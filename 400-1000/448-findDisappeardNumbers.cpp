#include "../lib/libleetcode.h"

/*
[4,3,2,7,8,2,3,1]
[7,3,2,-4,8,2,3,1]
[3,3,2,-4,8,2,-7,1]
[2,3,-3,-4,8,2,-7,1]
[3,-2,-3,-4,8,2,-7,1]
[3,-2,-3,-4,1,2,-7,-8]
[-1,-2,-3,-4,3,2,-7,-8]
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
  int n = nums.size();
  int i = 0;
  while (i < n) {
    int old = nums[i]-1;
    if (nums[i] > 0 && nums[old] > 0) {
      std::swap(nums[i], nums[nums[i]-1]);
      nums[old] = -nums[old];
      continue;
    }
    i++;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (nums[i] > 0) {
      ans.push_back(i+1);
    }
  }

  return ans;
}

int main() {
  vector<int> nums{1,1,2,4};
  vector<int> v = findDisappearedNumbers(nums);
  printVector(v);
  return 0;
}