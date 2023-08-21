## Tree Height
We're working with the same concept from last time, except the nodes aren't sorted by their value. 

## Tree Height 
1. the first line just returns 0 if the root node is null. In this case, there is no more tree to search. 
2. we use a recursive approach to calculate the height. Since the height of the tree is determined by the deepest node, we search both sides of the tree and add up the tallest side until we reach the end of the tree. 