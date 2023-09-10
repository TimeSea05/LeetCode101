#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
  int n = s.size();
  vector<vector<bool>> dp(n, vector<bool>(n));

  int maxLen = 0;
  int l = 0, r = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i <= j; i++) {
      if (i == j) {
        dp[i][j] = true;
      } else if (i == j-1) {
        dp[i][j] = (s[i] == s[j]);
      } else {
        dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
      }

      if (dp[i][j] && maxLen < (j-i+1)) {
        maxLen = j-i+1;
        l = i, r = j;
      }
    }
  }

  return s.substr(l, r-l+1);
}

int main() {
  cout << longestPalindrome("0") << endl;
  return 0;
}