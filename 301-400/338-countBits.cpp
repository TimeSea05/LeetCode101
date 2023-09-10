#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector<int> countBits(int n) {
  vector<int> ans(n+1);
  int pow = 1;

  while (1) {
    int inc = min(pow, n+1 - pow);
    for (int i = 0; i < inc; i++) {
      ans[pow+i] = ans[i]+1;
    }

    if (inc != pow) break;
    pow += pow;
  }

  return ans;
}

int main() {
  auto v = countBits(5);
  for (auto i: v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}