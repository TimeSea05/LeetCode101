#include <iostream>
#include <vector>
using namespace std;

int m, n;
int xdirect[4];
int ydirect[4];
const int NDIRECTS = 4;

void initDirectArr() {
  xdirect[0] = -1, xdirect[1] = 1, xdirect[2] = 0, xdirect[3] = 0;
  ydirect[0] = 0, ydirect[1] = 0, ydirect[2] = -1, ydirect[3] = 1;
}

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
  visited[i][j] = true;
  for (int k = 0; k < NDIRECTS; k++) {
    int newx = i + xdirect[k];
    int newy = j + ydirect[k];
    if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
      if (board[newx][newy] == 'O' && !visited[newx][newy]) {
        dfs(board, visited, newx, newy);
      }
    }
  }
}

void solve(vector<vector<char>>& board) {
  m = board.size(), n = board[0].size();
  initDirectArr();
  vector<vector<bool>> visited(m, vector<bool>(n));

  // up and down
  for (int j = 0; j < n; j++) {
    if (board[0][j] == 'O' && !visited[0][j]) {
      dfs(board, visited, 0, j);
    }
    if (board[m-1][j] == 'O' && !visited[m-1][j]) {
      dfs(board, visited, m-1, j);
    } 
  }

  // left and right
  for (int i = 1; i < m-1; i++) {
    if (board[i][0] == 'O' && !visited[i][0]) {
      dfs(board, visited, i, 0);
    }
    if (board[i][n-1] == 'O' && !visited[i][n-1]) {
      dfs(board, visited, i, n-1);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        board[i][j] = 'X';
      }
    }
  }
}

void print2DCharVector(vector<vector<char>>& board) {
  printf("[");
  for (int i = 0; i < board.size(); i++) {
    if (i != 0) printf(",");
    printf("[");
    for (int j = 0; j < board[0].size(); j++) {
      if (j != 0) printf(",");
      printf("\"%c\"", board[i][j]);
    }
    printf("]");
  }
  printf("]\n");
}

int main() {
  vector<vector<char>> board{{'O','O','O'},{'O','O','O'},{'O','O','O'}};
  solve(board);
  print2DCharVector(board);
  return 0;
}