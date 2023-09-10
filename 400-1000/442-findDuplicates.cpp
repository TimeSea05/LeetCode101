#include <iostream>
#include <vector>
using std::vector;

// vector<int> findDuplicates(vector<int>& nums) {
//   int n = nums.size();
//   vector<int> duplicates;

//   for (int i = 0; i < n; i++) {
//     while (nums[i] != nums[nums[i]-1]) {
//       std::swap(nums[i], nums[nums[i]-1]);
//     }
//   }

//   for (int i = 0; i < n; i++) {
//     if (nums[i]-1 != i) {
//       duplicates.push_back(nums[i]);
//     }
//   }

//   return duplicates;
// }

vector<int> findDuplicates(vector<int>& nums) {
  int n = nums.size();
  vector<int> duplicates;

  for (int i = 0; i < n; i++) {
    int abs = nums[i] > 0 ? nums[i] : -nums[i];
    if (nums[abs-1] > 0) {
      nums[abs-1] = -nums[abs-1];
    } else {
      duplicates.push_back(abs);
    }
  }

  return duplicates;
}

int main() {
  vector<int> nums{4,3,2,7,8,2,3,1};
  auto v = findDuplicates(nums);
  for (auto i: v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}