#include <vector>
#include <iostream>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  vector<long> dp(amount+1, INT32_MAX);
  dp[0] = 0;
  long minCoinsNum = INT32_MAX;

  for (int i = 0; i < n; i++) {
    for (int j = coins[i]; j <= amount; j++) {
      dp[j] = min(dp[j], dp[j-coins[i]] + 1);
    }
    minCoinsNum = min(minCoinsNum, dp[amount]);
  }

  if (minCoinsNum == INT32_MAX) return -1;
  return minCoinsNum;
}

int main() {
  vector<int> coins{1};
  int amount = 0;
  cout << coinChange(coins, amount) << endl;

  return 0;
}
