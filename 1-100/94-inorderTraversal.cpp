#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<int>& v) {
  if (root == NULL) {
    return;
  }
  inorder(root->left, v);
  v.push_back(root->val);
  inorder(root->right, v);
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> v;
  inorder(root, v);
  return v;
}

vector<int> inorderTraversalStack(TreeNode* root) {
  vector<int> v;
  stack<TreeNode*> stk;
  if (root != NULL) {
    stk.push(root);
  }

  while (!stk.empty()) {
    TreeNode *n = stk.top();

    if (n->left != NULL) {
      stk.push(n->left);
      n->left = NULL;
      continue;
    }

    v.push_back(n->val);
    stk.pop();

    if (n->right != NULL) {
      stk.push(n->right);
    }
  }

  return v;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> v = inorderTraversalStack(root);
  int size = v.size();
  for (int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}