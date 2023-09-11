#include "../lib/libleetcode.h"
#include <iostream>

/*
Brian Kernighan Algorithm
*/
int hammingDistanceBrian(int x, int y) {
  int z = x ^ y;
  int ans = 0;
  while (z) {
    z &= (z-1);
    ans++;
  }

  return ans;
}

int hammingDistance(int x, int y) {
  int z = x ^ y;
  return __builtin_popcount(z);
}

int main() {
  cout << hammingDistanceBrian(1, 4) << endl;
  return 0;
}
