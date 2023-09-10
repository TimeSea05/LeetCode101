#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Point {
  int x, y;
  Point(int x, int y): x(x), y(y) {}
};

struct BlockInfo {
  Point p;
  int dist;

  BlockInfo(int x, int y, int dist): p(Point{x, y}), dist(dist) {}
};

const int MARK = 2;
int N;

int xdirect[4];
int ydirect[4];
const int NDIRECTS = 4;

void initDirectArr() {
  xdirect[0] = -1, xdirect[1] = 1, xdirect[2] = 0, xdirect[3] = 0;
  ydirect[0] = 0, ydirect[1] = 0, ydirect[2] = -1, ydirect[3] = 1;
}

void dfs(vector<vector<int>>& grid, int mark, int i, int j) {
  grid[i][j] = mark;
  for (int k = 0; k < NDIRECTS; k++) {
    int newx = i + xdirect[k];
    int newy = j + ydirect[k];
    if (newx >= 0 && newx < N && newy >= 0 && newy < N && grid[newx][newy] == 1) {
      dfs(grid, mark, newx, newy);
    }
  }
}

void markIsland(vector<vector<int>>& grid, int mark) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j] == 1) {
        goto out;
      }
    }
  }

out:
  dfs(grid, mark, i, j);
}

bool isCoastal(vector<vector<int>>& grid, int i, int j) {
  for (int k = 0; k < NDIRECTS; k++) {
    int newx = i + xdirect[k];
    int newy = j + ydirect[k];
    if (newx >= 0 && newx < N && newy >= 0 && newy < N && (grid[newx][newy] == 0 || grid[newx][newy] == 1)) {
      return true;
    }
  }

  return false;
}

int shortestBridge(vector<vector<int>>& grid) {
  N = grid.size();
  initDirectArr();
  markIsland(grid, MARK);

  queue<BlockInfo*> q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == MARK) {
        q.push(new BlockInfo(i, j, 0));
      }
    }
  }

  while (!q.empty()) {
    BlockInfo *blockinfo = q.front();
    q.pop();

    int x = blockinfo->p.x, y = blockinfo->p.y;
    if (isCoastal(grid, x, y)) {
      for (int i = 0; i < NDIRECTS; i++) {
        int newx = x + xdirect[i];
        int newy = y + ydirect[i];
        if (newx >= 0 && newx < N && newy >= 0 && newy < N) {
          if (grid[newx][newy] == 1) {
            return blockinfo->dist;
          } else if (grid[newx][newy] == 0) {
            q.push(new BlockInfo(newx, newy, blockinfo->dist+1));
          }
          grid[newx][newy] = MARK;
        }
      }
    }
  }

  return 0;
}

int main() {
  vector<vector<int>> grid{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  cout << shortestBridge(grid) << endl;

  return 0;
}
