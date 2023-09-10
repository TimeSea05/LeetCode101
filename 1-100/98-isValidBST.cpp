#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Res {
  long minNum;
  long maxNum;
  bool valid;
  Res(): minNum(LONG_MAX), maxNum(LONG_MIN), valid(true) {}
  Res(long maxNum, bool valid): maxNum(maxNum), valid(valid) {}
};

Res isValidBSTRes(TreeNode *root) {
  if (root == nullptr) {
    return Res();
  }

  Res l = isValidBSTRes(root->left);
  Res r = isValidBSTRes(root->right);

  Res cur;
  cur.valid = l.valid && r.valid && (l.maxNum < root->val && r.minNum > root->val);
  cur.maxNum = max(max(l.maxNum, long(root->val)), r.maxNum);
  cur.minNum = min(min(l.minNum, long(root->val)), r.minNum);

  return cur;
}

bool isValidBST(TreeNode *root) {
  return isValidBSTRes(root).valid;
}

int main() {
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(1);

  cout << ((isValidBST(root)) ? "true" : "false") << endl;
}