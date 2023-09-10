#include <stdio.h>
#include <vector>
using namespace std;

/*
  思路：先找到下降处，比如在[4, 2, 3]中，下降处为4
  然后将下降处的两个数变成一样的，在这个例子中，有两种情况
  [2, 2, 3], [4, 4, 3]
  两种情况中只需要有一种满足题意则返回true，两种都不满足题意返回false
*/

bool checkPossibility(vector<int>& nums) {
  if (nums.size() == 1) return true;

  int i = 0;
  for (; i < nums.size() - 1; i++) {
    if (nums[i] > nums[i+1]) break;
  }
  if (i == nums.size() - 1) return true;  

  int small = nums[i+1], big = nums[i];
  int j = 0;

  nums[i] = small;
  for (; j < nums.size() - 1; j++) {
    if (nums[j] > nums[j+1]) break;
  }
  if (j == nums.size() - 1) return true;

  nums[i] = big, nums[i+1] = big;
  for (j = 0; j < nums.size() - 1; j++) {
    if (nums[j] > nums[j+1]) return false;
  }
  return true;
}

int main() {
  vector<int> nums{1, 3};
  bool res = checkPossibility(nums);

  if (res) printf("true\n");
  else printf("false\n");
  return 0;
}