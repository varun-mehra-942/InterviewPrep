#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data) {
    this->data = data;
    this->left = this->right = nullptr;
  }
};
std::vector<std::pair<int, TreeNode *>> vo;
void verticalOrder(TreeNode *root) {

  std::map<int, std::multiset<int>> nodes;
  std::queue<std::pair<TreeNode *, int>> q;

  q.push({root, 0});

  while (!q.empty()) {
    TreeNode *tempNode = q.front().first;
    int col = q.front().second;
    q.pop();

    nodes[col].insert(tempNode->data);
    if (tempNode->left != nullptr) {
      q.push({tempNode->left, col - 1});
    }
    if (tempNode->right != nullptr) {
      q.push({tempNode->right, col + 1});
    }
  }

  std::vector<std::vector<int>> ans;
  for (auto i : nodes) {
    std::vector<int> temp;
    for (auto j : i.second) {
      temp.push_back(j);
    }
    ans.push_back(temp);
  }

  for (auto i : ans) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {

  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(8);
  verticalOrder(root);

  return 0;
}
