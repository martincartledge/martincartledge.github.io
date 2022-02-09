# GraphQL Schema Design Pt 3

### sharing types

as your schema grows, it is appealing to reuse types across different fields and use cases

in some cases this makes sense; however, trying to share too much rarely works out well

an example of how this can turn troublesome is related to the connection pattern (as discussed in graphql schema design pt 2)

here, we have a schema where an `Organization` has a paginated connection of `users`

```graphql
type UserConnection {
    edges: [UserEdge!]!
    pageInfo: PageInfo!
}

type UserEdge {
    node: User
}

type User {
    login: String!
}

type Organization {
    users: UserConnection!
}
```

and now lets say that the concept of teams and team members' comes into play

a mistake would be to reuse the same `UserConnection` for the `members` field

after all, team members and organization users are all _users_

```graphql
type UserConnection {
    edges: [UserEdge!]!
    pageInfo: PageInfo!
}

type UserEdge {
    node: User
}

type User {
    login: String!
}

type Organization {
    users: UserConnection!
    teams: [Team]
}

type Team {
    members: UserConnection!
}
```

an issue with reusing types like this is the likelihood of these types diverging over time is high

moving forward it can get easy to get stuck if (or when) new features are introduced

```graphql
type UserEdge {
    isTeamLeader: Boolean
    isOrganizationAdmin: Boolean
}
```

the `UserEdge` (where information should be related to a user within a team) is shared across organization users and team users; therefore, you can no longer add anything specific to one of them

imagine if you had a `TeamMemberConnection` and a `OrganizationUserConnection`

you would be free to encode any data on the edges and connections, which could very likely turn out problematic

another common misstep is to share inputs

in a lot of cases, `create` and `update` mutations look similar; the `update` mutation will take the `id` of the resource to update and most of the attributes will stay the same

```graphql
input ProductInput {
    name: String
    price: MoneyInput
}

type Mutation {
    createProduct(input: ProductInput): CreateProductPayload
    updateProduct(id: ID!, input: ProductInput): UpdateProductPayload
}
```

this can be useful to allow generated clients to reuse forms and logic; however, it can lead to similar problems as we discussed above

usually, a create input would have more non-null fields (you can not create a product without a `name` for example)

because it is reused in the update mutation, that input field has to be made nullable (the creation mutation would have to handle validation at runtime instead of letting the schema handle it)

generally, you should avoid trying too hard to share types unless it is very obvious it _can_ be shared

if you have doubts, keep in mind that the downsides usually outweigh the benefits

### global identification

a concept that has gained a lot of popularity amongst graphql APIs is _global identification_ of objects

the idea behind this is that a graphql client should be able to fetch any _node_ in the graph given a unique identifier

practically speaking, this translates in a graphql server exposing a global `node (id: ID!): Node` field that lets clients fetch any node through that single field

the `node` field returns a `Node` interface type

```graphql
interface Node {
    id: ID!
}

type User implements Node {
    id: ID!
    name: String!
}
```

the `Node` interface is essentially an object with a globally unique ID and can be fetched using the `node(id: ID!)` and `nodes(ids: [ID!]!)` fields

the purpose of global identification is client-side caching

do you absolutely need global identification? you might not if:

- you do not expect relay clients to use your API
- you do not see a need to fetch objects using a single global identifier

if you are using apollo, apollo can use a combination of the type name and a simpler ID to build a global identifier for you

having a globally unique ID for a certain _node_ or _object_ can be a useful principle, 

global identifiers are similar to uniform resource identifiers (URIs) which are used to identify REST resources

users should not try to build or hack their IDs - but instead use the IDs they get from the API directly

to ensure this happens, you can use _opaque identifiers_

```json
{
  "data": {
    "node": {
      "id": "RmFjdGlvbjoy"
    }
  }
}
```

the most common way to make IDs opaque is to `Base64` them, the idea is not to hide how the ID is built (it is easy for the client to see it is `Base64`), this just serves as a reminder to the client that the string is meant to be opaque

opaque IDs are great because they enable you to change the underlying ID generation knowing that clients have (hopefully) not built logic coupled to how the ID is constructed

sometimes this does not lead to the best developer experience

it can be difficult to know what kind of node ID you have when you are building a client application

