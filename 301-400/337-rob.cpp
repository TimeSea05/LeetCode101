#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Info {
  int selected;
  int unselected;
};

Info dfs(TreeNode *root) {
  if (root == nullptr) {
    return Info{0,0};
  }

  Info l = dfs(root->left);
  Info r = dfs(root->right);

  Info ans;
  ans.selected = root->val + l.unselected + r.unselected;
  ans.unselected = std::max(l.selected, l.unselected) + std::max(r.selected, r.unselected);

  return ans;
}

int rob(TreeNode *root) {
  Info i = dfs(root);
  return std::max(i.selected, i.unselected);
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(1);

  std::cout << rob(root) << std::endl;
  return 0;
}