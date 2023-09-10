#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::min;
using std::max;
using std::endl;


int largestRectangleArea(vector<int>& heights) {
  heights.insert(heights.begin(), 0);
  heights.push_back(0);

  vector<int> stk;
  int maxArea = 0;

  for (int i = 0; i < heights.size(); i++) {
    while (!stk.empty() && heights[stk.back()] > heights[i]) {
      int r = i-1;
      int cur = stk.back(); stk.pop_back();
      int l = stk.back();
      int h = heights[cur];
      maxArea = max(maxArea, h*(r-l));
    }
    stk.push_back(i);
  }

  return maxArea;
}

int main() {
  vector<int> heights{2,1,5,6,2,3};
  cout << largestRectangleArea(heights) << endl;
}