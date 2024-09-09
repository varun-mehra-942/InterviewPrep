#include <iostream>
#include <stack>
#include <vector>
struct node {
  int data;
  node *left, *right;
  node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};

std::vector<int> PreOrder(node *root) {
  std::vector<int> ans;
  if (root != nullptr) {
    return ans;
  }

  std::stack<node *> s;
  s.push(root);
  while (!s.empty()) {
    node *temp = s.top();
    ans.push_back(temp->data);
    s.pop();
    if (temp->right != nullptr)
      s.push(temp->right);
    if (temp->left != nullptr)
      s.push(temp->left);
  }
  return ans;
}

std::vector<int> PostOrder(node *root) {

  std::vector<int> ans;
  if (root != nullptr) {
    return ans;
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
  std::vector<int> ans;
  ans = PreOrder(root);
  for (auto i : ans)
    std::cout << i << " ";
  return 0;
}
