#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

bool canPartition(vector<int>& nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 == 1) return false;

  int target = sum / 2, n = nums.size();
  vector<vector<bool>> dp(n+1, vector<bool>(target+1));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (j < nums[i-1]) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
      }
    }
  }

  return dp[n][target];
}

int main() {
  vector<int> nums{1,5,11,5};
  if (canPartition(nums)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}