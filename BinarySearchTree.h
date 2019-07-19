//A simple binary search tree
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

    Node(X data)
    {
      this->data = new X(data);
      this->left = nullptr;
      this->right = nullptr;
    }
    ~Node()
    {
      if (left != nullptr)
      {
        delete left;
        left = nullptr;
      }
      if (right != nullptr)
      {
        delete right;
        right = nullptr;
      }
      if (data != nullptr)
      {
        delete data;
        data = nullptr;
      }
    }
  };

  Node* root;

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

  Node* Private_Remove(Node* node, X key)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (key < *(node->data))
    {
      node->left = Private_Remove(node->left, key);
    }
    else if (key > *(node->data))
    {
      node->right = Private_Remove(node->right, key);
    }
    else
    {
      if (node->left == nullptr)
      {
        Node* temp = node->right;
        delete node;
        return temp;
      }
      else if (node->right == nullptr)
      {
        Node* temp = node->left;
        delete node;
        return temp;
      }
      else
      {
        Node* current_node = node->right;
        while (current_node && current_node->left != nullptr)
        {
          current_node = current_node->left;
        }
        node->data = current_node->data;
        node->right = Private_Remove(node->right, key);
      }
    }
    return node;
  }

  Node* Private_Add(Node* node, X data)
  {
    if (node == nullptr)
    {
      return new Node(data);
    }
    if (node->data != nullptr && data < *(node->data))
    {
      node->left = Private_Add(node->left, data);
    }
    else if (node->data != nullptr && data > *(node->data))
    {
      node->right = Private_Add(node->right, data);
    }
    return node;
  }

  ostream& Print_In_Order(ostream& stream, Node* node)
  {
    if (node == nullptr || node->data == nullptr)
    {
      return stream;
    }

    Print_In_Order(stream, node->left);

    stream << *(node->data) << ", ";

    Print_In_Order(stream, node->right);

    return stream;
  }

public:
  void Add(X data) //all of these public methods are basically just wrapping the struct for ease of use
  {
    if (root == nullptr)
    {
      root = Private_Add(root, data);
    }
    else
    {
      Private_Add(root, data);
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

  void Remove(X key)
  {
    root = Private_Remove(root, key);
  }

  Node* Root()
  {
    return root;
  }


  friend ostream& operator<<(ostream& stream, BST& bst)
  {
    return bst.Print_In_Order(stream, bst.Root());
  }

  BST()
  {
    root = nullptr;
  }

  BST(X data)
  {
    root = new Node(data);
  }

  ~BST()
  {
    if (root != nullptr)
    {
      delete root;
      root = nullptr;
    }
  }

};
