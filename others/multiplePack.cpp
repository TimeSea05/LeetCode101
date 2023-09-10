#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000;
int s[SIZE], v[SIZE], w[SIZE];
int dp[SIZE];

int main() {
  int N, V;
  freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &V);

  int cnt = 1;
  for (int i = 1; i <= N; i++) {
    int volume, value, size;
    scanf("%d %d %d", &volume, &value, &size);

    int power = 1;
    while (size >= power) {
      v[cnt] = power*volume;
      w[cnt] = power*value;

      size -= power;
      power *= 2;
      cnt++;
    }

    if (size > 0) {
      v[cnt] = volume*size;
      w[cnt] = value*size;
      cnt++;
    }
  }

  // 转换成01背包问题
  for (int i = 1; i < cnt; i++) {
    for (int j = V; j >= v[i]; j--) {
      dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
    }
  }

  printf("%d\n", dp[V]);
  return 0;
}
