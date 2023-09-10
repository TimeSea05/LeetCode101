#include <vector>
#include <iostream>
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


int m, n;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  m = mat.size(), n = mat[0].size();
  vector<vector<int>> dp(m, vector<int>(n, INT16_MAX));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) dp[i][j] = 0;
      else {
        if (i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        if (j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      }
    }
  }

  for (int i = m-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      if (mat[i][j] != 0) {
        if (i+1 < m) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
        if (j+1 < n) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
      }
    }
  }

  return dp;
}

int main() {
  vector<vector<int>> mat{{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
  auto res = updateMatrix(mat);
  print2DVector(res);
}