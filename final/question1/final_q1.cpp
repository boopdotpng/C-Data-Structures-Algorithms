/*
 * Implement the min() and nodeCount() method for the BST shown below.
 * min() returns the min key in the BST
 * nodeCount() returns the count of the nodes in the BST
 * Your implementation can either be iterative or recursive.
 * Do NOT modify the test.
 * Do NOT add any additional STLs
 * You can add private data, and methods to the BST if needed
 * Useful link for std::pair https://cplusplus.com/reference/utility/pair/pair/
 * Note: Your code should work for any arbitrary BST, not just the one given in the test
 */

#include <iostream>
#include <string>
#include <utility>

class Node
{
private:
   int key;
   std::string val;
   Node *left;
   Node *right;
   friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
   BinarySearchTree() : root{nullptr} {}
   void insert(int key, std::string val); // Recursive
   std::pair<int, std::string> min();     // Returns the min key, and associated value
   int nodeCount();                       // Returns the number of nodes
private:
   Node *root;
   void insertHelper(Node *parent, Node *new_node);
   int nodeCountHelper(Node* root);
};

void BinarySearchTree::insert(int key, std::string val)
{
   Node *new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr)
   {
      root = new_node;
   }
   else
   {
      insertHelper(root, new_node);
   }
}

void BinarySearchTree::insertHelper(Node *parent, Node *new_node)
{
   if (new_node->key < parent->key)
   {
      if (parent->left == nullptr)
      {
         parent->left = new_node;
      }
      else
      {
         insertHelper(parent->left, new_node);
      }
   }
   else if (new_node->key > parent->key)
   {
      if (parent->right == nullptr)
      {
         parent->right = new_node;
      }
      else
      {
         insertHelper(parent->right, new_node);
      }
   }
}

std::pair<int, std::string> BinarySearchTree::min()
{
   std::pair<int, std::string> minPair;
   Node *current = root;
   while (current->left != nullptr)
   {
      current = current->left;
   }
   minPair.first = current->key;
   minPair.second = current->val;

   return minPair;
}

// Hint: Traverse the tree and count the nodes
int BinarySearchTree::nodeCount()
{
   int nodecount = nodeCountHelper(root);

   return nodecount;
}

int BinarySearchTree::nodeCountHelper(Node* root)
{

   if (root == nullptr){
      return 0;
   }
   else{
     return 1 + nodeCountHelper(root->left) + nodeCountHelper(root->right);
   }
}

// Test
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

   auto minPair = t.min();
   std::cout << "Min key and value: " << minPair.first << " " << minPair.second << std::endl;
   std::cout << "Number of nodes: " << t.nodeCount() << std::endl;

   return 0;
}
