#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  TreeNode *ptr = root;
  while (ptr != nullptr) {
    if (ptr->left == nullptr) {
      ptr = ptr->right;
      continue;
    }

    TreeNode *pred = ptr->left;
    while (pred->right != nullptr) {
      pred = pred->right;
    }

    TreeNode *right = ptr->right;
    ptr->right = ptr->left;
    ptr->left = nullptr;
    pred->right = right;

    ptr = ptr->right;
  }
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  flatten(root);

  while (root != nullptr) {
    cout << root->val << " ";
    root = root->right;
  }
  cout << endl;
}
