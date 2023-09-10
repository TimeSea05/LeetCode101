#include <iostream>
#include <cstdint>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

class LFUCache {
private:
  struct Node {
    Node *prev, *next;
    int key;
    int val;
    int freq;

    Node(): prev(this), next(this), key(0), val(0), freq(0) {}
    Node(int key, int val) {
      this->prev = this->next = nullptr;
      this->key = key, this->val = val;
      this->freq = 1;
    }
  };

  int capacity;
  int count;
  int minFreq;
  Node nodeHashQueue;
  unordered_map<int, Node*> nodeHash;
  unordered_map<int, Node> freqQueueHash;

  void listInsert(Node *prev, Node *next, Node *node) {
    node->prev = prev; node->next = next;
    prev->next = node; next->prev = node;
  }

  void listInsertHead(Node *head, Node *node) {
    listInsert(head, head->next, node);
  }

  void listInsertTail(Node *head, Node *node) {
    listInsert(head->prev, head, node);
  }

  void listDelete(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  bool listEmpty(Node *list) {
    return list->prev == list && list->next == list;
  }

public:
  LFUCache(int capacity) {
    this->count = 0;
    this->capacity = capacity;

    nodeHashQueue.prev = &nodeHashQueue;
    nodeHashQueue.next = &nodeHashQueue;
  }

  int get(int key) {
    if (nodeHash[key] != nullptr) {
      Node *node = nodeHash[key];
      int oldFreq = node->freq; node->freq++;
      listDelete(node);
      listInsertHead(&freqQueueHash[node->freq], node);

      if (oldFreq == minFreq && listEmpty(&freqQueueHash[oldFreq])) {
        minFreq++;
      }
      return node->val;
    }

    return -1;
  }

  void put(int key, int value) {
    if (capacity == 0) return;

    if (nodeHash[key] != nullptr) {
      Node *node = nodeHash[key];
      int oldFreq = node->freq; node->freq++;
      node->val = value;

      listDelete(node);
      listInsertHead(&freqQueueHash[node->freq], node);

      if (oldFreq == minFreq && listEmpty(&freqQueueHash[oldFreq])) {
        minFreq++;
      }
      return;
    }

    if (count == capacity) {
      Node *nodeToDelete = freqQueueHash[minFreq].prev;
      int keyToDelete = nodeToDelete->key;
      listDelete(nodeToDelete); delete nodeToDelete;
      nodeHash[keyToDelete] = nullptr;
    } else {
      count++;
    }
    minFreq = 1;

    Node *node = new Node(key, value);
    nodeHash[key] = node;
    listInsertHead(&freqQueueHash[minFreq], node);
  }
};

int main() {
  LFUCache lfu(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  cout << lfu.get(1) << endl;
  
  lfu.put(3, 3);
  cout << lfu.get(2) << endl;
  cout << lfu.get(3) << endl;

  lfu.put(4, 4);
  cout << lfu.get(1) << endl;
  cout << lfu.get(3) << endl;
  cout << lfu.get(4) << endl;

  return 0;
}
