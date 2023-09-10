#include <bits/stdc++.h>
using namespace std;

int N, V;
const int MAXN = 1010;
const int MAXV = 1010;
const int MAXSIZE = 20010;

int v[MAXSIZE], w[MAXSIZE], s[MAXSIZE];
int dp[MAXV];

int main() {
  // freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &V);

  int cnt = 1;
  for (int i = 1; i <= N; i++) {
    int volume, value, size;
    scanf("%d %d %d", &volume, &value, &size);

    if (size > 0) {
      int power = 1;
      while (size >= power) {
        v[cnt] = power*volume;
        w[cnt] = power*value;
        s[cnt] = -1;
        cnt++;

        size -= power;
        power *= 2;
      }

      if (size > 0) {
        v[cnt] = size*volume;
        w[cnt] = size*value;
        s[cnt] = -1;
        cnt++;
      }
    } else {
      v[cnt] = volume;
      w[cnt] = value;
      s[cnt] = size;
      cnt++;
    }
  }

  for (int i = 1; i < cnt; i++) {
    if (s[i] == -1) {
      for (int j = V; j >= v[i]; j--) {
        dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
      }
    } else {
      for (int j = v[i]; j <= V; j++) {
        dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
      }
    }
  }

  printf("%d\n", dp[V]);
  return 0;
}