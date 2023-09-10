#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
  if (s.size() == 0) {
    return 0;
  }

  int maxLen = 0;
  stack<int> stk;
  stk.push(-1);

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      int idx = stk.top();
      stk.pop();
      if (stk.empty()) {
        stk.push(i);
      } else {
        maxLen = max(maxLen, i - stk.top());
      }
    }
  }

  return maxLen;
}

int main() {
  cout << longestValidParentheses("(()(((()") << endl;
}