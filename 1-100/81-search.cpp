#include <cstdio>
#include <vector>
using namespace std;

/*
  比较中间和右边
  中间和右边相同      2 ... 2
  如果右边是无序的，那就是类似于    2 100 -1 1 2 这种，那左边肯定是有序的，而且全是2
  就比如 2 2 2 2 2 2 100 -1 1 2

  如果左边是无序的，那右边就是有序的，右边全是 2 2 2 2
  左边的话，2 100 2 2 2 2 2
  那就两个数组都看一下，就是用递归
*/

bool searchRange(vector<int>& nums, int target, int l, int r) {
  int mid = (l + r) / 2;

  while (l <= r) {
    mid = (l + r) / 2;
    if (nums[mid] == target) return true;

    if (nums[mid] > nums[r]) {
      if (nums[l] > target || nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid -1;
      }
    } else if (nums[mid] < nums[r]) {
      if (nums[mid] > target || nums[r] < target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else {
      return searchRange(nums, target, l, mid - 1) || searchRange(nums, target, mid + 1, r);
    }
  }

  return false;
}

bool search(vector<int>& nums, int target) {
  return searchRange(nums, target, 0, nums.size() - 1);
}

int main() {
  vector<int> nums{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
  int target = 2;

  if (search(nums, target)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}

