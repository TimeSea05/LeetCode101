#include <vector>
#include <iostream>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
  int n = prices.size();
  // 第几天 / 0卖出 1 持有 / 第几次买入
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1)));

  for (int i = 1; i <= k; i++) {
    dp[0][0][i] = 0, dp[0][1][i] = -prices[0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][0][j] = max(dp[i-1][0][j], dp[i-1][1][j] + prices[i]);
      dp[i][1][j] = max(dp[i-1][1][j], dp[i-1][0][j-1] - prices[i]);
    }
  }

  return dp[n-1][0][k];
}

int main() {
  vector<int> prices{2,4,1};
  int k = 2;
  cout << maxProfit(k, prices) << endl;
  return 0;
}