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

and now lets say that the concept of teams and team members comes into play

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
