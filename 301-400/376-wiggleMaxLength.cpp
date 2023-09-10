#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
  int n = nums.size();
  if (n < 3) {
    if (n == 1) return 1;
    if (n == 2) {
      if (nums[0] == nums[1]) {
        return 1;
      }
      return 2;
    }
  }

  // dp[i]: 包含nums[i]的最长摆动子序列长度
  vector<int> dp(n, 1);
  vector<int> wiggleIndex(n, -1);

  // initialization
  bool allSameElements = true;
  for (int i = 1; i < n; i++) {
    if (nums[0] != nums[i]) allSameElements = false;
    dp[i] = allSameElements ? 1 : 2;
    if (!allSameElements) {
      wiggleIndex[i] = 0;
    }
  }

  if (nums[0] != nums[1]) {
    wiggleIndex[1] = 0;
  }

  for (int i = 2; i < n; i++) {
    for (int j = 1; j < i; j++) {
      if (wiggleIndex[j] == -1) {
        if (nums[i] != nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
        continue;
      }

      // 判断是否两个差异号
      // 而且两个差都不能是0
      int sub1 = nums[j] - nums[wiggleIndex[j]];
      int sub2 = nums[i] - nums[j];
      if ((sub1 ^ sub2) < 0 && sub1 != 0 && sub2 != 0) {
        dp[i] = max(dp[i], dp[j] + 1);
        wiggleIndex[i] = j;
      }
    }
  }

  int maxLen = 0;
  for (auto len: dp) maxLen = max(len, maxLen);
  return maxLen;
}

int main() {
  vector<int> nums{3,3,3,2,5};
  cout << wiggleMaxLength(nums) << endl;
  return 0;
}