#include "../lib/libleetcode.h"

ListNode *reverseList(ListNode *head) {
  ListNode dummy(0);
  dummy.next = head;

  ListNode *ptr = head->next;
  head->next = nullptr;
  while (ptr != nullptr) {
    ListNode *oldNext = dummy.next;
    dummy.next = ptr;
    ptr = ptr->next;
    dummy.next->next = oldNext;
  }

  return dummy.next;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  if (k == 1) {
    return head;
  }
  ListNode dummy(0);
  dummy.next = head;
  ListNode *before = &dummy;

  int num = 0;
  ListNode *ptr = before;
  while (before->next != nullptr) {
    while (num != k && ptr != nullptr) {
      ptr = ptr->next;
      num++;
    }
    if (ptr == nullptr) {
      break;
    }

    ListNode *oldHead = before->next;
    ListNode *oldTail = ptr;
    ListNode *oldTailNext = ptr->next;
    oldTail->next = nullptr;

    before->next = reverseList(oldHead);
    oldHead->next = oldTailNext;

    before = oldHead;
    ptr = before;
    num = 0;
  }

  return dummy.next;
}

int main() {
  std::vector<int> arr{1,2,3,4,5,6};
  ListNode *head = constructList(arr);

  ListNode *reversed = reverseKGroup(head, 2);
  printList(reversed);
}