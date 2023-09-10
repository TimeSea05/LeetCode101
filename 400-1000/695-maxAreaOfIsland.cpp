#include <vector>
#include <iostream>
using namespace std;

int m, n;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area, int i, int j) {
  visited[i][j] = true;
  area++;

  // up
  if (i-1 >= 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
    dfs(grid, visited, area, i-1, j);
  }
  // down
  if (i+1 < m && grid[i+1][j] == 1 && !visited[i+1][j]) {
    dfs(grid, visited, area, i+1, j);
  }
  // left
  if (j-1 >= 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
    dfs(grid, visited, area, i, j-1);
  }
  // right
  if (j+1 < n && grid[i][j+1] == 1 && !visited[i][j+1]) {
    dfs(grid, visited, area, i, j+1);
  }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
  m = grid.size(), n = grid[0].size();
  int maxArea = 0;

  vector<vector<bool>> visited(m);
  for (int i = 0; i < m; i++) {
    visited[i] = vector<bool>(n);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1 && !visited[i][j]) {
        int area = 0;
        dfs(grid, visited, area, i, j);

        if (area > maxArea) maxArea = area;
      }
    }
  }

  return maxArea;
}

int main() {
  vector<vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
  cout << maxAreaOfIsland(grid) << endl;
}