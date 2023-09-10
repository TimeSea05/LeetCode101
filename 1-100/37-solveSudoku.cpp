#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

struct Point {
  int x, y;
  Point(int x, int y): x(x), y(y) {}
};

bool boardFilled;

Point findEmptySpace(vector<vector<char>>& board) {
  Point p(-1, -1);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        p.x = i, p.y = j;
        return p;
      }
    }
  }
  return p;
}

vector<char> canPlaceNumbers(vector<vector<char>>& board, int i, int j) {
  vector<bool> nums(10);
  // horizontal
  for (int k = 0; k < 9; k++) {
    if (board[i][k] != '.') {
      nums[board[i][k] - '0'] = true;
    }
  }

  // vertical
  for (int k = 0; k < 9; k++) {
    if (board[k][j] != '.') {
      nums[board[k][j] - '0'] = true;
    }
  }

  // in 3*3 block
  int blockStartX = i - i%3, blockStartY = j - j%3;
  for (int k = 0; k < 3; k++) {
    for (int l = 0; l < 3; l++) {
      if (board[blockStartX+k][blockStartY+l] != '.') {
        nums[board[blockStartX+k][blockStartY+l] - '0']= true;
      }
    }
  }

  vector<char> canPlace;
  for (int k = 1; k <= 9; k++) {
    if (!nums[k]) {
      canPlace.push_back('0' + k);
    }
  }

  return canPlace;
}

void dfs(vector<vector<char>>& board, int i, int j) {
  Point p(10, 10);
  vector<char> nums = canPlaceNumbers(board, i, j);
  for (int k = 0; k < nums.size(); k++) {
    board[i][j] = nums[k];

    if (p.x == 10) {  // point p is not initialized
      p = findEmptySpace(board);
      if (p.x == -1) {
        boardFilled = true;
        return;
      }
    }

    dfs(board, p.x, p.y);

    if (boardFilled) {
      return;
    }
    board[i][j] = '.';
  }
}

void solveSudoku(vector<vector<char>>& board) {
  Point p = findEmptySpace(board);
  dfs(board, p.x, p.y);
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
  vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

  solveSudoku(board);
  print2DCharVector(board);
  return 0;
}