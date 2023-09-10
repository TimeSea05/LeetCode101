#include <iostream>
#include <ostream>
#include <vector>

using std::vector;

int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y) {
  if (grid[x][y] != '1' || visit[x][y]) {
    return;
  }

  visit[x][y] = true;
  int m = grid.size(), n = grid[0].size();
  for (int i = 0; i < 4; i++) {
    int nextX = x + directions[i][0];
    int nextY = y + directions[i][1];

    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
      dfs(grid, visit, nextX, nextY);
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<bool>> visit(m, vector<bool>(n));
  int count = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '1' && !visit[i][j]) {
        dfs(grid, visit, i, j);
        count++;
      }
    }
  }

  return count;
}

int main() {
  vector<vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
  std::cout << numIslands(grid) << std::endl;
  return 0;
}
