#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
  vector<int> dp(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++) {
    for (int j = i-1; j >= 0; j--) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int maxLen = 0;
  for (int i = 0; i < dp.size(); i++) {
    if (maxLen < dp[i]) {
      maxLen = dp[i];
    }
  }

  return maxLen;
}

int main() {
  vector<int> nums{7,7,7,7,7,7,7};
  cout << lengthOfLIS(nums) << endl;
  return 0;
}