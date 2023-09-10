#include <vector>
#include <cstdio>
using namespace std;

void print2DVector(vector<vector<int>>& v) {
  printf("[");
  for (int i = 0; i < v.size(); i++) {
    if (i != 0) printf(",");
    printf("[%d,%d]", v[i][0], v[i][1]);
  }
  printf("]\n");
}

int m, n;

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
  visited[i][j] = true;

  // up
  if (i-1 >= 0 && heights[i-1][j] >= heights[i][j] && !visited[i-1][j]) {
    dfs(heights, visited, i-1, j);
  }
  // down
  if (i+1 < m && heights[i+1][j] >= heights[i][j] && !visited[i+1][j]) {
    dfs(heights, visited, i+1, j);
  }
  // left
  if (j-1 >= 0 && heights[i][j-1] >= heights[i][j] && !visited[i][j-1]) {
    dfs(heights, visited, i, j-1);
  }
  // right
  if (j+1 < n && heights[i][j+1] >= heights[i][j] && !visited[i][j+1]) {
    dfs(heights, visited, i, j+1);
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  m = heights.size(), n = heights[0].size();
  vector<vector<bool>> canPacific(m);
  vector<vector<bool>> canAtlantic(m);
  for (int i = 0; i < heights.size(); i++) {
    canPacific[i] = vector<bool>(n);
    canAtlantic[i] = vector<bool>(n);
  }

  // dfs from Pacific to land
  for (int i = 0; i < m; i++) {
    if (!canPacific[i][0]) {
      dfs(heights, canPacific, i, 0);
    }
  }
  for (int j = 0; j < n; j++) {
    if (!canPacific[0][j]) {
      dfs(heights, canPacific, 0, j);
    }
  }

  // dfs from Atlantic to land
  for (int i = 0; i < m; i++) {
    if (!canAtlantic[i][n-1]) {
      dfs(heights, canAtlantic, i, n-1);
    }
  }
  for (int j = 0; j < n; j++) {
    if (!canAtlantic[m-1][j]) {
      dfs(heights, canAtlantic, m-1, j);
    }
  }

  vector<vector<int>> res;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (canAtlantic[i][j] && canPacific[i][j]) {
        res.push_back(vector<int>{i, j});
      }
    }
  }

  return res;
}

int main() {
  vector<vector<int>> heights{{2,1},{1,2}};
  vector<vector<int>> res = pacificAtlantic(heights);
  print2DVector(res);
  return 0;
}