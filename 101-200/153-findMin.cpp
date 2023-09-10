#include <vector>
#include <iostream>
using namespace std;

int findMin(vector<int>& nums) {
  int i = 0, j = nums.size() - 1;
  int mid = (i + j) / 2;

  while (i <= j) {
    mid = (i + j) / 2;
    int mid_left = (mid == 0) ? j : mid - 1;
    if (nums[mid] < nums[mid_left]) {
      return nums[mid];
    }

    if (nums[mid] > nums[j]) {
      i = mid + 1;
    } else if (nums[mid] < nums[j]) {
      j = mid - 1;
    } else {
      break;
    }
  }

  return nums[mid];
}

int main() {
  vector<int> nums{11,13,15,17};
  cout << findMin(nums) << endl;
  return 0;
}