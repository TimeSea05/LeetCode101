#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>{0, 0});

  dp[0][0] = 0, dp[0][1] = -prices[0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    if (i < 2) dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    else dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
  }

  return dp[n-1][0];
}

int main() {
  vector<int> prices{1,2,3,0,2};
  cout << maxProfit(prices) << endl;
  return 0;
}