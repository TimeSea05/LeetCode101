#include <iostream>
#include <vector>
using namespace std;

int minSteps(int n) {
  vector<int> dp(n+1, INT32_MAX);
  dp[0] = 0, dp[1] = 0;

  for (int i = 2; i <= n; i++) {
    int factor = 1;
    while (factor <= i/2) {
      if (i % factor == 0) {
        dp[i] = min(dp[i], dp[factor] + i/factor);
      }
      factor++;
    }
  }

  return dp[n];
}

int main() {
  cout << minSteps(3) << endl;
  return 0;
}