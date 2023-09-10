#include <cstdio>
#include <cmath>

bool judgeSquareSum(int c) {
  long longc = (long)c;
  long p1 = 0, p2 = (long)floor(sqrt((double)c));

  while (p1 <= p2 && p1 * p1 + p2 * p2 != longc) {
    if (p1 * p1 + p2 * p2 < c) p1++;
    else p2--;
  }

  if (p1 * p1 + p2 * p2 == longc) {
    return true;
  }
  return false;
}

int main() {
  if (judgeSquareSum(8)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}