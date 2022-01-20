# GraphQL Schema Design

> APIS should be easy to use and hard to misuse

A great API should make it easy to do the _right_ thing and make it really hard to do the _wrong_ thing

a developer should easily be able to determine _what_ they can achieve and _how_ to do it

an API should guide developers towards the best way to use th API while pushing them from bad practices

## design first

start to think of the design very early in the process

it is important to work with the teams/developers that are most familiar with the use cases you will expose with your API

public APIs are hard to change once they have been exposed

## client first

graphql is a client-centric API, this should affect how we design our APIs

its tempting to design in terms of backend resources and entities; however, it is best to design with the clients use cases in mind first

without thinking of the client' use cases first, we run the risk of creating generic APIs that make the client guess on how to use it or to have to read loads of documentation in order to achieve what they want, or in worst cases, to not be able to achieve their task at all

a great way to start is working with a _first client_ as early on in the process as possible

share your design early, have the client integrate with the API, and provide mock servers for your API along the way

this is especially important for internal and partner APIs

_client first does not mean always doing exactly what the client wants_

when clients run into problems - they may come to you with solutions

_gather information on the problem before implementing a solution_

take a step back - chances are there is a more elegant solution behind the problem

> You Aren't Going to Need It" (YAGNI) - Extreme Programming

the above rings true often times, especially for APIs

APIs should be complete (should provide enough features for clients to achieve use cases they are interested in) BUT

they _should not_ expose more than that

when you API over-exposes you run the risk of introducing performance and/or security issues 

make sure you are not designing schemas that are influenced by implementation details

the developers that integrate with your API will _probably_ not care what databse you are using, which programming language the server is built with, or what design issues you have on the backend

> your graphql schema is an entry point to functionality

occasionally, availability and performance will dictate the design; however, it is important to execute carefully with the client in mind

due to its typed nature, graphql tends to attract vendors and tools that offer to build a graphql API from a database or other data sources

remember, if you are building an API with a _client first_ mindset, this might not make sense
- this makes our schema coupled to implementation concerns
- the result is often generic in terms of tables and entities
- it does not keep our clients needs in mind
- it usually exposes way more that we should (YAGNI)

these tools can be more useful for quick prototypes or for if a graphql layer is needed on top of a database

another caution is generators that take an existing API definition (swagger/open API) and transliterate it into a graphql schema

an API should take into consideration the architecture and/or style it is built in

REST and graphql have different design concerns

a REST API should focus on resources and use HTTP method semantics to interact with them

a naive generator might generate graphql mutations like `postUser` or `putProduct` when in graphql style, these should look more like remote procedure calls like `createUser` and `updateProduct`

## best practices

### naming

> the names are the API talking back to you, so listen to them - joshua bloch

naming is very hard to get right but so important to think about

a good name immediately conveys information on what the API probably does before even reading documentation (or worse guessing)

naming things in a good way will often guilde us towards the right design by itself

_consistency is king_

clients have to take time to understand the API before using it, when things are consistent, discovering a new API will feel natural for users

```graphql
type Query {
    products(ids: [ID!]): [Product!]!
    findPosts(ids: [ID!]): [Post!]!
}

type Mutation {
    addProduct(input: AddProductInput): AddProductPayload
    createPost(input: CreatePostInput): CreatePostPayload
}
```

this schema is _not_ consistent when it comes to naming

there are two different naming schemes to get a list of objects: one prefixed with `find` and the other simply defined as `products`

this schema is hard to use for clients and is not predictable

if a client is already using `findPosts` and wants to integrate with `products` they will most likely assume they can use `findProducts`, that is, until they are met with a `field does not exist` error

you should be consistent with action verbs, you should also be consistent in how you name your domain concepts as well (e.g. do not name `BlogPost` in one place and `Post` in another unless they are different concepts)

a good example for the `Mutation` type is for adding a product using something like `addProduct`, but then adding a post using `createPost`

