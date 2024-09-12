#include <iostream>
#include <stack>
#include <utility>
#include <vector>
struct node {
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};
void display(std::vector<int> vec, std::string s) {
  std::cout << s << " ";
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void IncrementValue(std::stack<std::pair<node *, int>> &s) {

  std::pair<node *, int> temp;
  temp = s.top();
  s.pop();
  temp.second++;

  s.push(temp);
}

// we cant do temp.second++ as we cant direclty modify the values in stack we
// first need to pop is annd then modify is
//
// the idea is to keep track of each element using a integer attacked to the
// element, if the count is 1 then we will push the element to the
// pre(root,left,right) and increment the value of the integer
void InPrePost(node *root) {
  if (root == nullptr)
    return;
  int count = 10;
  std::stack<std::pair<node *, int>> s;
  std::vector<int> pre, in, post;
  s.push(std::make_pair(root, 1));
  while (!s.empty()) {
    std::pair<node *, int> temp = s.top();
    if (temp.second == 1) {
      pre.push_back(temp.first->data);
      IncrementValue(s);
      if (temp.first->left != nullptr) {
        s.push(std::make_pair(temp.first->left, 1));
      }
    } else if (temp.second == 2) {
      in.push_back(temp.first->data);
      IncrementValue(s);
      if (temp.first->right != nullptr) {
        s.push(std::make_pair(temp.first->right, 1));
      }
    } else {
      s.pop();
      post.push_back(temp.first->data);
    }
  }
  display(pre, "Preorder");
  display(in, "Inorder");
  display(post, "Postorder");
}
int main(int argc, char *argv[]) {

  node *root = new node(2);
  root->left = new node(3);
  root->right = new node(4);
  root->left->left = new node(5);
  root->left->right = new node(6);
  root->right->left = new node(7);
  root->right->right = new node(8);
  InPrePost(root);
  return 0;
}
