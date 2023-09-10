#include <vector>
#include <iostream>
using namespace std;

// 核心：第一个和最后一个不能同时抢
// 分别计算出两种情况的最大值，然后返回两个结果中最大的
// 0 ~ n-1, 1 ~ n

int rob(vector<int>& nums) {
  if (nums.size() <= 3) {
    int max = 0;
    for (auto i: nums) {
      if (i > max) max = i;
    }

    return max;
  }

  int n = nums.size();
  vector<int> dp1(n), dp2(n);

  dp1[0] = nums[0], dp1[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n-1; i++) {
    dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
  }

  dp2[1] = nums[1], dp2[2] = max(nums[1], nums[2]);
  for (int i = 3; i < n; i++) {
    dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
  }

  return max(dp1[n-2], dp2[n-1]);
}

int main() {
  vector<int> nums{1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
  cout << rob(nums) << endl;
  return 0;
}