when you build these IDs, try and include as much information about them as possible to help fetch this node globally

a basic example might look something like this `type_name:databse_id`, you should not default to this though

in some cases, nodes cannot be fetched without routing information (especially in more distributed architectures)

make sure you include any information that would make it _easier_ to _route_ to this node

example: _products_ might be shared or distributed by _shops_ (meaning our IDs might need the `shop` id in there `shop_id: type_name:id`)

#### in summary

- you do not always need global identification (especially if not planning on supporting relay)
- like connections, they can be a good pattern (even outside the context of relay)
- opaque IDs are recommended
- ensure your global ID contains enough context to globally route to a node (especially in a distributed architecture)

### nullability

> a graphql concept that allows you to define whether a field can return `null` or not when queried

a non-null field (a field that cannot return `null` at runtime is defined by using the `!` syntax after its type)

by default all fields are nullable

```graphql
type Product {
    # this field is non-null
    name: String!
    
    # price returns null when the product is free (default)
    price: Money
    
    # the tags field itself cannot be null
    # if it does return a list, then every
    # item within this list is non-null
    tags: [Tag!]
}
```

if a field returns `null` when queried (even if it was marked as non-null in the schema) this will cause a graphql server to error

since the field cannot be `null` graphql will go up to the parent of the field until it finds a nullable one

if all fields were all non-nullable the entire query returns `null` with an error

below, the `topProduct` field is marked as non-null and the `shop` field is marked as nullable

```graphql
query {
    shop(id: 1) {
        name
        topProduct {
            name
            price
            tags
        }
    }
}
```

imagine `name` was to return `null` even though you marked it as non-null, because `topProduct` cannot be null either the result would look like this

```json
{
  "data": {
    "shop": null
  }
}
```

`shop` was nullable; therefore, graphql wiped the response even though `name` was the only field that was returning `null`

this is a good reminder that nullability can either be really powerful or a terrible mistake (depending on how it is applied)

non-nullability can be great:
- it helps to build more expressive and predictable schemas
- it lets the clients avoid overly defensive code and conditionals

non-nullability can be tricky as well:
- non-null fields are arguments are hard to evolve, going from non-null to null is a breaking change (but the opposite is not)
- it is hard to predict what can be null and what cannot, especially in distributed environments. as your architecture evolves, anything including timeouts, transient errors, or rate limits could return null for certain fields

a few guidelines for nullability:
- for arguments, non-null is almost always better to allow for a more predictable and easy to understand API (if you are adding an argument, nullable is the best choice to avoid breaking existing clients)
- fields that return object types that are backed by database associations, network calls, or anything else that could potentially fail one day should be nullable
- simple scalars on an object that you know will be loaded on the parent at execution time are generally safe to make non-null
- _rarely_ for object types you are strongly confident will never be `null` and that will still allow for partial responses at the parent level (this can be hard to predict, especially when the type ends up being reused in other contexts)

### abstract types

abstract types can be of great help when designing a schema and can be truly helpful to decouple your interface from the underlying persistence layer

pretend this type was generated from your database model

```graphql
type SocialMediaFeedCard {
    id: ID!
    title: String!
    birthdayDate: DateTime
    eventDate: DateTime
    postContent: String
}
```

this represents a social media post; however, there are some issues with this type

sometimes a post is about a birthday, sometimes it is about an event,and sometimes it is simply a text post

with the example above, you are not using the schema to the full potential and now there are opportunities to be in illegal states

a birthday card should not have content, simply a `birthdayDate`

an event should be not include a `birthdayDate`, but as it stands now, the schema implies that this is possible

to address this, you can design your schema with the help of abstract types, in this case by using an `Interface` type

```graphql
interface SocialMediaFeedCard {
    id: ID!
    title: String!
}

type BirthdayFeedCard implements SocialMediaFeedCard {
    id: ID!
    title: String!
    date: DateTime!
}

type EventFeedCard implements SocialMediaFeedCard {
    id: ID!
    title: String!
    date: DateTime!
}

type ContentFeedCard implements SocialMediaFeedCard {
    id: ID!
    title: String!
    content: String!
}
```

this schema is much clearer for clients to understand, and we can now understand the different types that might be coming our way

you also do not need nullable fields anymore and all potential types do not allow for any illegal states
