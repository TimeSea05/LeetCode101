#include <iostream>
#include <vector>
using namespace std;

// 1 1 2 2 3 3 4 8 8
// mid = 4 i = 0, j = 8

int singleNonDuplicate(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];
  
  int i = 0, j = nums.size() - 1;
  int mid = (i + j) / 2;

  while (i < j) {
    if (nums[mid] == nums[mid-1]) {
      if ((mid - i) % 2) i = mid + 1;
      else j = mid - 2;
    } else if (nums[mid] == nums[mid + 1]) {
      if ((mid - i) % 2) j = mid - 1;
      else i = mid + 2; 
    } else {
      return nums[mid];
    }

    mid = (i + j) / 2;
  }

  return nums[mid];
}

int main() {
  vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
  cout << singleNonDuplicate(nums) << endl;
  return 0;
}