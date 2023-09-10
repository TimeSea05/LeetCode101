#include <cstdio>
#include <vector>
using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode* constructList(const vector<int>& numbers, int pos) {
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

bool hasCycle(ListNode *head) {
  ListNode *fast = head, *slow = head;

  while (1) {
    if (fast == NULL) return false;
    fast = fast->next;
    if (fast == NULL) return false;
    fast = fast->next;

    slow = slow->next;
    if (slow == fast) return true;
  }

  return false;
}

int main() {
  vector<int> head{};
  int pos = -1;

  ListNode *list = constructList(head, pos);
  if (hasCycle(list)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}