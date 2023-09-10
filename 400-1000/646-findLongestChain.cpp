#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
  sort(pairs.begin(), pairs.end(), [](vector<int>& pair1, vector<int>& pair2) {
    if (pair1[0] != pair2[0]) {
      return pair1[0] < pair2[0];
    }
    return pair1[1] < pair2[1];
  });

  int n = pairs.size();
  vector<int> dp(n,1);
  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (pairs[j][1] < pairs[i][0]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  return dp[n-1];
}

int main() {
  vector<vector<int>> pairs{{1,2},{7,8},{4,5}};
  cout << findLongestChain(pairs) << endl;
  return 0;
}