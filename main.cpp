#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
  BST<int>* tree_three = new BST<int>(10);
  cout << *(tree_three) << endl;
  tree_three->Add(12);
  cout << *(tree_three) << endl;
  tree_three->Add(9);
  cout << *(tree_three) << endl;
  tree_three->Add(13);
  cout << *(tree_three) << endl;
  tree_three->Add(11);
  cout << *(tree_three) << endl;

  cout << tree_three->Contains(10) << endl;
  cout << *(tree_three) << endl;
  delete tree_three;
  return 0;
}
