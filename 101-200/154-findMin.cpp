#include <iostream>
#include <vector>
using namespace std;

int findMinRange(vector<int>& nums, int l, int r) {
  int mid = (l + r) / 2;
  while (l <= r) {
    mid = (l + r) / 2;
    int mid_left = (mid == 0) ? r : mid - 1;
    if (nums[mid] < nums[mid_left]) {
      return nums[mid];
    }

    if (nums[mid] > nums[r]) {
      l = mid + 1;
    } else if (nums[mid] < nums[r]) {
      r = mid - 1;
    } else {
      return min(findMinRange(nums, l, mid - 1), findMinRange(nums, mid + 1, r));
    }
  }

  return nums[mid];
}

int findMin(vector<int>& nums) {
  return findMinRange(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums{2, 2, 2, 2, 2};
  cout << findMin(nums) << endl;
  return 0;
}