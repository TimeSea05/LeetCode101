#include <map>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct Node {
  int key, val;
  Node *prev, *next;
  Node(): key(0), val(0), prev(nullptr), next(nullptr) {};
  Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}; 
};

void list_insert(Node *prev, Node *node, Node *next) {
  node->prev = prev, node->next = next;
  prev->next = node, next->prev = node;
}

void list_insert_head(Node *queue, Node *node) {
  list_insert(queue, node, queue->next);
}

void list_insert_tail(Node *queue, Node *node) {
  list_insert(queue->prev, node, queue);
}

void list_delete(Node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

class LRUCache {
private:
  int capacity;
  int count;
  Node queue;
  std::map<int, Node*> cache;

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    queue.prev = &queue; queue.next = &queue;
  }

  int get(int key) {
    Node *valNode = cache[key];
    if (valNode == nullptr) {
      return -1;
    }
    list_delete(valNode);
    list_insert_head(&queue, valNode);

    return valNode->val;
  }

  void put(int key, int value) {
    // check if `key` is already in LRUCache
    if (cache[key] != nullptr) {
      Node *node = cache[key];
      node->val = value;
      list_delete(node);
      list_insert_head(&queue, node);
      return;
    }

    // `key` is not in LRUCache
    if (count < capacity) {
      count++;
      Node *newNode = new Node(key, value);
      cache[key] = newNode;
      list_insert_head(&queue, newNode);
    } else {
      // delete tail
      Node *tail = queue.prev;
      int deletedKey = tail->key;
      list_delete(tail); delete tail;
      cache[deletedKey] = nullptr;

      // insert new node to head
      Node *newNode = new Node(key, value);
      cache[key] = newNode;
      list_insert_head(&queue, newNode);
    }
  }
};

int main() {
  LRUCache lruCache(2);
  lruCache.put(2, 1);
  lruCache.put(1, 1);
  lruCache.put(2, 3);
  lruCache.put(4, 1);
  cout << lruCache.get(1) << endl;
  cout << lruCache.get(2) << endl;
}