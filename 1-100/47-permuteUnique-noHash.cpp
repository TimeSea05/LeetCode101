#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& temp, vector<vector<int>>& res, int depth) {
  if (depth == nums.size()) {
    res.push_back(vector<int>(temp));
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (visited[i]) continue;
    if (i > 0 && nums[i-1] == nums[i] && !visited[i-1]) {
      continue;
    }

    temp.push_back(nums[i]);
    visited[i] = true;
    depth++;

    dfs(nums, visited, temp, res, depth);

    depth--;
    visited[i] = false;
    temp.pop_back();
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<bool> visited(nums.size());
  vector<vector<int>> res;
  vector<int> temp;
  int depth = 0;

  dfs(nums, visited, temp, res, depth);
  return res;
}

void print2DVector(vector<vector<int>>& v) {
  printf("[");
  for (int i = 0; i < v.size(); i++) {
    if (i != 0) printf(",");
    printf("[");
    for (int j = 0; j < v[i].size(); j++) {
      if (j != 0) printf(",");
      printf("%d", v[i][j]);
    }
    printf("]");
  }
  printf("]\n");
}

int main() {
  vector<int> nums{1, 1, 2};
  auto res = permuteUnique(nums);
  print2DVector(res);

  return 0;
}
