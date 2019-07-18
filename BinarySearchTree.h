//A simple binary search tree
/*
    INSERT WORKS REALLY DOES WORK THIS TIME
    FIND WORKS - JANKY THOUGH USED IN CONTAINS
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

  Node* Private_Add(Node* node, X data)
  {
    if (node->data != nullptr && data < *(node->data))
    {
      node->left = new Node();
      node->left = Private_Add(node->left, data);
    }
    else if (node->data != nullptr && data > *(node->data))
    {
      node->right = new Node();
      node->right = Private_Add(node->right, data);
    }
    else
    {
      Node* new_node = new Node();
      new_node->data = new X(data);
      return new_node;
    }
  }

  X* Private_Find(Node* node, X key)
  {
    if (node->left != nullptr && node->data != nullptr && key < *(node->data))
    {
      return Private_Find(node->left, key);
    }
    else if (node->right != nullptr && node->data != nullptr &&  key > *(node->data))
    {
      return Private_Find(node->right, key);
    }
    else if (node->right == nullptr && *(node->data) != key && node->left == nullptr)
    {
      return nullptr;
    }
    else
    {
      return node->data;
    }
  }


  Node* Private_Delete(Node* node, X key)
  {
    if (key < *(node->data))
    {
      node->left = Private_Delete(node->left, key);
    }
    else if (key > *(node->data))
    {
      node->right = Private_Delete(node->right, key);
    }
    else
    {
      if (node->left == nullptr)
      {
        Node* temp = new Node();
        delete node->right;
        return temp;
      }
      else if (node->right == nullptr)
      {
        Node* temp = new Node();
        delete node->left;
        return temp;
      }
      else //find the left most child and make that the root of the subtree
      {
        Node* leftmost = new Node();
        //to start off the chain and go down from there: setting leftmost to the current node so as to traverse from this node as the new "root"
        leftmost->data = new X();
        while (leftmost && leftmost->left != nullptr)
        {
          leftmost = leftmost->left;
        }
        node->data = leftmost->data;
        node->right = Private_Delete(node->right, *(leftmost->data)); //deletes the the leftmost after it has been transffered
      }
    }
  }

public:
  void Add(X data) //all of these public methods are basically just wrapping the struct for ease of use
  {
    if (root->data != nullptr && data < *(root->data))//all of this handles the root node, Private_Add handles the rest
    {
      root->left = Private_Add(root->left, data);
    }
    if (root->data != nullptr && data > *(root->data))
    {
      root->right = Private_Add(root->right, data);
    }
    else
    {
      root->data = new X(data);
    }
  }

  X* Find(X key)
  {
    return Private_Find(root, key);
  }

  bool Contains(X key)
  {
    if (Private_Find(root, key) == nullptr)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void Delete(X key)
  {
    root = Private_Delete(root, key);
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
