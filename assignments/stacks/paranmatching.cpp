/*
Write a function that returns if a string of paranthesis are matched.
You are required to use the STL stack datastructure in your code for O(n) time complexity.
See 5.17 in the book for problem description and a stack based algorithm.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
	stack<char> array;
	char current = (char) 0;

	for(auto &ch : expr){
		if (ch == '(' || ch == '[' || ch == '{'){
			array.push(ch);
		}

		else {
			if (array.empty()){
				return false;
			}
			current = array.top();
			array.pop();

			if(current == '('){
				if (ch != ')'){
					return false;
				}
			}
			if(current == '{'){
				if (ch != '}'){
					return false;
				}
			}
			if(current == '['){
				if (ch != ']'){
					return false;
				}
			}
		}
	}
	if(!(array.empty())){
			return false;
		}
		return true;

}

// Test - DO NOT MODIFY
int main()
{
	vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"};

	for (auto expr : parans)
	{
		if (areParanthesisBalanced(expr))
			cout << "Balanced" << endl;
		else
			cout << "Not Balanced" << endl;
	}
	return 0;
}
