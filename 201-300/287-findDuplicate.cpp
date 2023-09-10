#include <iostream>
#include <vector>
using std::vector;

// int findDuplicate(vector<int>& nums) {
//   int slow = nums[0], fast = nums[nums[0]];

//   while (slow != fast) {
//     slow = nums[slow];
//     fast = nums[nums[fast]];
//   }

//   slow = 0;
//   while (slow != fast) {
//     slow = nums[slow];
//     fast = nums[fast];
//   }

//   return slow;
// }

int findDuplicate(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int abs = nums[i] >= 0 ? nums[i] : -nums[i];
    if (nums[abs] > 0) {
      nums[abs] = -nums[abs];
    } else {
      return abs;
    }
  }

  return 0;
}

int main() {
  vector<int> nums{2,2,2,2,2};
  std::cout << findDuplicate(nums) << std::endl;
}