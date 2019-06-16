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
    if (this->data == NULL)
    {
      this->data = new X(data);
    }

    else if (*(this->data) < data && this->right != NULL)
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
      return this->right->Contains(key);
    }
    else if (*(this->data) > key && this->left != NULL)
    {
      return this->left->Contains(key);
    }
    else
    {
      return false;
    }
  }

  X* Find(X key)
  {
    if (*(this->data) == key)
    {
      return this->data;
    }
    else if (*(this->data) < key && this->right != NULL)
    {
      return this->right->Find(key);
    }
    else if (*(this->data) > key && this->left != NULL)
    {
      return this->left->Find(key);
    }
    else
    {
      return NULL;
    }
  }

  X* Remove(X key)
  {
    if (this->Contains(key) == false)
    {
        return NULL;
    }
    // get pointer to node ie TreeNode node = right
    // set right to node->right
    // set node->right to null
    // handle if right->left not null ie set left node->left
    // set node left null
    // delete node
    // BECAUSE OF DESTRUCTOR
    if (this->right != NULL && *(this->right->data) == key)
    {
      TreeNode<X>* right = this->right->right;
      if (this->right->left != NULL)
      {
        TreeNode<X>* left = this->right->left;
        this->Add(*(this->right->left->data));
      }
      this->right = NULL;

      delete this->right;
      this->right = right;


    }

    else if (this->left != NULL && *(this->left->data) == key)
    {
      TreeNode<X>* left = this->left->left;
      if (this->left->right != NULL)
      {
        X right_data = *(this->left->right->data);
        this->right = NULL;
        
      }
      this->left = NULL;


      delete this->left;
      this->left = left;
    }

    else if (*(this->data) < key && this->right != NULL)
    {
      return this->right->Remove(key);
    }

    else if (*(this->data) > key && this->left != NULL)
    {
      return this->left->Remove(key);
    }
  }

friend ostream& operator<<(ostream& stream, TreeNode& tree)
{
    if (tree.left != NULL)
    {
        stream << *(tree.left);
    }

    stream << *(tree.data) << ", ";

    if (tree.right != NULL)
    {
        stream << *(tree.right);
    }

    return stream;
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

  ~TreeNode()
  {
    if (this->data != NULL)
    {
        delete this->data;
        this->data = NULL;
    }

    if (this->left != NULL)
    {
        delete this->left;
        this->left = NULL;
    }

    if (this->right != NULL)
    {
        delete this->right;
        this->right = NULL;
    }
  }
};

#endif
