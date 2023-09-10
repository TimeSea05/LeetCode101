#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

bool canJump(vector<int>& nums) {
  int size = nums.size();
  vector<int> jumps(size);
  jumps[0] = true;

  for (int i = 0; i < size; i++) {
    if (!jumps[i]) return false;

    if (i + nums[i] >= size-1) {
      return true;
    }

    for (int j = 1; j <= nums[i]; j++) {
      jumps[i+j] = 1;
    }
  }
  return false;
}

int main() {
  vector<int> nums{2,3,1,1,4};
  cout << canJump(nums) << endl;
  return 0;
}
