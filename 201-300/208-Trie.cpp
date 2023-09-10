#include <cstring>
#include <iostream>
#include <string>
using std::string;

class Trie {
private:
  static const int SIZE = 26;
  struct Node {
    bool isKey = false;
    Node *arr[SIZE] = {nullptr};
  };

  Node root;
public:
  Trie() {}

  void insert(string word) {
    Node *node = &root;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (node->arr[idx] == nullptr) {
        node->arr[idx] = new Node;
      }
      node = node->arr[idx];
    }

    node->isKey = true;
  }

  bool search(string word) {
    Node *node = &root;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (node->arr[idx] == nullptr) {
        return false;
      }
      node = node->arr[idx];
    }

    return node->isKey;
  }

  bool startsWith(string prefix) {
    Node *node = &root;
    for (int i = 0; i < prefix.size(); i++) {
      int idx = prefix[i] - 'a';
      if (node->arr[idx] == nullptr) {
        return false;
      }
      node = node->arr[idx];
    }

    return true;
  }
};

void check(bool t) {
  std::cout << (t ? "true" : "false") << std::endl;
}

int main() {
  Trie trie;
  trie.insert("apple");
  check(trie.search("apple"));
  check(trie.search("app"));
  check(trie.startsWith("app"));
  trie.insert("app");
  check(trie.search("app"));
}
