#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct PathInfo {
  int maxPathLen;
  int maxRootPathLen;
  PathInfo(int plen, int rplen): maxPathLen(plen), maxRootPathLen(rplen) {}
};

PathInfo searchPath(TreeNode *root) {
  if (root == nullptr) {
    return PathInfo(0, 0);
  }

  PathInfo lpathInfo = searchPath(root->left);
  PathInfo rpathInfo = searchPath(root->right);
  int maxRootPathLen = max(max(lpathInfo.maxRootPathLen, rpathInfo.maxRootPathLen), 0) + root->val;
  int maxPathLen = max(
    max(maxRootPathLen, lpathInfo.maxRootPathLen + root->val + rpathInfo.maxRootPathLen),
    max(lpathInfo.maxPathLen, rpathInfo.maxPathLen)
  );

  return PathInfo(maxPathLen, maxRootPathLen);
}

int maxNodeVal(TreeNode *root) {
  int maxVal = root->val;
  if (root->left != nullptr) {
    maxVal = max(maxVal, maxNodeVal(root->left));
  }
  if (root->right != nullptr) {
    maxVal = max(maxVal, maxNodeVal(root->right));
  }

  return maxVal;
}

int maxPathSum(TreeNode *root) {
  int len = searchPath(root).maxPathLen;
  if (len != 0) {
    return len;
  }

  return maxNodeVal(root);
}

int main() {
  TreeNode *root = new TreeNode(-10);
  // root->left = new TreeNode(9);
  // root->right = new TreeNode(20);
  // root->right->left = new TreeNode(15);
  // root->right->right = new TreeNode(7);

  cout << maxPathSum(root) << endl;
  return 0;
}
