#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
  TreeNode<int>* tree = new TreeNode<int>;

  tree->Add(3);
  tree->Add(5);
  tree->Add(7);
  tree->Add(4);
  tree->Add(10);
  tree->Add(33);
  tree->Add(2);
  tree->Add(9);

  cout << *(tree->Find(5)) << endl;
  cout << *(tree) << endl;
  tree->Remove(5);
  cout << *(tree) << endl;
  delete tree;



  return 0;
}
