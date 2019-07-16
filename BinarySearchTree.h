//A simple binary search tree
/*
    INSERT WORKS REALLY DOES WORK THIS TIME
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

  Node* root = new Node(); //This took me an embarassing amount of time to remember to do. . .

  Node* Private_Add(Node* node, X key)
  {
    if (node->data != nullptr && key < *(node->data))
    {
      node->left = new Node();
      node->left = Private_Add(node->left, key);
    }
    else if (node->data != nullptr && key > *(node->data))
    {
      node->right = new Node();
      node->right = Private_Add(node->right, key);
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
    if (root->data != nullptr && key < *(root->data))//all of this handles the root node, Private_Add handles the rest
    {
      root->left = Private_Add(root->left, key);
    }
    if (root->data != nullptr && key > *(root->data))
    {
      root->right = Private_Add(root->right, key);
    }
    else
    {
      root->data = new X(key);
    }
  }

  BST()
  {
    root->data = nullptr;
    root->left = new Node();
    root->right = new Node();
  }

  BST(X data)
  {
    root->data = new X();
    root->left = new Node();
    root->right = new Node();

    this->Add(data);
  }

};
