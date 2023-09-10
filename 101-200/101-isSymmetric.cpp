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

// bool nodeEqual(TreeNode *n1, TreeNode *n2) {
//   if (n1 == nullptr || n2 == nullptr) {
//     return false;
//   }

//   return n1->val == n2->val;
// }

// bool isSymmetric2Trees(TreeNode *tree1, TreeNode *tree2) {
//   if (tree1 == nullptr && tree2 == nullptr) {
//     return true;
//   }
//   if (!nodeEqual(tree1, tree2)) {
//     return false;
//   }

//   return isSymmetric2Trees(tree1->left, tree2->right) &&
//     isSymmetric2Trees(tree1->right, tree2->left);
// }

bool isSymmetric(TreeNode *root) {
  stack<TreeNode*> stk1, stk2;
  stk1.push(root->left), stk2.push(root->right);

  bool isSymmetric = true;
  while (!stk1.empty() && !stk2.empty()) {
    TreeNode *left = stk1.top(), *right = stk2.top();
    stk1.pop(), stk2.pop();

    // one of the two is nullptr
    if (left == nullptr || right == nullptr) {
      if (left != nullptr || right != nullptr) {
        isSymmetric = false;
        break;
      }
    } else {  // both of the two are not nullptr
      if (left->val != right->val) {
        isSymmetric = false;
        break;
      }
      stk1.push(left->left), stk2.push(right->right);
      stk1.push(left->right), stk2.push(right->left); 
    }
  }

  return isSymmetric;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  // root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(3);
  // root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  cout << ((isSymmetric(root)) ? "true" : "false") << endl;
  return 0;
}
