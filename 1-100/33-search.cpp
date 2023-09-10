#include <iostream>
#include <vector>
using namespace std;

/*
  旋转后的数组，从中间分开
  如果中间的数大于最右边的数，那么左边是有序的
  如果中间的数小于最右边的数，那么右边是有序的
  在有序的半段里用首尾两个数组来判断目标值是否在这一区域
*/

int search(vector<int>& nums, int target) {
  int i = 0, j = nums.size() - 1;
  int mid = (i + j) / 2;

  while (i <= j) {
    mid = (i + j) / 2;
    if (nums[mid] == target) {
      return mid;
    }

    if (nums[mid] > nums[j]) {  // 左边有序
      if (nums[i] > target || nums[mid] < target) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    } else if (nums[mid] < nums[j]) { // 右边有序
      if (nums[mid] > target || nums[j] < target) {
        j = mid - 1;
      } else {
        i = mid + 1;
      }
    } else {
      break;
    }
  }

  return -1;
}

int main() {
  vector<int> nums{1};
  int target = 0;

  cout << search(nums, target) << endl;
  return 0;
}