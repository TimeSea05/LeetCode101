#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> res;
  queue<TreeNode*> q1, q2;
  if (root == nullptr) {
    return res;
  }

  q1.push(root);
  while (!q1.empty() || !q2.empty()) {
    queue<TreeNode*>& q = (q1.empty()) ? q2 : q1;
    queue<TreeNode*>& e = (q1.empty()) ? q1 : q2;

    vector<int> v;
    while (!q.empty()) {
      TreeNode *n = q.front(); q.pop();
      v.push_back(n->val);

      if (n->left != nullptr) {
        e.push(n->left);
      }
      if (n->right != nullptr) {
        e.push(n->right);
      }
    }
    res.push_back(v);
  }

  return res;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  auto v = levelOrder(root);
  for (int i = 0; i < int(v.size()); i++) {
    for (int j = 0; j < int(v[i].size()); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
