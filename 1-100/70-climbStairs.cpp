#include <iostream>
using namespace std;

int climbStairs(int n) {
  int ways[50];
  ways[0] = 1; ways[1] = 1;

  for (int i = 2; i <= n; i++) {
    ways[i] = ways[i-1] + ways[i-2];
  }
  return ways[n];
}

int main() {
  cout << climbStairs(4) << endl;
  return 0;
}