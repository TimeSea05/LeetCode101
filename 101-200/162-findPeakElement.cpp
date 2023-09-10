#include <vector>
#include <climits>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int getVector(vector<int>& nums, int idx) {
  if (idx == -1 || idx == nums.size()) {
    return -INT_MAX;
  }
  return nums[idx];
}

int findPeakElement(vector<int>& nums) {
  int l = 0, r = nums.size()-1;
  if (nums[l] > getVector(nums, l+1)) {
    return l;
  }
  if (nums[r] > getVector(nums, r-1)) {
    return r;
  }

  while (l < r) {
    int mid = (l+r)/2;
    bool overLeft = getVector(nums, mid) > getVector(nums, mid-1);
    bool overRight = getVector(nums, mid) > getVector(nums, mid+1);
    if (overLeft && overRight) {
      return mid;
    } else if (!overLeft) {
      r = mid-1;
    } else {  // !overRight
      l = mid+1;
    }
  }

  return l;
}

int main() {
  vector<int> nums{1,2,1,3,5,6,4};
  cout << findPeakElement(nums) << endl;
}