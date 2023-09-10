#include <iostream>
#include <vector>
using namespace std;


int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3)));
  dp[0][0][1] = 0, dp[0][1][1] = -prices[0];  // 第几天/持有还是未持有/第几次买入
  dp[0][0][2] = 0, dp[0][1][2] = -prices[0];

  for (int i = 1; i < n; i++) {
    dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1] + prices[i]);
    dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][2] + prices[i]);
    dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]);
    dp[i][1][2] = max(dp[i-1][1][2], dp[i-1][0][1] - prices[i]);
  }

  return dp[n-1][0][2];
}

int main() {
  vector<int> prices{14,9,10,12,4,8,1,16};
  // vector<int> prices{1,2,3,4,5,6,7,8,9};
  cout << maxProfit(prices) << endl;
  return 0;
}