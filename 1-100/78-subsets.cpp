#include <vector>
#include <cstdio>
using std::vector;

vector<vector<int>> subsetsRange(vector<int>& nums, int idx) {
  int number = nums[idx];
  if (idx == nums.size()-1) {
    return vector<vector<int>>{{}, {number}};
  }

  vector<vector<int>> res = subsetsRange(nums, idx+1);
  int size = res.size();
  res.insert(res.begin(), res.begin(), res.end());

  for (int i = 0; i < size; i++) {
    res[i].push_back(number);
  }
  return res;
}

vector<vector<int>> subsets(vector<int>& nums) {
  return subsetsRange(nums, 0);
}

void printVector(vector<int>& nums) {
  printf("[");
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) printf(",");
    printf("%d", nums[i]);
  }
  printf("]\n");
}

int main() {
  vector<int> nums{1,2,3};
  auto res = subsets(nums);
  for (int i = 0; i < res.size(); i++) {
    printVector(res[i]);
  }
}