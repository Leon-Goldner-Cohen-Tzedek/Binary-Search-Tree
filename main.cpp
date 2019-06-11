#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
  TreeNode<int>* tree = new TreeNode<int>(10);

  tree->Add(3);
  tree->Add(23);
  tree->Add(5);
  tree->Add(17);
  tree->Add(18);
  tree->Add(16);

  tree->Remove(5);
  cout << tree->Contains(17) << endl;
  cout << tree->Find(16) << endl;
  cout << tree->Contains(5) << endl;

  return 0;
}
