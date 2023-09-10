#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using std::string;
using std::stack;

string decodeString(string s) {
  int n = s.size();
  string decoded;

  int i = 0, j = 0;
  while (1) {
    while (j < n && !isdigit(s[j])) {
      j++;
    }
    decoded += s.substr(i, j-i);
    if (j == n) break;

    // retrieve integer
    int rep = 0;
    while (isdigit(s[j])) {
      rep = rep * 10 + (s[j] - '0');
      j++;
    }

    int l = j, r = j;
    stack<char> stk; stk.push(s[r]);
    while (!stk.empty()) {
      r++;
      if (s[r] == '[') stk.push(s[r]);
      else if (s[r] == ']') stk.pop();
    }

    string repStr = decodeString(s.substr(l+1, r-l-1));
    for (int k = 0; k < rep; k++) {
      decoded += repStr;
    }

    i = j = r+1;
  }

  return decoded;
}

int main() {
  std::cout << decodeString("abc3[cd]xyz") << std::endl;
  return 0;
}