/* Count inversions - homework
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is maximum. Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

What would the complexity of a brute force approach be? Code an O(nlog(n)) algorithm to count the number of inversions. Hint - piggy back on the merging step of the mergesort algorithm.

The following two videos from Prof. Roughgarden may help you understand the problem better. Watch the first video and then try to figure out a good algorithm before you watch the second video -

https://www.youtube.com/watch?v=4IvYaOY8Pxw
https://www.youtube.com/watch?v=I6ygiW8xN7Y


*/ 
#include <iostream>
#include <vector>
#include <algorithm> // For copy



int mergeInv(std::vector<int>& nums, std::vector<int>& left, std::vector<int>& right) {
// Your code here


}

int countInv(std::vector<int>& nums) {
	// Base case - one element, nothing to sort

	if (nums.size() > 1) {
		int mid = nums.size()/2;
		std::vector<int> left(mid);
		std::vector<int> right(nums.size()-mid);
		std::copy(nums.begin(), nums.begin() + mid, left.begin());
		std::copy(nums.begin() + mid, nums.end(), right.begin());
		int numInvLeft = countInv(left);
		int numInvRight = countInv(right);
		int numInvMerge = mergeInv(nums, left, right);
		return numInvLeft + numInvRight + numInvMerge;
		
	}
	return 0;

}

int main()
{
    int n;
    std::vector<int> numvec{4, 5, 6, 1, 2, 3};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 9
    
    numvec = {1, 2, 3, 4, 5, 6};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 0
    
    numvec = {6, 5, 4, 3, 2, 1};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;  // Should be 15
    
    numvec = {0, 0, 0, 0, 0, 0};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;;  // Should be 0
}





