#include <bits/stdc++.h>
using namespace std;

void f1(vector<int>& v) {
  for (auto& i: v) {
    i = i * 2 - 1;
  }
}

void f2(vector<int>& v) {
  for (auto& i: v) {
    i = i * 2;
  }
} 

vector<int> beautifulArray(int n) {
  if (n == 1) return vector<int>{1};

  vector<int> even = beautifulArray((n+1)/2);
  vector<int> odd = beautifulArray(n/2);

  f1(even);
  f2(odd);

  even.insert(even.end(), odd.begin(), odd.end());
  return even;
}

void printVector(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  auto res = beautifulArray(4);
  printVector(res);
  return 0;
}