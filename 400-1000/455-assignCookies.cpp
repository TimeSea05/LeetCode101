#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>&g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  int content = 0;
  int child = 0, cookie = 0;

  while (1) {
    while (cookie < s.size() && child < g.size() && s[cookie] < g[child]) {
      cookie++;
    }

    if (child == g.size() || cookie == s.size()) break;
    else content++, child++, cookie++;
  }

  return content;
}

int main() {
  vector<int> g{1, 2, 3};
  vector<int> s{1, 1};

  cout << findContentChildren(g, s) << endl;
  return 0;
}