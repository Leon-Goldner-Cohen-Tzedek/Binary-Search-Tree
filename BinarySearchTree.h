// A simple binary search tree in c++
#include <iostream>

using namespace std;

#ifndef TreeNode_H_INCLUDED
#define TreeNode_H_INCLUDED


template <class X>
class TreeNode

{
private:
  TreeNode<X>* left;
  TreeNode<X>* right;
  X* data;

public:

  void Add(X data)
  {
    if (*(this->data) < data && this->right != NULL)
    {
      this->right->Add(data);
    }
    else if (*(this->data) > data && this->left != NULL)
    {
      this->left->Add(data);
    }

    else if (*(this->data) < data && this->right == NULL)
    {
      this->right = new TreeNode<X>(data);
    }
    else if (*(this->data) > data && this->left == NULL)
    {
      this->left = new TreeNode<X>(data);
    }

  }

  bool Contains(X key)
  {
    if (*(this->data) == key)
    {
      return true;
    }
    if (*(this->data) < key && this->right != NULL)
    {
      this->right->Contains(key);
    }
    else if (*(this->data) > key && this->left != NULL)
    {
      this->left->Contains(key);
    }
    else
    {
      return false;
    }
  }

  X Find(X key)
  {
    if (*(this->data) == key)
    {
      return *(this->data);
    }
    else if (*(this->data) < key && this->right != NULL)
    {
      this->right->Find(key);
    }
    else if (*(this->data) > key && this->left != NULL)
    {
      this->left->Find(key);
    }
    else
    {
      return 0; //find a better way to return a "not found"
    }
  }

  void Remove(X key)
  {
    if (*(this->right->data) == key)
    {
      delete this->right->data;
      this->right = this->right->right;

      if (this->right->left != NULL)
      {
        this->left = this->right->left;//handles the removed nodes child
      }
    }
    else if (*(this->left->data) == key)
    {
      delete this->left->data;
      this->left = this->left->left;

      if (this->right->right != NULL)
      {
        this->right = this->left->right;//handles the removed nodes child
      }
    }
    else if (*(this->data) < key && this->right != NULL)
    {
      this->right->Remove(key);
    }
    else if (*(this->data) > key && this->left != NULL)
    {
      this->left->Remove(key);
    }
  }

  TreeNode()
  {
    this->left = NULL;
    this->right = NULL;
    this->data = NULL;
  }

  TreeNode(X data)
  {
    this->left = NULL;
    this->right = NULL;
    this->data = new X(data);
  }
};


#endif
