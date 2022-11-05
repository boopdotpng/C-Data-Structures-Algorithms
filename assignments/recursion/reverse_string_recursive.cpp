// Homework
/*
 Write a short recursive C++ function that determines if a string s is a
palindrome, that is, it is equal to its reverse. For example, "racecar"
and "gohangasalamiimalasagnahog" are palindromes.

Note: Your implementation has to be recursive. Zero points for non-recursive code even if it's correct.
*/
#include <iostream>
#include <string>

bool isPalinHelper(std::string& s, int begin, int end) {
	if (s[begin] != s[end]){
		return false;
	}

	if ( begin < end + 1){
		return isPalinHelper(s, begin+1, end-1);
	}
}

bool isPalin(std::string& s) {
	return isPalinHelper(s, 0, s.size()-1);
}

int main() {
	std::string s1{"racecar"}; // Palindrome
	if (isPalin(s1)) std::cout << s1 << " is a palindrome" << std::endl;
	else std::cout << s1 << " is not a palindrome" << std:: endl;
	std::string s2{"racecars"}; // Not a palindrome
	if (isPalin(s2)) std::cout << s2 << " is a palindrome" << std::endl;
	else std::cout << s2 << " is not a palindrome" << std:: endl;
	std::string s3{"gohangasalamiimalasagnahog"};
	if (isPalin(s3)) std::cout << s3 << " is a palindrome" << std::endl;
	else std::cout << s3 << " is not a palindrome" << std:: endl;

}
