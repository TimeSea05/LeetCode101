#include <string>
#include <cstdio>
using namespace std;

bool validPalindrome(string s) {
  int i = 0, j = s.size() - 1;

  while (s[i] == s[j] && i < j) {
    i++, j--;
  }

  if (i >= j) return true;

  // case1: delete s[i]
  int p1 = i + 1, p2 = j;
  while (s[p1] == s[p2] && p1 < p2) {
    p1++, p2--;
  }
  if (p1 >= p2) return true;

  // case2: delete s[j]
  int q1 = i, q2 = j - 1;
  while (s[q1] == s[q2] && q1 < q2) {
    q1++, q2--;
  }
  if (q1 >= q2) return true;
  return false;
}

int main() {
  if (validPalindrome("abc")) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}