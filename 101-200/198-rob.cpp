#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];

  vector<int> money(nums.size());
  money[0] = nums[0], money[1] = max(nums[0], nums[1]);
  for (int i = 2; i < nums.size(); i++) {
    money[i] = max(money[i-2] + nums[i], money[i-1]);
  }

  int max = 0;
  for (int i = 0; i < money.size(); i++) {
    if (max < money[i]) {
      max = money[i];
    }
  }

  return max;
}

int main() {
  vector<int> nums{2,7,9,3,1};
  cout << rob(nums) << endl;
  return 0;
}