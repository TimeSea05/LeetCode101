#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  ListNode dummy; 
  dummy.next = head;
  ListNode *ptr = head->next;
  head->next = nullptr;

  while (ptr != nullptr) {
    ListNode *oldHead = dummy.next;
    ListNode *next = ptr->next;

    dummy.next = ptr; ptr->next = oldHead;
    ptr = next;
  }

  return dummy.next;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *reversed = reverseList(head);
  while (reversed != nullptr) {
    std::cout << reversed->val << " ";
    reversed = reversed->next;
  }
  std::cout << std::endl;

  return 0;
}