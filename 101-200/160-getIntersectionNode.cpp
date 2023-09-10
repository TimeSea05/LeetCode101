#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode *getIntersectionNodeSet(ListNode *headA, ListNode *headB) {
  std::set<ListNode*> s;
  while (headA != nullptr || headB != nullptr) {
    if (headA != nullptr) {
      if (s.count(headA)) return headA;
      s.insert(headA);
      headA = headA->next;
    }

    if (headB != nullptr) {
      if (s.count(headB)) return headB;
      s.insert(headB);
      headB = headB->next;
    }
  }

  return nullptr;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *ptrA = headA, *ptrB = headB;
  while (ptrA != nullptr && ptrB != nullptr) {
    if (ptrA == ptrB) {
      return ptrA;
    }

    ptrA = ptrA->next, ptrB = ptrB->next;
    if (ptrA == nullptr && ptrB == nullptr) {
      break;
    }
    if (ptrA == nullptr) ptrA = headB;
    if (ptrB == nullptr) ptrB = headA;
  }
  return nullptr;
}

int main() {
  ListNode *headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  ListNode *headB = new ListNode(5);
  headB->next = new ListNode(6);
  headB->next->next = new ListNode(1);
  headB->next->next->next = headA->next->next;

  std::cout << getIntersectionNode(headA, headB)->val << std::endl;
}
