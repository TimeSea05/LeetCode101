#include <vector>
#include <iostream>
using namespace std;

int N;

// 因为dfs顺序是从上到下，所以只需要考虑下面，上面不用考虑
void forbid(vector<string>& board, vector<vector<int>>& canPlace, int i, int j) {
  for (int k = i + 1; k < N; k++) {
    if (canPlace[k][j] <= 0) canPlace[k][j]--;
  }
  for (int k = i+1, l = j-1; k < N && l >= 0; k++, l--) {
    if (canPlace[k][l] <= 0) canPlace[k][l]--;
  }
  for (int k = i+1, l = j+1; k < N && l < N; k++, l++) {
    if (canPlace[k][l] <= 0) canPlace[k][l]--;
  }
}

void unforbid(vector<string>& board, vector<vector<int>>& canPlace, int i, int j) {
  for (int k = i + 1; k < N; k++) {
    if (canPlace[k][j] <= 0) canPlace[k][j]++;
  }
  for (int k = i+1, l = j-1; k < N && l >= 0; k++, l--) {
    if (canPlace[k][l] <= 0) canPlace[k][l]++;
  }
  for (int k = i+1, l = j+1; k < N && l < N; k++, l++) {
    if (canPlace[k][l] <= 0) canPlace[k][l]++;
  }
}

void dfs(vector<string>& board, vector<vector<int>>& canPlace, vector<vector<string>>& res, int i, int j) {
  if (canPlace[i][j] != 0) return;

  board[i][j] = 'Q';
  canPlace[i][j]++;
  forbid(board, canPlace, i, j);

  if (i == N-1) {
    res.push_back(vector<string>(board));
  } else {
    for (int k = 0; k < N; k++) {
      dfs(board, canPlace, res, i+1, k);
    }
  }

  unforbid(board, canPlace, i, j);
  canPlace[i][j]--;
  board[i][j] = '.';
}

vector<vector<string>> solveNQueens(int n) {
  N = n;
  vector<string> board(n, string(n, '.'));
  vector<vector<int>> canPlace(n, vector<int>(n, 0));
  vector<vector<string>> res;

  for (int i = 0; i < n; i++) {
    dfs(board, canPlace, res, 0, i);
  }

  return res;
}

void print2DStringVector(vector<vector<string>>& res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    if (i != 0) cout << ",";
    cout << "[";
    for (int j = 0; j < res[0].size(); j++) {
      if (j != 0) cout << ",";
      cout << "\"" << res[i][j] << "\"";
    }
    cout << "]";
  }
  cout << "]\n";
}

int main() {
  auto res = solveNQueens(1);
  print2DStringVector(res);
  return 0;
}