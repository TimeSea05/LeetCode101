#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

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

void dfs(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& res, vector<int>& temp, int depth) {
  if (depth == nums.size()) {
    res.push_back(vector<int>(temp));
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (visited[i]) continue;

    visited[i] = true;
    temp.push_back(nums[i]);
    depth++;

    dfs(nums, visited, res, temp, depth);

    depth--;
    temp.pop_back();
    visited[i] = false;
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<bool> visited(nums.size());
  vector<vector<int>> res;
  vector<int> temp;
  int depth = 0;

  dfs(nums, visited, res, temp, depth);
  return res;
}

int main() {
  vector<int> nums{0,1};
  vector<vector<int>> perm = permute(nums);
  print2DVector(perm);
  return 0;
}
