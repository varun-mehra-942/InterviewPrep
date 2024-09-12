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

std::vector<int> PostOrder2Stack(node *root) {

  std::vector<int> ans;
  if (root == nullptr) {
    return ans;
  }
  std::stack<node *> s1, s2;
  s1.push(root);
  while (!s1.empty()) {
    node *temp = s1.top();
    s1.pop();
    s2.push(temp);
    if (temp->left != nullptr)
      s1.push(temp->left);
    if (temp->right != nullptr)
      s1.push(temp->right);
  }
  while (!s2.empty()) {
    ans.push_back(s2.top()->data);
    s2.pop();
  }
  return ans;
}
std::vector<int> Postorder(node *root) {
  std::stack<node *> s;
  std::vector<int> ans;
  node *temp, *curr = root;
  while (curr != nullptr || !s.empty()) {
    if (curr != nullptr) {
      s.push(curr);
      curr = curr->left;
    } else {
      temp = s.top()->right;
      if (temp == nullptr) {
        temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        while (!s.empty() && temp == s.top()->right) {
          temp = s.top();
          s.pop();
          ans.push_back(temp->data);
        }
      } else {
        curr = temp;
      }
    }
  }
  return ans;
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
  ans = Postorder(root);
  for (auto i : ans)
    std::cout << i << " ";
  return 0;
}
