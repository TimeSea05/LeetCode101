#include "../lib/libleetcode.h"

void dfs(TreeNode* root, int& sum) {
  if (root == nullptr) {
    return;
  }
  dfs(root->right, sum);
  sum += root->val;
  root->val = sum;
  dfs(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
  int sum = 0;
  dfs(root, sum);
  return root;
}

int main() {
  vector<int> nums{4,1,6,0,2,5,7,null,null,null,3,null,null,null,8};
  TreeNode *root = constructBinaryTree(nums);
  TreeNode *convertedTree = convertBST(root);

  levelOrderTraversal(root);
}
