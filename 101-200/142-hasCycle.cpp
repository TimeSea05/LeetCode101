#include <cstdio>
#include <vector>
using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode* constructList(const vector<int>& numbers, int pos) {
  if (numbers.size() == 0) return NULL;

  vector<ListNode*> nodes(numbers.size());
  for (int i = 0; i < numbers.size(); i++) {
    nodes[i] = new ListNode(numbers[i]);
  }

  for (int i = 0; i < nodes.size() - 1; i++) {
    nodes[i]->next = nodes[i+1];
  }

  if (pos != -1) {
    nodes[nodes.size() - 1]->next = nodes[pos];
  }
  return nodes[0];
}

ListNode* detectCycle(ListNode *head) {
  ListNode *fast = head, *slow = head;

  while (1) {
    if (fast == NULL) return NULL;
    fast = fast->next;
    if (fast == NULL) return NULL;
    fast = fast->next;

    slow = slow->next;
    if (slow == fast) break;
  }

  fast = head;
  while (1) {
    if (fast == slow) return fast;
    fast = fast->next, slow = slow->next;
  }

  return NULL;
}

int main() {
  vector<int> head = {1};
  int pos = -1;
  ListNode *list = constructList(head, pos);

  ListNode *entrance = detectCycle(list);
  if (entrance == NULL) {
    printf("NULL\n");
  } else {
    printf("%d\n", entrance->val);
  }

  return 0;
}