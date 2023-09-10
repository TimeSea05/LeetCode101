#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findNode(TreeNode *root, TreeNode *node) {
  if (root == nullptr) {
    return false;
  } else if (root == node) {
    return true;
  }

  return findNode(root->left, node) || findNode(root->right, node);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  bool rootEqualsP = root == p, rootEqualsQ = root == q;
  bool leftFoundP = findNode(root->left, p);
  bool rightFoundP = findNode(root->right, p);
  bool leftFoundQ = findNode(root->left, q);
  bool rightFoundQ = findNode(root->right, q);

  if (rootEqualsP) {
    if (leftFoundQ || rightFoundQ) {
      return root;
    }
    return nullptr;
  }

  if (rootEqualsQ) {
    if (leftFoundP || rightFoundP) {
      return root;
    }
    return nullptr;
  }

  if ((leftFoundP && rightFoundQ) || (leftFoundQ && rightFoundP)) {
    return root;
  }

  if (leftFoundP && leftFoundQ) {
    return lowestCommonAncestor(root->left, p, q);
  }

  if (rightFoundP && rightFoundQ) {
    return lowestCommonAncestor(root->right, p, q);
  }

  return nullptr;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  std::cout << lowestCommonAncestor(root, root->left, root->right)->val << std::endl;
  return 0;
}