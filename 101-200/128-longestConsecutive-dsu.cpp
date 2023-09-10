#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

unordered_map<int, int> d;
unordered_map<int, int> cnt;
int maxLen = 1;

int find(int x) {
  if (d[x] != x) {
    d[x] = find(d[x]);
  }
  return d[x];
}

void match(int a, int b) {
  int x = find(a);
  int y = find(b);

  if (x != y) {
    d[x] = y;
    cnt[y] += cnt[x];
    maxLen = std::max(maxLen, cnt[y]);
  }
}

int longestConsecutive(vector<int>& nums) {
  if (nums.size() == 0) {
    return 0;
  }

  for (auto i: nums) {
    d[i] = i;
    cnt[i] = 1;
  }

  for (auto i: nums) {
    if (d.count(i-1)) {
      match(i-1, i);
    }
    if (d.count(i+1)) {
      match(i+1, i);
    }
  }

  return maxLen;
}

int main() {
  vector<int> nums{0,3,7,2,5,8,4,6,0,1};
  cout << longestConsecutive(nums) << endl;
}