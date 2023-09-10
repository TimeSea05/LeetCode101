#include <iostream>
#include <vector>
using namespace std;

void generate(vector<string>& res, string str, int n, int l, int r) {
  if (l == n && r == n) {
    res.push_back(str);
    return;
  }

  if (l < n) {
    generate(res, str + "(", n, l+1, r);
  }
  if (r < l) {
    generate(res, str + ")", n, l, r+1);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> res;
  generate(res, "", n, 0, 0);
  return res;
}

int main() {
  auto res = generateParenthesis(2);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}