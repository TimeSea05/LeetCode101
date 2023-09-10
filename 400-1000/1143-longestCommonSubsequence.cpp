#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  int len1 = text1.size(), len2 = text2.size();
  vector<vector<int>> dp(len1+1, vector<int>(len2+1));

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      dp[i][j] = max(dp[i-1][j-1]+(text1[i-1]==text2[j-1]), max(dp[i-1][j], dp[i][j-1]));
    }
  }

  return dp[len1][len2];
}

int main() {
  cout << longestCommonSubsequence("abcde", "abc") << endl;
  return 0;
}