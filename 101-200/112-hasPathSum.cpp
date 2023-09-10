#include "../lib/libleetcode.h"

bool hasPathSum(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return false;
  }

  if (root->val == targetSum) {
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }
  }

  if (hasPathSum(root->left, targetSum - root->val)) {
    return true;
  }
  return hasPathSum(root->right, targetSum-root->val);
}

int main() {
  vector<int> arr{1,-2,-3,1,3,-2,null,-1};
  TreeNode *root = constructBinaryTree(arr);
  check(hasPathSum(root, -1));
  return 0;
}