#include <vector>
#include <iostream>
using namespace std;

int integerBreak(int n) {
  int maxMultiply = 0;
  for (int i = 2; i <= n; i++) {
    int div = n / i, remain = n % i;
    int mul = 1;

    for (int j = 0; j < remain; j++) {
      mul *= (div + 1);
    }
    for (int j = 0; j < i - remain; j++) {
      mul *= div;
    }

    maxMultiply = max(maxMultiply, mul);
  }

  return maxMultiply;
}

int integerBreakDP(int n) {
  vector<int> dp(n+1);
  for (int i = 2; i <= n; i++) {
    int curMax = 0;
    for (int j = 1; j < i; j++) {
      curMax = max(curMax, max(j * (i-j), j * dp[i-j]));
    }
    dp[i] = curMax;
  }

  return dp[n];
}

int main() {
  cout << integerBreakDP(8) << endl;
  return 0;
}
