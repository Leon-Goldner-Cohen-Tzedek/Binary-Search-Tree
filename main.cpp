#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
  BST<int> tree_three(10);

  tree_three.Add(11);
  tree_three.Add(9);

  cout << tree_three.Contains(10) << endl;

  return 0;
}
