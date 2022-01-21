# GraphQL Schema Design Pt 2

## lists and pagination

most schemas will expose list type fields

```graphql
type Product {
    variants: [ProductVariant!]!
}
```

this could turn out to be less than ideal down the line

the `variants` field provides no control to th e client regarding how many items that will be returned, _all_ will be returned every time

this could potentially lead to fields having to be removed due to performance issues on the backend or clients that need to do their own filtering (wasting lots of data if they only want to display the first few items in the UI)

for the reason above, _pagination_ is almost always an essential component of a good API

the idea behind it is to break up large datasets into "pages" (letting the client get parts of the data instead of sending too much data across the wire)

pagination provides a great experience for clients and servers
- on the server-side pagination helps you load a certain part of a dataset instead of making queries for too much data (which can lead to extremely slow request times and timeouts)
- on the client-side this encourages a better user experience and performance (you would not want your users to have to scroll through a thousand items)

in graphql pagination is done in many ways, two common approaches are below

### offset pagination

most widely used technique

> clients are in control of how many items they are interested in receiving (an `offset` or `page` parameter helps move across a paginated list)

in a http api it might look like: 
`GET /products?limit=250&page=3`

in graphql it might look like:
```graphql
type Query {
    products(limit: Int!, page: Int!): [Product!]!
}
```

this pagination works well for a few reasons
- easiest to implement on the backend
- offers a lot of flexibility to clients (skip to a page, track their location as they paginate through a list)

however, as api providers grow, this might cause some issues:
_database performance_

try to imagine the database query would look like to fufill the `products` field

``````
SELECT * FROM products
WHERE user_id = %user_id
LIMIT 250 OFFSET 500;
`````` 

queries like this do not scale well with large datasets

when the `offset` parameter grows the database implementation needs to read all rows up until this number to get that offset, but it has no need for the rows it just read and will return `offset` + `limit` to the user

_inconsistent results_

any changes to the list while a client is paginating can modify the items returned to the page requested by the client

due to these reasons, a lot of api providers move to another style of pagination, _cursor-based_

### cursor pagination

> a cursor is a stable identifier that points to an item on a list

clients can use the cursor to instruct the api to give them a number of results before or after the cursor

```graphql
type Query {
    products(limit: Int!, after: String): [Product!]!
}
```

the concept of _pages_ does not exist in cursor pagination

the client only knows about the _next_ or _previous_ few items

the client would not know what _page_ they are on, and they can not skip to a page

the performance downsides that came with offset pagination are not eliminated because you can use the cursor to fetch results

``````
SELECT * FROM products
WHERE user_id = %user_id
AND id > 15
ORDER BY id DESC
LIMIT 10
``````

in cursor pagination the server always provides what the _next_ cursor is in some way or another

this allows the clients to request the next few elements

```json
{
  "data": {
    "products": {
      "next": "def456",
      "items": [{}, {}, {}]
    }
  }
}
```

the client would take the next cursor and use it to fetch the next 10 items

```graphql
query {
    products(first: 10, after: "def456") {
        next
        items {
            name
            price
        }
    }
}
```

unless you need the ability to skip ahead to different pages, cursor pagination is a good choice for graphql apis

most graphql apis today use cursor-based pagination

### relay connections

> relay calls paginated lists connections

query for a `connection` field

```graphql
query {
    products(first: 10, after: "abc123") {
        edges {
            cursor
            node {
                name
            }
        }
        pageInfo {
            endCursor
            hasNextPage
            hasPreviousPage
        }
    }
}
```

connections return a `connection` type, this type exposes two fields: `edges` and `pageInfo`

the _edges_ field contains the data you requested

the `pageInfo` field contains the metadata about the pagination itself

the `edges` field does not return the items immediately but instead returns an edge type with extra connection metadata for that item

this is how you determine the cursor of each item in the list

the `node` field on the list of edges contains the data you are looking for, in this case, `products`

the result of the query above will look like this

```json
{
  "data": {
    "products": {
      "edges": [
        {
          "cursor": "Y3Vyc29yOnYyOpHOAA28Nw==",
          "node": {
            "name": "Production Ready GraphQL Book"
          }
        }
      ],
      "pageInfo": {
        "endCursor": "Y3Vyc29yOnYyOpHOAA28Nw==",
        "hasNextPage": true,
        "hasPreviousPage": false
      }
    }
  }
}
```

the client would take the `endCursor` in the `pageInfo` metadata and use it to get the next items after what you have already fetched

the schema would look like this

```graphql
type ProductConnection {
    edges: [ProductEdge]
    pageInfo: PageInfo!
}

type ProductEdge {
    cursor: String!
    node: Product!
}

type PageInfo {
    endCursor: String
    hasNextPage: Boolean!
    hasPreviousPage: Boolean!
    startCursor: String
}

type Product {
    name: String!
}
```

the connection pattern comes with certain overhead for clients but it is very useful when designing more complex scenarios

the github api uses connection edges to encode data about the _relationship_ rather than the item itself

in this example the `Team.members` connection and edges have the role of a user in that team of the `edge` type rather than the `User` type itself

```graphql
type TeamMemberEdge {
    cursor: String!
    node: User!
    role: TeamMemberRole!
}
```

the connection pattern does require cursor-based pagination

even if you are using offset based pagination, `edge` types are still a good idea

using the underlying type directly in a list type is rarely what you want, some fields are specific to a type's membership in a collection

### custom connection fields
