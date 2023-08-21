## Vectors

This is c++'s dynamic array type.

### Solution

1. we check if the vectors are of different sizes. If so, the calculation cannot continue.
2. Then we use .at(i) which returns the value of the element at index i to compute the product of both arrays and use .push_back() to append the product to a new array.
