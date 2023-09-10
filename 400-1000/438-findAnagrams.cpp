#include <vector>
#include <string>
#include <cstring>
#include "../lib/libleetcode.h"

using std::vector;
using std::string;

bool checkArrayEquality(int a[], int b[], int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

vector<int> findAnagrams(string s, string p) {
  int slen = s.size(), plen = p.size();
  vector<int> ans;
  if (slen < plen) {
    return ans;
  }

  int sCountMap[26], pCountMap[26];
  memset(sCountMap, 0, 26*sizeof(int));
  memset(pCountMap, 0, 26*sizeof(int));

  for (int i = 0; i < plen; i++) {
    pCountMap[p[i]-'a']++;
    sCountMap[s[i]-'a']++;
  }

  if (checkArrayEquality(sCountMap, pCountMap, 26)) {
    ans.push_back(0);
  }

  for (int j = plen; j < slen; j++) {
    sCountMap[s[j]-'a']++, sCountMap[s[j-plen]-'a']--;
    if (checkArrayEquality(sCountMap, pCountMap, 26)) {
      ans.push_back(j+1-plen);
    }
  }

  return ans;
}

int main() {
  auto v = findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa");
  printVector(v);
  return 0;
}