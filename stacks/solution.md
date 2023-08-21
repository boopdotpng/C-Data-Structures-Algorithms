## stacks

A stack is exactly what you imagine a stack to be. The items you stack last remain at the top of the list, and you can only remove items by removing the items above them first. (LIFO - last in first out)

### solution

If we have the string "((({})))":

All the open parenthesis get added to the stack.
stack: "{((("

Then we iterate through the rest of the string and check if all open parenthesis were closed. If the stack is not empty by the end of the string, then there was an extra parenthesis that wasn't closed, making the string valid.

If the first character is ), a closing parenthesis, the program will fail because the stack is empty (on line 25).
