#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
  if (s.size() == 0) {
    return 0;
  }

  map<char, int> exists;

  int i = -1, j = -1;
  int size = (int)s.size();
  int maxLen = 0;

  while (j+1 < size) {
    j++;
    char c = s[j];
    if (!exists[c - 'a']) {
      exists[c - 'a'] = true;
    } else {
      while (s[++i] != c) {
        exists[s[i] - 'a'] = false;
      }
    }

    maxLen = max(maxLen, j-i);
  }

  return maxLen;
}

int main() {
  cout << lengthOfLongestSubstring(" ") << endl;
  return 0;
}