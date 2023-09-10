#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int SIZE = 1005;
int volumes[SIZE], values[SIZE];
int dp[SIZE];

int main() {
  int itemsNum, bagVolume;
  // freopen("input.txt", "r", stdin);

  scanf("%d %d", &itemsNum, &bagVolume);
  for (int i = 1; i <= itemsNum; i++) {
    scanf("%d %d", &volumes[i], &values[i]);
  }

  for (int i = 1; i <= itemsNum; i++) {
    for (int v = bagVolume; v >= volumes[i]; v--) {
      dp[v] = max(dp[v], dp[v-volumes[i]]+values[i]);
    }
  }

  printf("%d\n", dp[bagVolume]);
  return 0;
}