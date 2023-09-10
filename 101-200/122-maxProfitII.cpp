#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
  // dp[i][0]: max profit without holding the shares
  // dp[i][1]: max profit holding the shares
  vector<vector<int>> dp(prices.size(), vector<int>{0, 0});
  dp[0][0] = 0, dp[0][1] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
  }

  return dp.back()[0];
}

int main() {
  vector<int> prices{7,1, 5, 3, 6, 4};
  cout << maxProfit(prices) << endl;
  return 0;
}