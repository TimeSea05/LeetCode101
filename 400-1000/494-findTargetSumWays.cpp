#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
  int n = nums.size();
  int sum = accumulate(nums.begin(), nums.end(), 0);

  if (target > sum || target < -sum) {
    return 0;
  }

  int offset = sum;
  vector<vector<int>> dp(n+1, vector<int>(offset * 2 + 1));
  dp[0][offset] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = -offset; j <= offset; j++) {
      if (offset + j - nums[i-1] >= 0) {
        dp[i][offset+j] += dp[i-1][offset+j-nums[i-1]];
      }
      if (offset + j + nums[i-1] <= 2 * sum) {
        dp[i][offset+j] += dp[i-1][offset+j+nums[i-1]];
      }
    }
  }

  return dp[n][offset+target];
}

int main() {
  vector<int> nums{1};
  cout << findTargetSumWays(nums, 1) << endl;
  return 0;
}