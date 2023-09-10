#include <bits/stdc++.h>
using namespace std;

struct item {
  int volume;
  int value;
};

int N, V;
const int MAXN = 110;
const int MAXV = 110;
const int MAXS = 110;

int s[MAXN];
item items[MAXN][MAXS];
int dp[MAXV];

int main() {
  // freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &V);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &s[i]);
    for (int j = 1; j <= s[i]; j++) {
      scanf("%d %d", &(items[i][j].volume), &(items[i][j].value));
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int v = V; v >= 0; v--) {
      for (int n = 1; n <= s[i]; n++) {
        if (v >= items[i][n].volume) {
          dp[v] = max(dp[v], dp[v - items[i][n].volume]+items[i][n].value);
        }
      }
    }
  }

  printf("%d\n", dp[V]);
  return 0;
}