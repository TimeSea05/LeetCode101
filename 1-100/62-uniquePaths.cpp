#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i > 0) dp[i][j] += dp[i-1][j];
      if (j > 0) dp[i][j] += dp[i][j-1];
    }
  }

  return dp[m-1][n-1];
}

int main() {
  cout << uniquePaths(7, 3) << endl;
  return 0;
}