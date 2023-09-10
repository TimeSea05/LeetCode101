struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void invert(TreeNode *root) {
  if (root == nullptr || root->left == root->right) {
    return;
  }
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  if (root->left != nullptr) {
    invert(root->left);
  }
  if (root->right != nullptr) {
    invert(root->right);
  }
}

TreeNode *invertTree(TreeNode *root) {
  invert(root);
  return root;
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  TreeNode *inverted = invertTree(root);
}