#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
  int i = nums.size()-2, j = i+1;
  while (i >= 0 && nums[i] >= nums[i+1]) {
    i--;
  }

  if (i == -1) {
    sort(nums.begin(), nums.end());
    return;
  }

  while (j > i && nums[j] <= nums[i]) {
    j--;
  }
  swap(nums[i], nums[j]);
  sort(nums.begin() + i+1, nums.end());
}

int main() {
  vector<int> nums{1,1,5,1,1};
  nextPermutation(nums);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}