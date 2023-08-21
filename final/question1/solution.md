### the min function

Since the binary search tree will always have its least valued keys on the left side of the tree, we just need to keep traveling down that side until we reach a null pointer (meaning there is no more tree). Then we have our least key->value pair.

### the nodecount function

We use a helper function to solve this problem recursively. This helper function just traverses both sides of the tree, adding 1 for the root node and 1 for each node that it encounters on both sides, until it reaches a null pointer.
