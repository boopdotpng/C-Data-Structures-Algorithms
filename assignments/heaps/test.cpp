/* Given: A sequence of numbers x1, x2, ..., xn input one-by-one, find the median as the numbers arrive.
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
 * Your algorithms should be O(nlogn) where n is the number of elements seen thus far.
 * Hint: Solution involves using a max and min heap (STL priority queues) discussed in class.
 */

#include <iostream>
#include <queue>
#include <vector>

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

// Helper function to print queue for debugging

template <typename T>
void printQueue(T &q)
{
    T q_copy(q);
    while (!q_copy.empty())
    {
        std::cout << q_copy.top() << " ";
        q_copy.pop();
    }
    std::cout << std::endl;
}

std::vector<double> findMedian(std::vector<int> &data)
{
    std::priority_queue<int> max_heap;                                      // STL Max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // STL Min-heap

    std::vector<double> res;

    for (int i = 0; i < data.size(); i++)
    {
        if (max_heap.empty() || data[i] < max_heap.top())
        {
            max_heap.push(data[i]);
        }
        else
        {
            min_heap.push(data[i]);
        }

        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if (max_heap.size() == min_heap.size())
        {
            res.push_back((max_heap.top() + min_heap.top()) / 2.0);
        }
        else if (max_heap.size() > min_heap.size())
        {
            res.push_back(max_heap.top());
        }
        else
        {
            res.push_back(min_heap.top());
        }
    }

    return res;
}

int main()
{
    std::vector<int> data_stream = {5, 42, 29, 85, 95, 99, 2, 15};
    // i-th element of median_stream is median of first i elements of input
    std::vector<double> median_stream = findMedian(data_stream);
    for (auto ele : median_stream)
    {
        std::cout << ele << " "; // Answer should be -5 23.5 29 35.5 42 63.5 42 35.5
    }
    std::cout << std::endl;
}
