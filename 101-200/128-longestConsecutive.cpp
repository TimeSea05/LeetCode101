#include <vector>
#include <iostream>
#include <map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  map<int, int> hash;
  int maxLen = 0, size = nums.size();

  for (int i = 0; i < size; i++) {
    int num = nums[i];
    if (hash[num] == 0) {
      int lLen = hash[num-1], rLen = hash[num+1];
      if (lLen != 0 && rLen != 0) {
        int len = lLen + 1 + rLen;
        hash[num-lLen] = len, hash[num+rLen] = len;
        hash[num] = 1;
        maxLen = max(maxLen, len);
      } else if (lLen != 0) {
        int len = lLen + 1;
        hash[num-lLen] = len; hash[num] = len;
        maxLen = max(maxLen, len);
      } else if (rLen != 0) {
        int len = rLen + 1;
        hash[num+rLen] = len; hash[num] = len;
        maxLen = max(maxLen, len);
      } else {
        hash[num] = 1;
        maxLen = max(maxLen, 1);
      }
    }
  }

  return maxLen;
}

int main() {
  vector<int> nums{0,3,7,2,5,8,4,6,0,1};
  cout << longestConsecutive(nums) << endl;
}
