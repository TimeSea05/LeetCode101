#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1005;
int volumes[SIZE], values[SIZE];
int dp[SIZE];

int main() {
  int itemsNum, packVolume;
  freopen("input.txt", "r", stdin);

  scanf("%d %d", &itemsNum, &packVolume);
  for (int i = 1; i <= itemsNum; i++) {
    scanf("%d %d", &volumes[i], &values[i]);
  }

  for (int i = 1; i < itemsNum; i++) {
    for (int v = volumes[i]; v <= packVolume; v++) {
      dp[v] = max(dp[v], dp[v-volumes[i]]+values[i]);
    }
  }

  printf("%d\n", dp[packVolume]);
  return 0;
}