
#include <algorithm>
#include <climits>
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
// we will traverse the tree and for any given node we will check if the sum of
// left subtree + the sum of right subtree +  the node data value is greater
// than the max value ,if so then we will update the max and do this for every
// node. for leaf nodes the sum for both left and right subtree is 0 so they
// will return their data value.
// we can use both refferences ans global variables.
int maxPathSum(node *root, int &max) {
  if (root == nullptr)
    return 0;

  int ml = maxPathSum(root->left, max);
  int mr = maxPathSum(root->right, max);

  max = std::max(max, ml + mr + root->data);

  return std::max(ml, mr) + root->data;
}
int main(int argc, char *argv[]) {

  node *root = new node(2);
  root->left = new node(3);
  root->right = new node(4);
  root->left->left = new node(5);
  root->left->right = new node(6);
  root->right->left = new node(7);
  root->right->right = new node(8);
  // we will use ans instead of directly using intmin as intmin is a constant
  // hence will give an error.
  int ans = INT_MIN;
  maxPathSum(root, ans);
  std::cout << ans;

  return 0;
}
