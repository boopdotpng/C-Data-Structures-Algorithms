/*
 Given an array of positive numbers, find the maximum sum of a subsequence such that no two numbers in the sequence are adjacent in the array.
 Your algorithm should be O(n) where n is the number of elements in the array.
 Assume at least one element is present in the array
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::vector;

int maxSum(vector<int> &nums)
{
	int n = nums.size();

	if (n == 1)
		return nums[0]; // handles base cases

	int memo[n]; // dp array

	memo[0] = nums[0];
	memo[1] = max(nums[0],nums[1]); // take largest element as starting point

	for (int i = 2; i < n; i++) // iterate starting at 2
	{
		memo[i] = max(memo[i-1],memo[i-2] + nums[i] ); // store max of inclusive and exclusive sum

		memo[i] = max(memo[i], nums[i]); // if theres an element higher than current sum, take that
	}

	return memo[n-1]; // return maximum sum
}

int main()
{
	vector<int> nums;
	// Test 1
	nums = {75, 105, 120, 75, 90, 135};
	cout << maxSum(nums) << endl; // 330
	// Test 2
	nums = {5, 5, 10, 100, 10, 5};
	cout << maxSum(nums) << endl; // 110
	// Test 3
	nums = {3, 2, 7, 10};
	cout << maxSum(nums) << endl; // 13
	// Test 4
	nums = {3, 2, 5, 10, 7};
	cout << maxSum(nums) << endl; // 15
}
