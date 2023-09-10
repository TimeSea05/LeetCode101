#include <vector>
#include <cstdio>
#include <algorithm>
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

void dfs(vector<int>& candidates, vector<bool>& visited, vector<int>& solution, vector<vector<int>>& res, int sum, int target, int start) {
  if (sum >= target) {
    if (sum == target) res.push_back(vector<int>(solution));
    return;
  }

  for (int i = start; i < candidates.size(); i++) {
    if (visited[i]) continue;
    if (i > 0 && candidates[i] == candidates[i-1] && !visited[i-1]) continue;

    visited[i] = true;
    solution.push_back(candidates[i]);

    dfs(candidates, visited, solution, res, sum+candidates[i], target, i+1);

    solution.pop_back();
    visited[i] = false;
  }
}

vector<vector<int>> conbinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<bool> visited(candidates.size());
  vector<int> solution;
  vector<vector<int>> res;

  dfs(candidates, visited, solution, res, 0, target, 0);
  return res;
}

int main() {
  vector<int> candidates{1,1,6,6};
  auto res = conbinationSum2(candidates, 7);
  print2DVector(res);
}