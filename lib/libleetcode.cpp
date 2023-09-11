#include "libleetcode.h"
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

void printList(ListNode *head) {
  ListNode *ptr = head;
  while (ptr != nullptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

ListNode* constructList(vector<int>& arr) {
  ListNode dummy(0);
  ListNode *ptr = &dummy;
  for (int i: arr) {
    ptr->next = new ListNode(i);
    ptr = ptr->next;
  }

  return dummy.next;
}


TreeNode* constructBinaryTree(vector<int>& arr) {
  int size = arr.size();
  if (size == 0) {
    return nullptr;
  }

  int rootVal = arr[0];
  TreeNode *root = new TreeNode(rootVal);

  queue<TreeNode*> q1, q2;
  q1.push(root);

  int i = 1;
  while (i < size) {
    queue<TreeNode*> &q = q1.empty() ? q2 : q1;
    queue<TreeNode*> &e = q1.empty() ? q1 : q2;

    while (!q.empty() && i < size) {
      TreeNode *node = q.front(); q.pop();
      if (arr[i] != null) {
        node->left = new TreeNode(arr[i]);
        e.push(node->left);
      }
      i++;
      if (i >= size) break;

      if (arr[i] != null) {
        node->right = new TreeNode(arr[i]);
        e.push(node->right);
      }
      i++;
      if (i >= size) break;
    }
  }

  return root;
}

void levelOrderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front(); q.pop();
    cout << node->val << " ";
    if (node->left != nullptr) {
      q.push(node->left);
    }
    if (node->right != nullptr) {
      q.push(node->right);
    }
  }

  cout << endl;
}

void check(bool val) {
  cout << (val ? "true" : "false") << endl;
}