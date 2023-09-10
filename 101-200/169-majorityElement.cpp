#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
  int size = nums.size();
  int candidate = nums[0], count = 1;

  for (int i = 1; i < size; i++) {
    if (nums[i] != candidate) {
      count--;
      if (count == 0) {
        candidate = nums[i];
        count = 1;
      }
    } else {
      count++;
    }
  }

  return candidate;
}

int main() {
  vector<int> nums{2,2,1,1,1,2,2};
  cout << majorityElement(nums) << endl;
  return 0;
}
