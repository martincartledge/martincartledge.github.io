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
