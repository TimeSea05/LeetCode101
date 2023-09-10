#include <bits/stdc++.h>
using namespace std;

int itemsNum, packVolume;
const int MaxItemsNum = 1010;
const int MaxVolume = 20010;

int volumes[MaxItemsNum], values[MaxItemsNum], sizes[MaxItemsNum];
int dp[MaxItemsNum][MaxVolume];
int q[MaxVolume];

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d %d", &itemsNum, &packVolume);
	for (int i = 1; i <= itemsNum; i++) {
		scanf("%d %d %d", &volumes[i], &values[i], &sizes[i]);
	}

	for (int i = 1; i <= itemsNum; i++) {
		for (int remain = 0; remain < volumes[i]; remain++) {
			int head = 0, tail = -1;
			for (int volume = remain; volume <= packVolume; volume += volumes[i]) {
				while (head <= tail && volume-q[head] > sizes[i]*volumes[i]) {
					head++;
				}
				while (head <= tail && dp[i-1][q[tail]] + (volume-q[tail])/volumes[i]*values[i] < dp[i-1][volume]) {
					tail--;
				}
				q[++tail] = volume;
				dp[i][volume] = dp[i-1][q[head]] + (volume-q[head])/volumes[i]*values[i];
			}
		}
	}

	printf("%d\n", dp[itemsNum][packVolume]);
	return 0;
}