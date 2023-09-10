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

int findVal(const vector<int>& v, int val) {
  for (int i = 0; i < int(v.size()); i++) {
    if (v[i] == val) {
      return i;
    }
  }

  return -1;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int rootVal = preorder[0];
  TreeNode *root = new TreeNode(rootVal);

  int idx = findVal(inorder, rootVal);
  int leftSubTreeNodeNum = idx, rightSubTreeNodeNum = inorder.size()-idx-1;
  if (leftSubTreeNodeNum > 0) {
    // construct left sub tree
    vector<int> leftPreorder = vector<int>(preorder.begin()+1, preorder.begin()+leftSubTreeNodeNum+1);
    vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin()+leftSubTreeNodeNum);
    root->left = buildTree(leftPreorder, leftInorder);
  }

  if (rightSubTreeNodeNum > 0) {
    // construct right sub tree
    vector<int> rightPreorder = vector<int>(preorder.begin()+1+leftSubTreeNodeNum, preorder.end());
    vector<int> rightInorder = vector<int>(inorder.begin()+idx+1, inorder.end());
    root->right = buildTree(rightPreorder, rightInorder);
  }

  return root;
}

void printTreePreorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cerr << root->val << " ";
  printTreePreorder(root->left);
  printTreePreorder(root->right);
}

int main() {
  vector<int> preorder{3, 9, 20, 15, 7};
  vector<int> inorder{9, 3, 15, 20, 7};
  TreeNode *root = buildTree(preorder, inorder);
  printTreePreorder(root);
  return 0;
}
