
#include <algorithm>
#include <cstdlib>
#include <iostream>
struct node {
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};
int maxDepth(node *root) {
  if (root == nullptr)
    return 0;

  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int isBalanced(node *root) {
  if (root == nullptr)
    return 0;

  int lh = isBalanced(root->left);
  int rh = isBalanced(root->right);
  if (abs(lh - rh) > 1 or lh == -1 or rh == -1)
    return -1;
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
  root->right->right->right = new node(9);
  root->right->right->right->right = new node(9);

  std::cout << ((isBalanced(root) > 1) ? "true" : "false");
  return 0;
}
