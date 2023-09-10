#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::sort;
struct ListNode {

  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode* list1, ListNode* list2) {
  ListNode dummy;
  ListNode *ptr = &dummy;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      ptr->next = list1;
      ptr = ptr->next;
      list1 = list1->next;
    } else {
      ptr->next = list2;
      ptr = ptr->next;
      list2 = list2->next;
    }
  }

  ptr->next = (list1 != nullptr) ? list1 : list2;
  return dummy.next;
}

ListNode* cut(ListNode* list, int count) {
  while (--count && list != nullptr) {
    list = list->next;
  }

  if (list == nullptr) {
    return nullptr;
  }

  ListNode* next = list->next;
  list->next = nullptr;
  return next;
}

ListNode* sortList(ListNode* head) {
  // get the length of list
  int len = 0;
  ListNode* ptr = head;
  while (ptr) {
    ptr = ptr->next;
    len++;
  }

  ListNode dummy;
  dummy.next = head;

  for (int step = 1; step < len; step *= 2) {
    ListNode *tail = &dummy;
    ListNode *cur = dummy.next;
    while (cur) {
      ListNode *left = cur;
      ListNode *right = cut(cur, step);
      cur = cut(right, step);

      tail->next = merge(left, right);
      while (tail->next != nullptr) {
        tail = tail->next;
      }
    }
  }

  return dummy.next;
}

int main() {
  ListNode *list = new ListNode(-1);
  list->next = new ListNode(5);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);
  list->next->next->next->next = new ListNode(0);

  ListNode* res = sortList(list);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }

  cout << endl;
}