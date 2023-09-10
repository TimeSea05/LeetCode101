#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  if (nums.size() == 0) {
    return vector<int>{-1, -1};
  }

  int i = 0, j = nums.size() - 1;
  int mid = (i + j) / 2;

  while (i <= j) {
    mid = (i + j) / 2;
    if (nums[mid] < target) {
      i = mid + 1;
    } else if (nums[mid] > target) {
      j = mid - 1;
    } else {
      break;
    }
  }

  if (nums[mid] == target) {
    int l = mid, r = mid;
    while (l >= 0 && nums[l] == target) l--;
    while (r < nums.size() && nums[r] == target) r++;
    return vector<int>{l+1, r-1};
  }

  return vector<int>{-1, -1};
}

int main() {
  vector<int> nums{1};
  int target = 1;
  vector<int> range = searchRange(nums, target);
  cout << range[0] << " " << range[1] << endl;
  return 0;
}