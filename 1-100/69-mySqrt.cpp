#include <iostream>
using namespace std;

int mySqrt(int x) {
  if (x == 0) return 0;
  else if (x == 1) return 1;

  int p1 = 0, p2 = x;

  while (p2 - p1 > 1) {
    int mid = (p1 + p2) / 2;
    long square = mid * mid;

    if (square < x) {
      p1 = mid;
    } else if (square > x) {
      p2 = mid;
    } else {
      return mid;
    }
  }

  return p1;
}

int main() {
  cout << mySqrt(1) << endl;
  return 0;
}