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

