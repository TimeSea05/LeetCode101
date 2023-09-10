#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrefix(const string &prefix, const string &str) {
  int prefixLen = prefix.size();
  for (int i = 0; i < prefixLen; i++) {
    if (prefix[i] != str[i]) {
      return false;
    }
  }
  return true;
}

bool isSuffix(const string& suffix, const string &str) {
  int suffixLen = suffix.size();
  int strLen = str.size();
  if (suffixLen > strLen) {
    return false;
  }

  for (int i = 0; i < suffixLen; i++) {
    if (suffix[suffixLen-i-1] != str[strLen-i-1]) {
      return false;
    }
  }

  return true;
}

bool wordBreak(string s, vector<string>& wordDict) {
  vector<bool> dp(s.size()+1);
  dp[0] = true;

  for (int i = 1; i < int(s.size()+1); i++) {
    for (string &word: wordDict) {
      if (i >= int(word.size()) && dp[i - word.size()]) {
        dp[i] = isSuffix(word, s.substr(0, i));
      }
      if (dp[i]) break;
    }
  }

  return dp.back();
}

int main() {
  string s = "b";
  vector<string> wordDict{"a"};
  cout << (wordBreak(s, wordDict) ? "true" : "false") << endl;
}
