#include <vector>
#include <iostream>
using namespace std;

const int ARITH_SLICE_START = INT32_MAX;

int numberOfArithmeticSlices(vector<int>& nums) {
  if (nums.size() < 3) return 0;

  vector<int> diffs(nums.size());
  vector<int> lens(nums.size());
  vector<int> arithNums(nums.size());

  diffs[0] = ARITH_SLICE_START, diffs[1] = nums[1]-nums[0];
  lens[0] = 1, lens[1] = 1;
  if (nums[1] - nums[0] == nums[2] - nums[1]) {
    lens[1] = 2;
  }
  arithNums[0] = 0, arithNums[1] = 0;

  for (int i = 2; i < nums.size(); i++) {
    int diff = nums[i]-nums[i-1];
    if (diff == diffs[i-1]) {
      diffs[i] = diff;
      lens[i] = lens[i-1]+1;
      arithNums[i] = arithNums[i-1]+lens[i-1]-1;
    } else {
      if (i+1 < nums.size() && diff == nums[i+1]-nums[i]) {
        diffs[i] = diff;
        lens[i] = 2;
      } else {
        diffs[i] = ARITH_SLICE_START;
        lens[i] = 1;
      }
      arithNums[i] = arithNums[i-1];
    }
  }

  return arithNums.back();
}

int main() {
  vector<int> nums{1, 2, 3,4};
  cout << numberOfArithmeticSlices(nums) << endl;
}