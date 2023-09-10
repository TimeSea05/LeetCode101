#include <vector>
#include <iostream>
using namespace std;

int m, n;

int minPathSum(vector<vector<int>>& grid) {
  m = grid.size(), n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
  dp[0][0] = grid[0][0];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
    }
  }

  return dp[m-1][n-1];
}

int main() {
  vector<vector<int>> grid{{1,2,3},{4,5,6}};
  cout << minPathSum(grid) << endl;
  return 0;
}