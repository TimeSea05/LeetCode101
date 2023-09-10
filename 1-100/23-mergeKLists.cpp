#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode*>& lists) {
  if (lists.size() == 0) {
    return nullptr;
  } else if (lists.size() == 1) {
    return lists[0];
  }

  int size = lists.size()/2;
  vector<ListNode*> l1(lists.begin(), lists.begin()+size);
  vector<ListNode*> l2(lists.begin()+size, lists.end());

  ListNode *h1 = mergeKLists(l1);
  ListNode *h2 = mergeKLists(l2);

  ListNode *p1 = h1, *p2 = h2;
  ListNode *dummy = new ListNode();
  ListNode *p = dummy;
  while (p1 != nullptr && p2 != nullptr) {
    if (p1->val < p2->val) {
      p->next = new ListNode(p1->val);
      p1 = p1->next;
    } else {
      p->next = new ListNode(p2->val);
      p2 = p2->next;
    }
    p = p->next;
  }

  while (p1 != nullptr) {
    p->next = new ListNode(p1->val);
    p1 = p1->next;
    p = p->next;
  }

  while (p2 != nullptr) {
    p->next = new ListNode(p2->val);
    p2 = p2->next;
    p = p->next;
  }

  return dummy->next;
}

int main() {
  ListNode *h1 = new ListNode(1);
  ListNode *p1 = h1;
  p1->next = new ListNode(4); p1 = p1->next;
  p1->next = new ListNode(5); p1 = p1->next;

  ListNode *h2 = new ListNode(1);
  ListNode *p2 = h2;
  p2->next = new ListNode(3); p2 = p2->next;
  p2->next = new ListNode(4); p2 = p2->next;

  ListNode *h3 = new ListNode(2);
  ListNode *p3 = h3;
  p3->next = new ListNode(6); p3 = p3->next;

  vector<ListNode*> v{h1, h2, h3};
  ListNode *res = mergeKLists(v);
  while (res != nullptr) {
    cout << res->val << " ";
    res = res->next;
  }

  cout << endl;
  return 0;
}