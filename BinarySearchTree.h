//A simple binary search tree
/*
    INSERT WORKs
    FIND
    DELETE
    OSTREAM INORDER PRINT METHOD
    DESTRUCTOR FOR TREE AND NODE
*/
#include <iostream>
using namespace std;

template <class X> class BST
{
private:

  struct Node
  {
    X* data;
    Node* left;
    Node* right;
  };

  Node* root = new Node(); //Thia took me an embarassing amount of time to remember to do. . .

  Node* Private_Add(Node* node, X key)
  {
    if (node->data != nullptr && *(node->data) < key)
    {
      return Private_Add(node->left, key);
    }
    else if (node->data != nullptr && *(node->data) > key)
    {
      return Private_Add(node->right, key);
    }
    else
    {
      Node* new_node = new Node();
      new_node->data = new X(key);
      return new_node;
    }
  }
public:
  void Add(X key) //all of these public methods are basically just wrapping the struct for ease of use
  {
    Private_Add(root, key);
  }



  BST()
  {
    root->data = nullptr;
  }

  BST(X data)
  {
    root->data = new X(data);
  }

};
