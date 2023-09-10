#include <bits/stdint-uintn.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using std::string;
using std::to_string;
using std::stoi;
using std::vector;
using std::uint64_t;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
  struct Node {
    int val;
    unsigned long ptr;
    Node(int val, unsigned long ptr): val(val), ptr(ptr) {}
  };

  void preorderEncode(TreeNode *root, string &data) {
    if (root == nullptr) {
      return;
    }
    data += "(";
    data += to_string(root->val);
    data += ",";
    data += to_string(uint64_t(root));
    data += ")";
    preorderEncode(root->left, data);
    preorderEncode(root->right, data);
  }

  void inorderEncode(TreeNode *root, string& data) {
    if (root == nullptr) {
      return;
    }

    inorderEncode(root->left, data);
    data += "(";
    data += to_string(root->val);
    data += ",";
    data += to_string(uint64_t(root));
    data += ")";
    inorderEncode(root->right, data);
  }

  vector<Node> decode(string data) {
    int size = data.size();
    vector<Node> res;

    int i = 0, j = 0;
    while (i < size && j < size) {
      int comma;
      while (data[j] != ')') {
        if (data[j] == ',') {
          comma = j;
        }
        j++;
      }

      res.push_back(Node(
        stoi(data.substr(i+1, comma-i-1)),
        std::stoul(data.substr(comma+1, j-comma-1))
      ));
      j++, i = j;
    }

    return res;
  }

  TreeNode *constructTree(vector<Node>& preorder, vector<Node>& inorder) {
    int size = preorder.size();
    if (size == 0) {
      return nullptr;
    } else if (size == 1) {
      return new TreeNode(preorder[0].val);
    }

    Node rootNode = preorder[0];
    int rootInorderIdx;
    for (rootInorderIdx = 0; rootInorderIdx <= size; rootInorderIdx++) {
      if (inorder[rootInorderIdx].val == rootNode.val && inorder[rootInorderIdx].ptr == rootNode.ptr) {
        break;
      }
    }

    int leftSize = rootInorderIdx, rightSize = size - rootInorderIdx - 1;
    vector<Node> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftSize);
    vector<Node> leftInorder(inorder.begin(), inorder.begin()+leftSize);
    vector<Node> rightPreorder(preorder.begin()+leftSize+1, preorder.end());
    vector<Node> rightInorder(inorder.begin()+leftSize+1, inorder.end());

    TreeNode *root = new TreeNode(rootNode.val);
    root->left = constructTree(leftPreorder, leftInorder);
    root->right = constructTree(rightPreorder, rightInorder);

    return root;
  }

public:
  string serialize(TreeNode *root) {
    string preorderData, inorderData;
    preorderEncode(root, preorderData);
    inorderEncode(root, inorderData);

    return preorderData + "." + inorderData;
  }

  TreeNode *deserialize(string data) {
    int split;
    for (split = 0; split < data.size(); split++) {
      if (data[split] == '.') {
        break;
      }
    }

    vector<Node> preorder = decode(data.substr(0, split));
    vector<Node> inorder = decode(data.substr(split+1));

    return constructTree(preorder, inorder);
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right = new TreeNode(4);

  Codec ser;
  TreeNode *tree = ser.deserialize(ser.serialize(root));
}
