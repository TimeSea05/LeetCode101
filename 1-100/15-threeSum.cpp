#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  map<string, bool> m;

  for (int i = 0; i < nums.size() - 2; i++) {
    int sum = -nums[i];
    int j = i+1, k = nums.size() - 1;

    while (j < k) {
      if (nums[j] + nums[k] > sum) {
        k--;
      } else if (nums[j] + nums[k] < sum) {
        j++;
      } else {
        char buf[64];
        sprintf(buf, "%d %d %d", nums[i], nums[j], nums[k]);
        string str = buf;
        if (!m[str]) {
          res.push_back(vector<int>{nums[i], nums[j], nums[k]});
          m[str] = true;
        }
        j++, k--;
      }
    }
  }

  return res;
}

int main() {
  vector<int> nums{0,0,0};
  vector<vector<int>> res = threeSum(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}