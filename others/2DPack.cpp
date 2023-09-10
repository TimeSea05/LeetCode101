#include <bits/stdc++.h>
using namespace std;

int N, V, M;
const int MAXN = 1010;
const int MAXV = 110;
const int MAXM = 110;

int v[MAXN], m[MAXN], w[MAXN];
int dp[MAXM][MAXV];

int main() {
  // freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &N, &V, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d %d", &v[i], &m[i], &w[i]);
  }

  for (int i = 1; i <= N; i++) {
    for (int weight = M; weight >= m[i]; weight--) {
      for (int volume = V; volume >= v[i]; volume--) {
        dp[weight][volume] = max(dp[weight][volume], dp[weight-m[i]][volume-v[i]]+w[i]);
      }
    }
  }

  printf("%d\n", dp[M][V]);
  return 0;
}