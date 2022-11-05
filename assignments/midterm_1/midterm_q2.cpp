/*
For the linked list implementation given below,
(1) implement a method that returns true if an input value exists in the list, false otherwise.
(2) implement a method that returns the maximum value in the list
Assume at least one node in list

Note: DO NOT modify the linked list or the test
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr){};
	~LinkedList();
	void pushFront(int val);
	void popFront();
	int maxVal();			 // Returns maximum value in list
	bool isPresent(int val); // Returns true if val is present in list
private:
	ListNode *head;
};

void LinkedList::pushFront(int val)
{
	ListNode *n = new ListNode(val, head);
	head = n;
}

void LinkedList::popFront()
{
	if (head == nullptr)
		return;
	ListNode *n = head;
	head = head->next;
	delete n;
}

bool LinkedList::isPresent(int val)
{
	ListNode *iter = head; // create iteration varariable starting at head of linked list

	while (iter != nullptr)
	{ // until there are no more nodes in the linked list
		if (iter->val == val)
			return true;   // check if value of current node is search_val
		iter = iter->next; // move iterator to next node
	}

	return false; // if value wasn't found return false
}

int LinkedList::maxVal()
{
	int max_result = 0; // store maximum value to return | 0 is minimum value
	ListNode *iter = head; // create iterator

	while(iter != nullptr){ // until list is empty
		if (max_result < iter->val) max_result = iter->val; // if the current value is greater than current max, make it the max
		iter = iter->next; //increment iterator
	}

	return max_result; // return max

}

LinkedList::~LinkedList()
{
	while (head != nullptr)
		popFront();
}

// Test
int main()
{
	LinkedList lst;
	lst.pushFront(42);
	lst.pushFront(88);
	lst.pushFront(31);
	lst.pushFront(21);
	lst.pushFront(6);

	if (lst.isPresent(21))
		std::cout << "21 in list" << std::endl;
	else
		std::cout << "21 not in list" << std::endl;

	if (lst.isPresent(8))
		std::cout << "8 in list" << std::endl;
	else
		std::cout << "8 not in list" << std::endl;

	std::cout << "Maximum list value: " << lst.maxVal() << std::endl;
}
