#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
  int m = s.size(), n = p.size();
  vector<vector<bool>> dp(n+1, vector<bool>(m+1));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (p[i-1] == '.') {
        if (j != 0) {
          dp[i][j] = dp[i-1][j-1] || dp[i][j];
        }
      } else if (p[i-1] == '*') {
        dp[i][j] = dp[i-2][j] || dp[i-1][j] || dp[i][j];

        int k = j;
        if (k > 0) {
          while (k <= m && ((s[k-1] == p[i-2] && dp[i][j]) || (p[i-2] == '.' && dp[i][j]))) {
            dp[i][k] = true;
            k++;
          }
        }
        if (j != k) j = k-1;
      } else {
        if (j != 0 && p[i-1] == s[j-1]) {
          dp[i][j] = dp[i-1][j-1] || dp[i][j];
        }
      }
    }
  }

  return dp[n][m];
}

int main() {
  if (isMatch("bbcacbabbcbaaccabc", "b*a*a*.c*bb*b*.*.*")) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