these prefix issues are common and the inconsistencies can add up and make your API hard to explore and use

API symmetry is important

make sure there are symmetric actions for a particular entity: a `publishPost` `mutation` makes it seems like there should be an `unpublishPost` mutation as well

following the [principle of least astonishment](https://en.wikipedia.org/wiki/Principle_of_least_astonishment) is generally a good idea:

> a component of a system should behave in a way that most users will expect it to behave

you can also consider to be overly specific when it comes to naming schema members

this avoids confusion for clients (on what _exactly_ an object or field represents)

it also helps graphql API providers as well

in large systems, it is common to have more than one name for similar concepts (think Event or User), these take up a lot of naming real estate which makes it hard to introduce more specific concepts down the line

try and keep generic names for later (they might come in handy later in the process)

an example of naming gone wrong (introduce a `User` object which acts as the viewer on the `query root`)

it includes information about the currently logged in user

```graphql
type Query {
    viewer: User!
}

type User {
    name: String!
    hasTwoFactorAuthentication: Boolean
    billing: Billing!
}
```

_a few months later someone discovers that this object is being used outsode of the scope of a logged in user_

```graphql
type Query {
    viewer: User!
    team(id: ID!): Team
}

type Team {
    members: [User!]!
}

type User {
    name: String!
    hasTwoFactorAuthentication: Boolean
    billing: Billing!
}
```

it is quickly realized that it makes no sense to exspose private information on team members (they are only meant to be seen by the viewer)

an error needs to be raised whenever these fields are accessed by a non-viewer user or make a new type

the first option is not practical and would not be great for clients (would be pretty brittle too)

the `User` type would have to go through a large deprecation and it should have been treated more as an `interface`

`Viewer` and `TeamMember` should have been types of their own

```graphql
type Query {
    user(id: ID!): User
    viewer: Viewer!
    team(id: ID!): Team
}

type Team {
    members: [User!]!
}

interface User {
    name: String!
}

type TeamMember implements User {
    name: String!
    isAdmin: Boolean!
}

type Viewer implements User {
    name: String!
    hasTwoFactorAuthentication: Boolean
    billing: Billing!
}
```

in this case, specific naming could have avoided a large deprecation and would have been much nicer for the clients to understand

naming things right can help guide towards the right design, while poor naming can steer an API towards bad design

### descriptions

graphql schema members can be documented using a _description_

this is how it would look using SDL

```graphql
"""
An order represents a `Checkout`
that was paid by a `Customer`
"""
type Order {
    items: [LineItem!]!
}
```

descriptions encode this information directly into the schema as opposed to being found in an external source (documentation)

if you are using a tool like graphiql, you can quickly read descriptions along with the schema

it is a good idea to describe all entities in your schema

a good description should clearly convey what a schema type _represents_, what mutations _do_, etc

descriptions can also occasionally reveal inadequate schema design

descriptions are icing on the cake - a client should not have to read descriptions to understand how your API can (and should) be used

an early warning sign to a potentially poor design is a description that explains an edge case, conditionals, or contexual behavior

using descriptions is great; however, do not make your users rely on them to understand your use cases

### using the schema

here, we have a schema with a `Product` type which contains a `price`, `priceInCents`, and `type` field

the `type` field represents the type of `Product` (`apparel`, `food`, `toys`)

```graphql
type Product {
    name: String!
    priceInCents: Int!
    type: String!
}
```

a potential problem here is clients may find it difficult determining _what can come out of this type_

what is the best way to handle the `type` field here?

in this case, assuming the `type` field has a set number of defined items, it would be favorable to "self-document" this schema and use an enum here

```graphql
enum ProductType {
    APPAREL
    FOOD
    TOYS
}

type Product {
    name: String!
    priceInCents: Int!
    type: ProductType!
}
```

a common design issue is including unstructured data as part of your schema (e.g. using a `String` type with a description that indicates how to parse the field or uses a scalar type like JSON)

```graphql
type Product {
    metaAttributes: JSON!
}

type User {
    # JSON encoded string with a list of user tags
    tags: String!
}
```

a more favorable approach (in most cases) is to use a stronger schema

```graphql
type ProductMetaAttribute {
    key: String!
    value: String!
}

type Product {
    metaAttributes: [ProductMetaAttribute!]!
}
```

these look familiar; however, the typed schema allows clients to handle this behavior in a much better way

it also allows for the schema to evolve over time (without the fear of breaking clients)

and finally it lets the server implementation know which fields are used on the `ProductMetaAttribute` type over time

if we use a custom encoding scalar or string, we lose what the typed graphql schema gives us

in some cases, custom scalars can help turn fields that are serialized strings into more useful types

```graphql
type Product {
    # Instead of a string description, we use a
    # custom scalar to indicate to clients
    # that they can treat the result of this field
    # as valid markdown
    description: Markdown
}

scalar Markdown
```

these can also be used as input types as well which results in more precise validation

```graphql
input CreateUser {
    email: EmailAddress
}

# A valid email address according to RFC5322
scalar EmailAddress
```

if you have the opportunity to use a stronger schema, you should consider doing so

this can mean using more complex object types as opposed to simple scalars, using enum types, and custom scalars when it makes sense to do so

### expressive schemas

graphql gives us the tools to build _expressive APIs_

> an API that allows client developers to easily understand how the API is meant to be used

easy to use, hard to misuse

as mentioned before, the graphql schema allows API providers to express how the API is meant to be used before they even look at documentation (or worse, implementing first)

a good way to build expressive schemas is to use nullability to your advantage

this graphql API provides a way to find a product

a product is referred by their global ID or by their name

you could make a `findProduct` field which (optionally) accepts _both_ and `id` and a `name` field

```graphql
type Query {
    # Find a query by id or by name
    # Passing none or both results
    # in a NotFound error
    findProduct(id: ID, name: String): Product
}
```

this would solve a client's needs; however, it is not that intuitive

e.g. what if a client provides no arguments or both arguments?

in both cases the server would more than likely return an error

you can solve this without having to explicitly explain any further

```graphql
type Query {
    productByID(id: ID!): Product
    productByName(name: String!): Product
}
```

you might be thinking, _why not combine these into one field?_

we should not be afraid of providing different ways to accomplish things in graphql

even if you provided five different ways to fetch a product, this would not add overhead to clients

the client will pick the fields that best suit their use case

now, with each field containing a single required field, our API is very hard to misuse

the schema will instruct clients on how to use the field

---

```graphql
type Payment {
    creditCardNumber: String
    creditCardExp: String
    giftCardCode: String
}
```

this `Payment` type represents a payment made by a customer

the three fields it contains can _potentially_ be filled in (depending on how the order was paid)

if a credit card was used, the `creditCardNumber` and `creditCardExp` fields should be filled in

if a gift card was used, the `gittCardCode` field should be filled in

we can improve this by using a strong schema to represent these rules

```graphql
type Payment {
    creditCardNumber: CreditCardNumber
    creditCardExpiration: CreditCardExpiration
    giftCardCode: String
}

# Represents a 16 digit credit card number
scalar CreditCardNumber

type CreditCardExpiration {
    isExpired: Boolean!
    month: Int!
    year: Int!
}
```

here we have addressed a few issues
- instead of a `String` type credit card expiration (makes it hard for clients to determine which format to provide), we have refactored this into a `CardExpirationDetails` type that has integer fields for both the month and the year. this is more usable than a string type and allows us to add fields later

we could add `isExpired: Boolean` field to help clients with this logic

we also use a custom scalar here for the credit card number which provide more semantics to clients since a credit card number has a particular format

we can still improve this though, notice a lot of fields are nullable, which will make it difficult for the client to know what the payment object will look like at runtime

you can improve this potential problem like so

```graphql
type Payment {
    creditCard: CreditCard
    giftCardCode: String
}

type CreditCard {
    number: CreditCardNumber!
    expiration: CreditCardExpiration!
}

# Represents a 16 digit credit card number
scalar CreditCardNumber

type CreditCardExpiration {
    isExpired: Boolean!
    month: Int!
    year: Int!
}
```

this is look much better - now we are using an object type that contains all the credit card related input fields

the schema expresses that if a credit card input is passed, it _must contain all the fields_ (as shown by the `number` and `expiration` fields)

previously, you would have had to handle that kind of conditional in the implementation as opposed to letting the schema handle that on its own

a common warning sign of potential refactors is taking a look at field prefixes - if multiple fields on a type share a prefix, chances are they could be under a new object type

this also lets us evolve the schema in a much better way, as opposed to adding more fields at the root (in our case the `Payment` object)

you can think of this principle in these terms

> make impossible states impossible

this is a common saying when it comes to strongly type languages

to apply this methodology, you can look at any given type in your schema and determine if its impossible to have inconsistent information from it

an example

```graphql
type Cart {
    paid: Boolean
    amountPaid: Money
    items: [CartItem!]!
}
```

in this case, it is possible for a client to get data that represents an impossible state (`paid`: `true` and `amountPaid`: `null`)

```json
{
  "data": {
    "cart": {
      "paid": true,
      "amountPaid": null,
      "item": [...]
    }
  }
}
```

another impossible state would be something like `paid`: `false` and `amountPaid`: `null`

```json
{
  "data": {
    "cart": {
      "paid": false,
      "amountPaid": 10000,
      "item": [...]
    }
  }
}
```

to fix this you can say that is a `payment` property is on a `cart`, it means that is has been paid for

by doing this you can use nullability to ensure both `paid` and `amountPaid` are present when that is the case

```graphql
type Cart {
    payment: Payment
    items: [CartItem!]!
}

type Payment {
    paid: Boolean!
    amountPaid: Money!
}
```

another example of an API that is tricky for a client to use would be something like a `product` field which takes an _optional_ sort argument

this makes sense because you would not want to force all clients to pass a value for sorting if they do not want to sort a particular way

```graphql
type Query {
    products(sort: SortOrder): [Product!]!
}
```

in this case, the schema does not give you much information about a default sort order; however, there is a way to fix this

graphql provides default values which are valuable when wanting to document the default case in your schema

```graphql
type Query {
    products(sort: SortOrder = DESC): [Product!]!
}
```

this way, you can avoid setting a default in your resolving logic and instead encode it right into your schema

wrapping up
- make sure your fields do one thing well and avoid clever or generic fields when possible
- avoid runtime logic if the schema can enforce it
- use complex object and input types to represent coupling between fields and arguments (avoid impossible states)
- use default values to indicate what the default behavior is when using optional inputs and arguments

### specific or generic

being specific in use cases you provide means you can optomize well for clients interested in that functionality

being too specific for some clients' means it is less customized for other clients

graphql's philosophy is letting clients consume exactly what they need - building a schema with that in mind and creating simple fields that answer clients' specific needs is generally a good idea

fields that are too generic are often times optimized for no one and are harder to reason about

fields should do one thing, and do it really well

an indication that a field might be doing more than one thing is a boolean argument

```graphql
type Query {
    posts(first: Int!, includeArchived: Boolean): [Post!]!
}
```

instead of making the `posts` field handle both listing archived posts and normal posts, you can separate these into two fields

```graphql
type Query {
    posts(first: Int!): [Post!]!
    archivedPosts(first: Int!): [Post!]!
}
```

by splitting these fields into two distinct use cases, your schema is more readable and easier to optimize, easier to cache, and easier to reason about for clients

a more common example of excessive use of generic fields are complex filters

```graphql
query {
    posts(where: [
        { attribute: DATE, gt: "2021-10-04" },
        { attribute: TITLE, include: "GraphQL" }
    ]) {
        id
        title
        date
    }
}
```

these filtering syntaxes are close to SQL and are very powerful; however, they should be avoided most of the time

- this is very generic which would force the team maintaining it to handle performance edge cases inside a single resolver
- it also does not focus on one use case in particular which would make it hard to discover and use on the client as well

if you are implementing a search or a filtering use case, filters can be very useful

try and be conscious of how much you need these generic fields

```graphql
type Query {
    filterPostsByTitle(
        includingTitle: String!,
        afterDate: DateTime
    ): [Post!]!
}
```

keep in mine: if you are building an API that should support more GQL-like filters for a search interface, going the generic route might make more sense

### anemic graphql

taken from the [anemic domain model](https://martinfowler.com/bliki/AnemicDomainModel.html), popularized by martin fowler

> designing schemas purely as dumb bags of data rather than designing them thinking of actions, use cases, or functionality

```graphql
type Discount {
    amount: Money!
}

type Product {
    price: Money!
    discounts: [Discount!]!
}
```

the `Product` type represents a product in an e-commerce store, the product has a `price` and a list of `discounts` that are applied

imagine the client wants to display the actual price a customer will have to pay

```js
const discountAmount = accounts.reduce((amount, discount) => {
    amount + discount.amount;
}, 0); 

const totalPrice = product.price - discountAmount;
```

the client will be able to display the price to customers, until the `Product` type evolves. what if taxes are added to products 

```graphql
type Product {
    price: Money!
    discounts: [Discount!]!
    taxes: Money!
}
```

now the client logic is not valid anymore, we can fix this by exposing what the client is interested in, a `totalPrice`

```graphql
type Product {
    price: Money!
    discounts: [Discount!]!
    taxes: Money!
    totalPrice: Money!
}
```

now the client gets exactly what they are interested in and can avoid writing and updating brittle code everytime something new is added

in this respect, we have designed our schema according to the domain and _not_ simply exposing data for clients to consume

the same principle can be applied to a `Mutation` as well

```graphql
type Mutation {
    updateCheckout(
        input: UpdateCheckoutInput
    ): UpdateCheckoutPayload
}

input UpdateCheckoutInput {
    email: Email
    address: Address
    items: [ItemInput!]
    creditCard: CreditCard
    billingAddress: Address
}
```

there are a few problems with this approach
- the mutation focuses too much on data and not behaviors (client would need to guess how to make a specific action) e.g. what if adding an item to our checkout actually reqiures updates to other attributes? our client would only learn of this via a runtime error, or by updating the wrong state (and forgetting to update an attribute)
- adding cognitive overload to clients due to them having to select a set of fields to update when wanting to make a certain action e.g. add to cart
- focusing too much on the shape of the internal data of checkout, not the behaviors of a checkout (not explicitly indicating that it is even possible to do these actions)
- having to make everything nullable which makes the schema less expressive

here is a fine-grained approach

```graphql
type Mutation {
    addItemToCheckout(
        input: AddItemToCheckoutInput
    ): AddItemToCheckoutPayload
}

input AddItemToCheckoutInput {
    checkoutID: ID!
    item: ItemInput!
}
```

some improvements:
- the schema is strongly typed and nothing is optional in this mutation. the client knows exactly what to provide to add an item to a checkout
- no more guessing, no more searching for which data to update, now we add an item. the client does not care about which data needs to be updated in these cases, just to add an item
- the potential for errors is greatly reduced, the resolver can return finer-grained errors
- it is no longer possible for the client to get into a weird state by using this mutation (it is now handled by a resolver)

a side effect of this design is the server-side implementation of these kinds of mutations is generally nicer to understand and write because it focuses on one thing, and the input and payload are predictive. it is also easier to see which events should be triggered by certain mutations

### relay specification

> a javascript client for graphql, a powerful abstraction for building client applications consuming graphql

it makes a few assumptions about the graphql api it interacts with:
- a method to re-fetch objects using a global identifier
- a `Connection` concept that helps paginate through datasets
- a specific structure for mutations
