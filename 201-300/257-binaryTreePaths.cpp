#include <cstdio>
#include <cstring>
#include <cstdlib>
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

string constructStringFromArray(vector<int>& vals) {
  char *str = new char[vals.size() * 5];
  char *strStart = str;
  for (int i = 0; i < vals.size(); i++) {
    if (i == 0) sprintf(str, "%d", vals[i]);
    else sprintf(str, "->%d", vals[i]);
    str = strStart + strlen(strStart);
  }

  return string(strStart);
}

void dfs(TreeNode *root, vector<int>& temp, vector<string>& res) {
  temp.push_back(root->val);

  // reach leaf
  if (root->left == nullptr && root->right == nullptr) {
    res.push_back(constructStringFromArray(temp));
    temp.pop_back();
    return;
  }

  if (root->left != nullptr) {
    dfs(root->left, temp, res);
  }
  if (root->right != nullptr) {
    dfs(root->right, temp, res);
  }
  temp.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<int> temp;
  vector<string> res;

  dfs(root, temp, res);
  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  auto res = binaryTreePaths(root);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}