#include <iostream>
#include <vector>
using namespace std;

/*
  dp[i]: 前i个数中，包含第i个数的连续子数组的最大和
  if nums[i] > 0, then 
*/

int maxSubArray(vector<int>& nums) {
  // check if all elements in array `nums` are negative
  bool isAllNegative = true;
  for (auto ele: nums) {
    if (ele >= 0) {
      isAllNegative = false;
      break;
    }
  }

  if (isAllNegative) {
    int max = nums[0];
    for (auto ele: nums) {
      if (ele > max) max = ele;
    }
    return max;
  }

  int n = nums.size();
  int maxSum = 0;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + nums[i] < 0) {
      sum = 0;
      continue;
    }
    sum += nums[i];
    maxSum = max(maxSum, sum);
  }

  return maxSum;
}

int main() {
  vector<int> nums{-1,-2,-3,-4,0};
  cout << maxSubArray(nums) << endl;
  return 0;
}