#include <iostream>
#include <vector>
using namespace std;

int m, n;

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {
  if (index == word.size()) {
    return true;
  }

  visited[i][j] = true;
  bool result = false;

  // up
  if (i-1 >= 0 && board[i-1][j] == word[index] && !visited[i-1][j]) {
    result |= dfs(board, visited, word, index+1, i-1, j);
  }
  // down
  if (i+1 < m && board[i+1][j] == word[index] && !visited[i+1][j]) {
    result |= dfs(board, visited, word, index+1, i+1, j);
  }
  // left
  if (j-1 >= 0 && board[i][j-1] == word[index] && !visited[i][j-1]) {
    result |= dfs(board, visited, word, index+1, i, j-1);
  }
  // right
  if (j+1 < n && board[i][j+1] == word[index] && !visited[i][j+1]) {
    result |= dfs(board, visited, word, index+1, i, j+1);
  }

  visited[i][j] = false;
  return result;
}

bool exist(vector<vector<char>>& board, string word) {
  m = board.size(), n = board[0].size();
  vector<vector<bool>> visited(m);
  for (int i = 0; i < m; i++) {
    visited[i] = vector<bool>(n);
  }

  char start = word[0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == start && dfs(board, visited, word, 1, i, j)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  if (exist(board, "ABCB")) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}