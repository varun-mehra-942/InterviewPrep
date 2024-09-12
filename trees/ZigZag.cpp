
#include <iostream>
#include <queue>
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

// to traverse the tree in zig zag we will keep a flag to specify the direction
// in which the element should be inserted in the vector, we will insert the
// root the pop it and insert its children and do that for every node, if flag
// is 0 we insert from left to right else we insert from right to left ( size-1
// -- last index ).
void zigzag(node *root) {
  if (root == nullptr)
    return;

  int flag = 0;
  std::queue<node *> q;
  q.push(root);
  std::vector<std::vector<int>> res;
  while (!q.empty()) {
    int size = q.size();
    std::vector<int> temp(size);
    for (int i = 0; i < size; i++) {
      node *val = q.front();
      q.pop();
      if (flag == 0) {
        temp[i] = val->data;
      } else {
        temp[size - 1 - i] = val->data;
      }
      if (val->left != nullptr)
        q.push(val->left);
      if (val->right != nullptr)
        q.push(val->right);
    }
    flag ^= 1;
    res.push_back(temp);
  }
  for (auto i : res) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
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
  root->right->right->left = new node(9);
  root->right->right->right = new node(10);
  zigzag(root);
  return 0;
}
