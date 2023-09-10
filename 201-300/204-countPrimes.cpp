#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {

  vector<bool> sieve(n);
  int count = 0;

  for (int i = 2; i < n; i++) {
    if (!sieve[i]) {
      for (int j = 2; j*i < n; j++) {
        sieve[j*i] = true;
      }
      count++;
    }
  }

  return count;
}

int main() {
  cout << countPrimes(3) << endl;
  return 0;
}