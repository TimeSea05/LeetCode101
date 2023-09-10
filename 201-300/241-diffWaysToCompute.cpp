#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<int> diffWaysToCompute(string expression) {
  vector<int> results;

  for (int i = 0; i < expression.size(); i++) {
    if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
      vector<int> results1 = diffWaysToCompute(expression.substr(0, i));
      vector<int> results2 = diffWaysToCompute(expression.substr(i+1, expression.size() - (i+1)));

      for (int j = 0; j < results1.size(); j++) {
        for (int k = 0; k < results2.size(); k++) {
          switch (expression[i]) {
            case '+':
              results.push_back(results1[j] + results2[k]);
              break;
            case '-':
              results.push_back(results1[j] - results2[k]);
              break;
            case '*':
              results.push_back(results1[j] * results2[k]);
              break;
          }
        }
      }
    }
  }

  if (results.empty()) {
    results.push_back(stoi(expression));
  }

  return results;
}

map<string, vector<int>> mem;

vector<int> diffWaysToComputeMem(string expression) {
  vector<int> results;

  for (int i = 0; i < expression.size(); i++) {
    if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
      string substr1 = expression.substr(0, i);
      string substr2 = expression.substr(i+1, expression.size() - (i+1));

      vector<int> result1, result2;
      result1 = (mem[substr1].size() != 0) ? mem[substr1] : diffWaysToComputeMem(substr1);
      result2 = (mem[substr2].size() != 0) ? mem[substr2] : diffWaysToComputeMem(substr2);

      for (int j = 0 ; j < result1.size(); j++) {
        for (int k = 0; k < result2.size(); k++) {
          switch (expression[i]) {
            case '+':
              results.push_back(result1[j] + result2[k]);
              break;
            case '-':
              results.push_back(result1[j] - result2[k]);
              break;
            case '*':
              results.push_back(result1[j] * result2[k]);
              break;
          }
        }
      }
    }
  }

  if (results.empty()) {
    results.push_back(stoi(expression));
  }
  mem[expression] = results;

  return results;
}

vector<int> diffWaysToComputeDP(string expression) {

  string input = expression + "+";
  istringstream ss(input);

  vector<int> data;
  int num;
  vector<char> ops;
  char ch;

  while (ss >> num && ss >> ch) {
    data.push_back(num);
    ops.push_back(ch);
  }

  int n = data.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>{}));

  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      if (i == j) {
        dp[j][i].push_back(data[i]);
        continue;
      }

      for (int k = j; k < i; k++) {
        for (auto left: dp[j][k]) {
          for (auto right: dp[k+1][i]) {
            switch (ops[k]) {
              case '+':
                dp[j][i].push_back(left + right);
                break;
              case '-':
                dp[j][i].push_back(left - right);
                break;
              case '*':
                dp[j][i].push_back(left * right);
                break;
            }
          }
        }
      }
    }
  }

  return dp[0][n-1];
}

int main() {
  auto res = diffWaysToComputeMem("2*3-4*5");
  printVector(res);
  return 0;
}