## Binary Search Tree

A binary search tree (BST) is a data structure where each node has a value and two child nodes: a left child with smaller values and a right child with larger values. The main property is that for any given node, all nodes in its left subtree have values less than the node's value, and all nodes in its right subtree have values greater.

### Searching
We can search values in the tree using the above property. If the value we're searching for is less than the root node value, then we search the left side of the tree. If it's greater, we search the right side of the tree. If we keep doing this, eventually we come across the key we're looking for.  