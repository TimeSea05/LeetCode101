#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
  stack<char> stk;

  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
    case '(':
    case '[':
    case '{':
      stk.push(s[i]);
      break;
    case '}':
      if (stk.empty() || stk.top() != '{') return false;
      else stk.pop();
      break;
    case ']':
      if (stk.empty() || stk.top() != '[') return false;
      else stk.pop();
      break;
    case ')':
      if (stk.empty() || stk.top() != '(') return false;
      else stk.pop();
      break;
    }
  }

  if (stk.size() != 0) return false;
  return true;
}

int main() {
  string s = "(]";
  cout << isValid(s) << endl;
}