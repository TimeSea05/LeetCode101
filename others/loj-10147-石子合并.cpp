#include <bits/stdc++.h>
using namespace std;

#define MAX 999999
// 4 5 9 4
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);

  vector<int> nums(n*2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    nums[i+n] = nums[i];
  }

  vector<int> sums(2*n - 1);
  sums[0] = nums[0];
  for (int i = 1; i < 2*n-1; i++) {
    sums[i] = sums[i-1] + nums[i];
  }

  vector<vector<int>> minDP(2*n-1, vector<int>(2*n - 1));
  vector<vector<int>> maxDP(2*n-1, vector<int>(2*n - 1));

  for (int i = 1; i < 2*n - 1; i++) {
    for (int j = i-1; j >= max(0, i+1-n); j--) {
      if (j == i-1) {
        minDP[j][i] = nums[j] + nums[i];
        maxDP[j][i] = nums[j] + nums[i];
        continue;
      }

      int sum = (j-1 >= 0) ? sums[i] - sums[j-1] : sums[i];
      int minStones = MAX, maxStones = 0;

      for (int k = j; k < i; k++) {
        int curMinStones = sum + minDP[j][k] + minDP[k+1][i];
        int curMaxStones = sum + maxDP[j][k] + maxDP[k+1][i];

        minStones = min(minStones, curMinStones);
        maxStones = max(maxStones, curMaxStones);
      }

      minDP[j][i] = minStones;
      maxDP[j][i] = maxStones;
    }
  }

  int minStonesNum = MAX, maxStonesNum = 0;
  for (int i = 0; i < n; i++) {
    minStonesNum = min(minStonesNum, minDP[i][i+n-1]);
    maxStonesNum = max(maxStonesNum, maxDP[i][i+n-1]);
  }

  printf("%d\n%d\n", minStonesNum, maxStonesNum);
  return 0;
}