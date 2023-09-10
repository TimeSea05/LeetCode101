#include <iostream>
#include <vector>
using namespace std;

vector<int> partitionLabels(string s) {
  vector<int> end(26, -1);
  vector<int> lens;

  for (int i = 0; i < s.size(); i++) {
    end[s[i]-'a'] = i;
  }

  int len = -1, prev = -1;
  for (int i = 0; i < s.size(); i++) {
    if (end[s[i]-'a'] > len) {
      len = end[s[i]-'a'];
    }

    if (i == len) {
      lens.push_back(len - prev);
      prev = len;
    }
  }

  return lens;
}

void printVector(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  string s = "ababcbacadefegdehijhklij";
  printVector(partitionLabels(s));
  return 0;
}