#include <vector>
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

void dfs(int n, int k, vector<vector<int>>& res, vector<int>& temp, int start) {
  if (k == 0) {
    res.push_back(vector<int>(temp));
    return;
  }

  for (int i = start; i <= n-k+1; i++) {
    temp.push_back(i);
    dfs(n, k-1, res, temp, i+1);
    temp.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> res;
  vector<int> temp;

  dfs(n, k, res, temp, 1);

  return res;
}

int main() {
  vector<vector<int>> res = combine(3, 2);
  print2DVector(res);
  return 0;
}