#include <iostream>
#include <vector>
struct node {
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// here we define a function to check if the present node is a leaf node or not
bool isLeaf(node *root) {
  return (root->left == nullptr && root->right == nullptr) ? true : false;
}

// to traverse the boundary we first need the left view without leaf nodes then
// leaf nodes and then the right view, to avoid root node adding twice we will
// add root node in the beginning  and add left and right part that are not leaf
// nodes.
void addLeft(node *root, std::vector<int> &res) {

  if (root == nullptr)
    return;
  if (!isLeaf(root)) {
    res.push_back(root->data);
    if (root->left != nullptr) {
      addLeft(root->left, res);
    } else if (root->right != nullptr) {
      addLeft(root->right, res);
    }
  }
  return;
}
void addright(node *root, std::vector<int> &res) {

  if (root == nullptr)
    return;
  if (!isLeaf(root)) {
    if (root->right != nullptr) {
      addright(root->right, res);
    } else if (root->left != nullptr) {
      addright(root, res);
    }
    res.push_back(root->data);
  }
  return;
}

void addLeaf(node *root, std::vector<int> &res) {

  if (root == nullptr)
    return;

  if (isLeaf(root)) {
    res.push_back(root->data);
    return;
  }

  addLeaf(root->left, res);
  addLeaf(root->right, res);
}

void BoundaryTraversal(node *root) {

  if (root == nullptr)
    return;
  std::vector<int> res;
  if (!isLeaf(root))
    res.push_back(root->data);
  addLeft(root->left, res);
  addLeaf(root, res);
  addright(root->right, res);

  for (auto i : res) {
    std::cout << i << " ";
  }
}
int main(int argc, char *argv[]) {

  node *root = new node(2);
  root->left = new node(3);
  root->right = new node(4);
  root->left->left = new node(5);
  root->left->right = new node(6);
  root->right->left = new node(7);
  root->right->right = new node(8);
  root->left->right->right = new node(11);
  BoundaryTraversal(root);
  return 0;
}
