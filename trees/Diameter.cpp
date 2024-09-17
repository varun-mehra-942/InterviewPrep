#include <climits>
#include <cstdlib>
#include <iostream>
struct node {
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
  }
};
// diameter of a tree is referred to the largest distance between 2 node that
// not necessarily passing from the root node.
int diameter(node *root, int &dia) {
  if (root == nullptr)
    return 0;

  int lh = diameter(root->left, dia);
  int rh = diameter(root->right, dia);

  dia = std::max(lh + rh, dia);
  return std::max(lh, rh) + 1;
}
int main(int argc, char *argv[]) {

  node *root = new node(2);
  root->left = new node(3);
  root->right = new node(4);
  root->left->left = new node(5);
  root->left->right = new node(6);
  root->right->left = new node(7);
  root->right->right = new node(8);
  int res = 0;
  diameter(root, res);
  std::cout << res;
  return 0;
}
