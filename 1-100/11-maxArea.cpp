#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& heights) {
  int l = 0, r = heights.size() - 1;
  int area = 0;
  while (l < r) {
    area = max(min(heights[l], heights[r]) * (r-l), area);
    if (heights[l] < heights[r]) {
      l++;
    } else {
      r--;
    }
  }

  return area;
}

int main() {
  vector<int> heights{1,8,6,2,5,4,8,3,7};
  cout << maxArea(heights) << endl;
  return 0;
}
