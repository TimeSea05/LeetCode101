#include <iostream>
#include <vector>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
  int nStr = strs.size();
  vector<int> zeros(nStr);
  vector<int> ones(nStr);
  for (int i = 0; i < nStr; i++) {
    for (int j = 0; j < strs[i].size(); j++) {
      if (strs[i][j] == '0') {
        zeros[i]++;
      } else {
        ones[i]++;
      }
    }
  }

  vector<vector<int>> dp(m+1, vector<int>(n+1));
  for (int i = 0; i < nStr; i++) {
    for (int j = m; j >= zeros[i]; j--) {
      for (int k = n; k >= ones[i]; k--) {
        dp[j][k] = max(dp[j][k], dp[j-zeros[i]][k-ones[i]]+1);
      }
    }
  }

  return dp[m][n];
}

int main() {
  vector<string> strs{"10", "0", "1"};
  cout << findMaxForm(strs,1,1) << endl;
  return 0;
}
