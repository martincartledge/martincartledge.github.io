# Introduction to GraphQL

>

## endpoint based APIs
> revolves around HTTP
- still dominating the field when it comes to web APIs
- can be very well optimized for a use case
- easily cachable, discoveravle, and simple to use by clients

### one size fits all
> api that tries to answer too many use cases
- hard to manage due to how coupled they are to different clients (browser, mobile, IOT, etc)

**_Solution? Add more endpoints_**

let's say we want to build an API that will allow us to `fetch` a `products` resource

browser
`GET /products`

gaming console
`GET api/playstation/products`

mobile
`GET api/mobile`

**_the problem?_**

- hard to reason about for developers
- brittle to changes
- difficult to maintain and/or evolve

**_another approach: one endpoint per use case_**

- allow certain query parameters to be used

browser
`GET api/products?version=browser`

gaming console
`GET api/products?version=gaming`

mobile
`GET api/products?version=mobile`

**_or make it more generic via partials_**

`GET api/products?partial=full`

`GET api/products?partial=minimal`


**_allow clients to select what they want from the server_**

the JSON API spec calls these sparse fieldsets:

`GET api/products?include=author&fields[products]=name,price`

here is a query language in a query parameter (inspired by google drive's API)

`GET api/products?fields=name,photos(title, metadata/height)`

**_Most of the above have tradeoffs that include optimization and customization_**

## History

- in 2012 [netflix announced they had made a complete API redesign](https://netflixtechblog.com/embracing-the-differences-inside-the-netflix-api-redesign-15fd8b3dc49d?gi=fb328ca985bc)

> netflix has found substantial limitations in the traditional one size fits all REST API approach
> 
> while effective, the problem with the OSFA approach is that its emphasis is to make it convent for the API provider not for the API consumer

this solution involved a new conpcetual layer between the typical client and server layers where client-specific code if hosted on the server

in their approach
- the server takes care of gathering content (fetching data, calling services)
- the adapter layer formats the data in the client specific way

this allows the API to give control to client developers - letting them build their client adapters on the server

## GraphQL is born

- in september 2015 facebook officially announced the release of graphql

facebook's data problem:
- frustrated with the differences between the data we wanted to use in our apps and the serer queries they required
- did not think of data in terms of resource URLs, secondary keys, or join tables
- thought about data in terms of a graph of objects
- the models they used were [NSObjects](https://developer.apple.com/documentation/objectivec/nsobject) or [JSON](https://www.json.org/json-en.html)
- there was also a considerable amount of code to write on both the server to prepare the data and on the client to parse it

graphql is not:
- a replacement for HTTP endpoint based APIs
- the next REST
- a graph database
- a library
- about graph theory

graphql is:
- a solution for building experience based APIs
- redefining the boundary between the client and the server (while maintaining sanity on the server)

**_graphql is a specification for an API query language and a server engine capable of executing such queries_**


### hello world

this is a `query` that asks for the current user and their name

```graphql

query {
  me {
    name
  }
}
```

`me` and `name` are referred to as `fields`

a client sends requests like these to a graphql server (usually as a simple string)

the response looks something like this

```json
{
  "data": {
    "me": {
      "name": "martin"
    }
  }
}
```

notice that the response and the query are very similar shapes

if a graphql query is successful, the response always has a `data` key, under this key is the reponse that the client is expecting

graphql allows clients to define requirements down to single fields, this allows them to fetch exactly what they need

another example

```graphql
query {
    me {
        name
        friends(first: 2) {
            name
            age
        }
    }
}
```

above we are fetching more than just a `name`, we are also fetching the `name` and the `age` of the first `2` of my `friends` - this is how we are able to traverse complex relationships. you will also notice that fields can take arguments. think of fields like functions, they can take arguments and return a certain type

the response looks something like this

```json
{
    "data": {
      "me": {
        "name": "martin",
        "friends": [{
          "name": "nikita",
          "age": 3
        }, {
          "name": "willow",
          "age": 2
        }]
      }
    }
}
```

the `query` keyword is _not_ a normal field. it tells the graphql server that we want to query off the **query root** of the schema

## the type system

at the core of any graphql server is a powerful type system that helps to express API capabilities. the type system of a graphql engine is often referred to as the **_schema_**. a common way of representing a schema is through the graphql schema definition language (SDL)

the schema definition language is the canonical representation of a graphql schema and is well defined in the spec. no matter what manguage you are running a graohql api with, the SDL describes the final schema

example:

```graphql
type Shop {
    name: String!
    # where the shop is location, null if online only
    location: Location
    products: [Product!]!
}

type Location {
    address: String
}

type Product {
    name: String!
    price: Price!
}
```

### types and fields

the most basic and crucial primitive of a graphql schema is the **_object type_**. object types desribe one concept in your graphql API. what makes them whole is when they define fields. previously (above), we defined a `Shop` type that defined three fields: `name`, `location`, and `products`, the `fieldName: Type` syntax allows us to give a return type to our fields.

example: the `name` field on a `Shop` type returns a String. it is helpful to compare graphql fields to simple functions. fields are executed by a graphql server and return a value that maps correctly to its return type

the `String` type is _not_ user-defined, it is part of graphql's pre-defined scalar types. graphql's real power life in the fact fields, which can return object types of their own

example

```
location: Location
```

the `location` field on the `Shop` returns a type `Location` which is a type that the schema defines. to see what fields are available on a `Location` type we can look at the `Location` type definition

```graphql
type Location {
    address: String!
}
```

the `Location` type defines one `address` field which returns a `String`

now we will see that a field can return an object type of its own

a graphql server can execute queries like these because at each level in the query - it is able to validate the client requirements against the defined schema

```graphql
query {
    # !. the shop field returns a `Shop` type
    shop(id: 1) {
        # 2. field location on the `Shop` type
        # Returns a `Location` type
        location {
            # 3. field address exists on the `Location` type
            # Returns a String
            address
        }
    }
}
```

if you will notice above, we know that our `Shop` type has a `location` field and that our `Location` type has an `address` field; however, where is the `shop` field coming from?

### schema roots

a graphql schema must be defined using type and fields to describe its capabilities

a graphql schema must always define a `Query Root` (a type that defines the entry point to possibilities)

we usually call this type a `Query`

```graphql
type Query {
    shop(id: ID): Shop!
}
```

the `Query` type is implicitly queried whenever you make a graphql api request

```graphql
{
    shop(id: 1) {
        name
    }
}
```

this is valid because it implicitly asks for the `shop` field on the `Query Root` even though we did not query for that particular field that returned a `Query` type first

a `Query Root` has to be defined on a graphql schema, and there are two other types of roots that can be defined, a `Mutation` and a `Subscription` root

### arguments

```graphql
type Query {
    shop(id: ID!): Shop!
}
```

a graphql field can define arguments just like a function

the graphql server uses these arguments at the runtime resolution of the field

these fields are defined between parentheses after the field name and you can have as many of them as you like

```graphql
type Query {
    shop(owner: String!, name: String!, location: Location): Shop!
}
```

arguments, like fields, can define a type which can either be a `scalar` type or an `input` type

input types are similar to types, but they are declared in a different way, using the `input` keyword

```graphql
type Product {
    price(format: PriceFormat): Int!
}

input PriceFormat {
    displayCents: Boolean!
    currency: String!
}
```

### variables

graphql queries can also define variables that can be used within a query

this allows clients to send variables along with a query and have the graphql server execute it instead of including it directly in the query string itself

```graphql
query FetchProduct($id: ID!, $format: PriceFormat!) {
    product(id: $id) {
        price(format: $format) {
            name
        }
    }
}
```

we gave this query an **operation name** (`FetchProduct`)

a client would send this query with variables like this

```json
{
  "id": "abc",
  "format": {
    "displayCents": true,
    "currency": "USD"
  }
}
```

### aliases

the server dictates the canonical name of fields but if the client wants to receive fields under another name, they can use _aliases_

```graphql
query {
    abcProduct: product(id: "abc") {
        name
        price
    }
}
```

above, the client requests the `product` field but defines an `abcProduct` alias

when the client executes the query, it will get back the field as if it was named `abcProduct`

```json
{
  "data": {
    "abcProduct": {
      "name": "shirt",
      "price": 25
    }
  }
}
```

this is useful when requesting the same field multiples times with different arguments

### mutations

> allows writing and modifying data

the entry point to the mutations of a schema is under the `Mutation` root

to access the `mutation` root in a graphql query, use the `mutation` keyword at the top level of a query

```graphql
mutation {
    addProduct(name: String!, price: Price!) {
        product {
            id
        }
    }
}
```

we define the `addProduct` mutation in a similiar way that we define fields on the query root

```graphql
type Mutation {
    addProduct(name: String!, price: Price!): AddProductPayload 
}

type AddProductPayload {
    product: Product!
}
```

two things make `mutation` fields different from `query` fields
- top-level fields under the mutation root are allowed to have side effects and make modifications
- top-level mutation fields must be executed serially by the server, other fields could be executed in parallel

similarly they
- take arguments
- have a return type for clients to query after a mutation is made

### enums

> allow a schema to clearly define a set of values that may be returned, for fields, or passed (arguments)

they come in handy when defining an API that is easy to use by clients

```graphql
type Shop {
    # the type of products the shop specializes in
    type: ShopType!
}

enum ShopType {
    APPAREL
    FOOD
    ELECTRONICS
}
```
