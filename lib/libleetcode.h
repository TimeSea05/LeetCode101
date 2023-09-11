#ifndef LIBLEETCODE_H_
#define LIBLEETCODE_H_

#include <vector>
#include <climits>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

const int null = -INT_MAX;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

template <typename T>
void printVector(vector<T>& v) {
  for (T i: v) {
    cout << i << " ";
  }
  cout << endl;
}

template <typename T>
void print2DVector(vector<vector<T> > &matrix) {
  for (vector<T>& v: matrix) {
    for (T i: v) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printList(ListNode *head);
void levelOrderTraversal(TreeNode *root);

TreeNode* constructBinaryTree(vector<int>& arr);
ListNode* constructList(vector<int>& arr);

void check(bool val);
#endif