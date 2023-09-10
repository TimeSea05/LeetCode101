#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
  int ans = 0;
  for (auto i: nums) {
    ans ^= i;
  }

  return ans;
}

int main() {
  vector<int> nums{4,1,2,1,2};
  cout << singleNumber(nums) << endl;
}
