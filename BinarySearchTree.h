//A simple binary search tree
/*
    INSERT
    FIND
    DELETE
    OSTREAM INORDER PRINT METHOD
    DESTRUCTOR FOR TREE AND NODE
*/

template <class X> class BST
{
private:

  struct Node
  {
    X* data
    Node* left;
    Node* right
  }

  Node* root;

  Node* insert(Node* node, X data)
  {

  }

public:

  void Insert(X data)
  {
    // EITHER
    if (root == NULL)
    {
        root = insert(root, data);
    }
    else if
    {
        insert(root, data);
    }
    else
    {
      root = insert(root, data);
    }

  }


  BST();

  BST(X& data);

}
