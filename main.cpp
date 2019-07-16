#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
  BST<int> tree_three(10);
  BST<int> tree_too;

  tree_three.Add(11);
  tree_three.Add(9);
  tree_too.Add(10);
  tree_too.Add(11);
  tree_too.Add(9);

  return 0;
}
