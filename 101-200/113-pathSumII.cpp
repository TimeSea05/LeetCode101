#include "../lib/libleetcode.h"

void dfs(TreeNode *root, int targetSum, vector<vector<int>>& ans, vector<int>& tmp) {
  if (root == nullptr) {
    return;
  }

  tmp.push_back(root->val);
  if (root->val == targetSum) {
    if (root->left == nullptr && root->right == nullptr) {
      ans.push_back(tmp);
      tmp.pop_back();
      return;
    }
  }

  dfs(root->left, targetSum - root->val, ans, tmp);
  dfs(root->right, targetSum - root->val, ans, tmp);
  tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  vector<vector<int>> ans;
  vector<int> tmp;
  dfs(root, targetSum, ans, tmp);
  return ans;
}

int main() {
  vector<int> arr{1,2,3};
  TreeNode *root = constructBinaryTree(arr);
  auto matrix = pathSum(root, 22);
  print2DVector(matrix);

  return 0;
}