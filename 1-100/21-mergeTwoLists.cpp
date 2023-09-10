struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *p = list1, *q = list2;
  ListNode *dummy = new ListNode();
  ListNode *r = dummy;

  while (p != nullptr && q != nullptr) {
    if (p->val > q->val) {
      r->next = new ListNode(q->val);
      q = q->next;
      r = r->next;
    } else {
      r->next = new ListNode(p->val);
      p = p->next;
      r = r->next;
    }
  }

  while (p != nullptr) {
    r->next = new ListNode(p->val);
    p = p->next, r = r->next;
  }

  while (q != nullptr) {
    r->next = new ListNode(q->val);
    q = q->next, r = r->next;
  }

  return dummy->next;
}