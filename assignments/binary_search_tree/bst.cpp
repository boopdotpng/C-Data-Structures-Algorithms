/*
 * Implement the find() method for the BST which returns the value if the key is present, empty string otherwise.
 * Your implemntation can be either iterative or recursive.
*/

#include <iostream>
#include <string>

class Node
{
private:
   int key;
   std::string val;
   Node* left;
   Node* right;
   friend class BinarySearchTree;
};


class BinarySearchTree
{
public:
       BinarySearchTree(): root{nullptr} {}
       void insert(int key, std::string val); // Recursive
       void printInOrder() const; // Prints keys in-order. Recursive
	   std::string find(int key) const; //Returns value if node is present, else return empty string. Iterative
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
        void printInOrderHelper(Node *n) const; //Helper for recursive implemenation of printInroder()
};


void BinarySearchTree::insert(int key, std::string val)
{
   Node* new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) {
      root = new_node;
   } else {
      insertHelper(root, new_node);
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node)
{
   if (new_node->key < parent->key) {
      if (parent->left == nullptr) {
         parent->left = new_node;
      }
      else {
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {
      if (parent->right == nullptr) {
         parent->right = new_node;
      }
      else {
         insertHelper(parent->right, new_node);
      }
   }
}

std::string BinarySearchTree::find(int key) const {

   Node* search = root;

   while (search != nullptr) // until you search through the whole tree
   {
      if (key < search->key)
      {
         search = search->left; // lesser values are in the left subtree
      }
      else if (key > search->key)
      {
         search = search->right; // greater values are in the right subtree
      }
      else
      {
         return search->val; // value found
      }
   }
   return ""; // if while loop finishes without finding the value, return empty string
   }


void BinarySearchTree::printInOrder() const {
	if (root == nullptr) {
		std::cout << std::endl;
	}
	printInOrderHelper(root);
	std::cout << std::endl;

}

void BinarySearchTree::printInOrderHelper(Node* n) const {
	if (n == nullptr) {
		return;
	}
	printInOrderHelper(n->left);
	std::cout << n->key << " ";
	printInOrderHelper(n->right);
}

int main()
{
   BinarySearchTree t;
   t.insert(5, "Boron");
   t.insert(3, "Lithium");
   t.insert(7, "Nitrogen");
   t.insert(2, "Helium");
   t.insert(4, "Berylium");
   t.insert(6, "Carbon");
   t.insert(8, "Oxygen");
   t.printInOrder(); // Prints the keys in order (will appear sorted)
   int ele = 8;
   std::string val = t.find(ele);
   if (val == "" ) {
	   std::cout << ele << " does not exist in tree" << std::endl;
   } else {
	   std::cout << ele << " : " << val << std::endl;
   }
   ele = 0;
   val = t.find(ele);
   if (val == "" ) {
	   std::cout << ele << " does not exist in tree" << std::endl;
   } else {
	   std::cout << ele << " : " << val << std::endl;
   }
    return 0;
}

