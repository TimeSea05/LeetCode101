#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *dummy = new ListNode(0, head);
  ListNode *p = dummy;
  ListNode *q = head;
  ListNode *r = head;
  for (int i = 1; i < n; i++) {
    r = r->next;
  }

  while (r->next != nullptr) {
    p = p->next;
    q = q->next;
    r = r->next;
  }

  p->next = q->next;
  delete q;

  return dummy->next;
}

int main() {
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  for (int i = 2; i <= 5; i++) {
    p->next = new ListNode(i);
    p = p->next;
  }

  ListNode *newHead = removeNthFromEnd(head, 2);
  p = newHead;
  while (p != nullptr) {
    cout << p->val << " ";
    p = p->next;
  }

  cout << endl;
  return 0;
}