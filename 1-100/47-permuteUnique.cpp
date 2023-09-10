#include <vector>
#include <cstdio>
#include <map>
using namespace std;

const int BASE = 11;

int getHash(vector<int>& vals) {
  int base = 1;
  int hash = 0;

  for (int i = 0; i < vals.size(); i++) {
    hash += vals[i] * base;
    base *= BASE;
  }

  return hash;
}

void dfs(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& res, vector<int>& temp, map<int, bool>& hashes, int depth) {
  if (depth == nums.size()) {
    int hash = getHash(temp);
    if (!hashes[hash]) {
      res.push_back(vector<int>(temp));
      hashes[hash] = true;
    }
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (visited[i]) continue;;

    visited[i] = true;
    temp.push_back(nums[i]);
    depth++;

    dfs(nums, visited, res, temp, hashes, depth);

    depth--;
    temp.pop_back();
    visited[i] = false;
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<bool> visited(nums.size());
  vector<vector<int>> res;
  vector<int> temp;
  map<int, bool> hashes;
  int depth = 0;

  dfs(nums, visited, res, temp, hashes, depth);
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
  vector<int> nums{1, 2, 3};
  auto res = permuteUnique(nums);
  print2DVector(res);

  return 0;
}