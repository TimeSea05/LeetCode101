#include <iostream>
#include <vector>
using namespace std;

// brute-force: time limit exceeded
int maxProfitBF(vector<int>& prices) {
  int max = 0;
  for (int i = 0; i < prices.size() - 1; i++) {
    for (int j = i+1; j < prices.size(); j++) {
      if (prices[j] - prices[i] > max) {
        max = prices[j] - prices[i];
      }
    }
  }

  return max;
}

// greedy
int maxProfitGreedy(vector<int>& prices) {
  int max = 0;
  int low = INT32_MAX;

  for (int i = 0; i < prices.size(); i++) {
    if (prices[i] < low) {
      low = prices[i];
    }

    if (prices[i] - low > max) {
      max = prices[i] - low;
    } 
  }

  return max;
}

// DP
int maxProfit(vector<int>& prices) {
  // dp[i][0]: max profit without holding the shares
  // dp[i][1]: max profit holding the shares
  vector<vector<int>> dp(prices.size(), vector<int>{0, 0});
  dp[0][0] = 0, dp[0][1] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1],  -prices[i]);
  }

  return dp.back()[0];
}


int main() {
  vector<int> v{7,1,5,3,6,4};
  cout << maxProfit(v) << endl;
  return 0;
}