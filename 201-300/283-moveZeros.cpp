#include <iostream>
#include <vector>
using std::vector;

void moveZeroes(vector<int>& nums) {
  int n = nums.size();

  int l = 0;
  while (l < n && nums[l] != 0) {
    l++;
  }
  if (l == n-1 || l == n) {
    return;
  }

  int r = l;
  while (r+1 < n && nums[r+1] == 0) {
    r++;
  }
  if (r == n-1) {
    return;
  }

  for (int i = r+1; i < n; i++) {
    if (nums[i] != 0) {
      std::swap(nums[i], nums[l]);
      l++;
    }
    r++;

    if (r == n-1) {
      break;
    }
  }
}

int main() {
  vector<int> nums{0};
  moveZeroes(nums);

  for (auto i: nums) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  return 0;
}
