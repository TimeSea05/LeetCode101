#include <iostream>
#include <vector>
using namespace std;

int m, n;
int maximalSquare(vector<vector<char>>& matrix) {
  m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> dp(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == '0') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = INT16_MAX;
        if (i-1 < 0 || j-1 < 0) {
          dp[i][j] = 1;
          continue;
        }

        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
        dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
      }
    }
  }

  int maxSquare = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      maxSquare = max(maxSquare, dp[i][j] * dp[i][j]);
    }
  }

  return maxSquare;
}

void print2DCharVector(vector<vector<char>>& v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<char>> matrix{{'0','1','1','1'},{'1','1','1','1'},{'1','1','1','1'},{'1','1','1','1'}};
  cout << maximalSquare(matrix) << endl;
  // print2DCharVector(matrix);
  return 0;
}