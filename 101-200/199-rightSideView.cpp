#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }
  ans.push_back(root->val);

  deque<TreeNode*> q1, q2;
  q1.push_back(root);

  while (!(q1.empty() && q2.empty())) {
    deque<TreeNode*>& q = q1.empty() ? q2 : q1;
    deque<TreeNode*>& e = q1.empty() ? q1 : q2;

    while (!q.empty()) {
      TreeNode *front = q.front();
      if (front->left != nullptr) e.push_back(front->left);
      if (front->right != nullptr) e.push_back(front->right);
      q.pop_front();
    }

    if (!(q1.empty() && q2.empty())) {
      ans.push_back(e.back()->val);
    }
  }

  return ans;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  auto v = rightSideView(root);
  for (auto i: v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}