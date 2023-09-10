#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::set;

class Solution {
private:
  int n;
  int len;
  int max;

  string str;
  set<string> st;

  int maxParentheses(string s) {
    int lnum = 0, rnum = 0;
    for (char c: s) {
      if (c == '(') lnum++;
      else if (c == ')') rnum++;
    }

    return std::min(lnum, rnum);
  }

  void dfs(int idx, string cur, int score) {
    if (idx == n) {
      if (score == 0 && cur.size() >= len) {
        if (cur.size() > len) {
          st.clear();
          len = cur.size();
        }
        st.insert(cur);
      }
      return;
    }

    if (str[idx] == '(') {
      if (score < max) {
        dfs(idx+1, cur+'(', score+1);
      }
      dfs(idx+1, cur, score);
    } else if (str[idx] == ')') {
      if (score > 0) {
        dfs(idx+1, cur+')', score-1);
      }
      dfs(idx+1, cur, score);
    } else {
      dfs(idx+1, cur+str[idx], score);
    }
  }

public:
  Solution() {}

  vector<string> removeInvalidParentheses(string s) {
    this->str = s;
    this->n = s.size();
    this->len = 0;
    this->max = maxParentheses(s);

    dfs(0, "", 0);

    vector<string> ans;
    for (const string & deleted: st) {
      ans.push_back(deleted);
    }

    return ans;
  }
};

int main() {
  Solution solu;
  vector<string> ans = solu.removeInvalidParentheses("(a)())()");
  for (const string& s: ans) {
    std::cout << s << "\n";
  }

  return 0;
}
