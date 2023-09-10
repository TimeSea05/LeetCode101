#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n) {
  vector<int> dp(n+1, INT16_MAX);
  dp[0] = 0, dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j*j <= i; j++) {
      dp[i] = min(dp[i], dp[i-j*j]+1);
    }
  }

  return dp[n];
}

int main() {
  cout << numSquares(16) << endl;
  return 0;
}