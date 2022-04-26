# GraphQL Schema Design Pt 4
## mutations

### input and payload types

mutations are simple fields, they can take arguments and return a certain type

a common practice is to return a *payload type*, which is used for the result of a mutation

```graphql
# example payload type for a createCheckout mutation
type CreateProductPayload {
    product: Product
}
```