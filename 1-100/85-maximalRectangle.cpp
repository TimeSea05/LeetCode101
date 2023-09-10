#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
  // heights.insert(heights.begin(), 0);
  // heights.push_back(0);
  int maxArea = 0, size = heights.size();
  stack<int> st;

  for (int i = 0; i < size; i++) {
    while (!st.empty() && heights[st.top()] > heights[i]) {
      int cur = st.top(); st.pop();
      int r = i-1, l = st.top();
      maxArea = max(maxArea, (r-l)*heights[cur]);
    }
    st.push(i);
  }

  return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
  if (matrix.size() == 0) {
    return 0;
  }

  int m = matrix.size(), n = matrix[0].size();
  int maxRect = 0;
  vector<int> heights(n+2);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == '0') {
        heights[j+1] = 0;
      } else {
        heights[j+1]++;
      }
    }

    maxRect = max(maxRect, largestRectangleArea(heights));
  }

  return maxRect;
}

int main() {
  vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  cout << maximalRectangle(matrix) << endl;
  // vector<int> heights{2, 1, 5, 6, 2, 3};
  // cout << largestRectangleArea(heights) << endl;
  return 0;
}