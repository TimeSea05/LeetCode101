#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
  vector<int> balloons{1};
  balloons.insert(balloons.end(), nums.begin(), nums.end());
  balloons.push_back(1);

  int n = balloons.size();
  vector<vector<int>> dp(n, vector<int>(n));

  for (int i = 2; i < n; i++) {
    for (int j = i-2; j >= 0; j--) {
      int maxCoinsNum = 0;
      for (int k = j+1; k < i; k++) {
        int curCoinsNum = balloons[i] * balloons[k] * balloons[j];
        curCoinsNum += (dp[j][k] + dp[k][i]);
        maxCoinsNum = max(maxCoinsNum, curCoinsNum);
      }
      dp[j][i] = maxCoinsNum;
    }
  }

  return dp[0][n-1];
}

int main() {
  vector<int> nums{3,1,5,8};
  cout << maxCoins(nums) << endl;
  return 0;
}