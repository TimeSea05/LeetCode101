#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *list) {
  if (list == nullptr || list->next == nullptr) {
    return list;
  }

  ListNode dummy; dummy.next = list;
  ListNode *ptr = list->next;
  dummy.next->next = nullptr;

  while (ptr != nullptr) {
    ListNode *nextPtr = ptr->next;
    ListNode *oldHead = dummy.next;
    dummy.next = ptr; ptr->next = oldHead;
    ptr = nextPtr;
  }

  return dummy.next;
}

bool isPalindrome(ListNode *head) {
  if (head->next == nullptr) {
    return true;
  }

  ListNode dummy;

  ListNode *fast = head->next->next, *slow = head;
  while (fast != nullptr) {
    fast = fast->next;
    if (fast == nullptr) break;
    fast = fast->next;
    slow = slow->next;
  }

  ListNode *mid = slow; ListNode *midNext = mid->next;
  mid->next = nullptr;
  ListNode *l = head, *r = reverseList(midNext);
  ListNode *reversed = r;

  bool flag = true;
  while (l != nullptr && r != nullptr) {
    if (l->val != r->val) {
      flag = false;
      break;
    }
    l = l->next, r = r->next;
  }

  mid->next = reverseList(reversed);
  return flag;
}

void check(bool flag) {
  std::cout << (flag ? "true\n" : "false\n");
}

int main() {
  ListNode *root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(2);
  root->next->next->next = new ListNode(1);
  root->next->next->next->next = new ListNode(1);


  check(isPalindrome(root));
  return 0;
}
