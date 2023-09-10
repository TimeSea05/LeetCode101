#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
  if (points.empty()) return 0;

  sort(points.begin(), points.end(), [](vector<int>&a, vector<int>& b) {
    return a[1] < b[1];
  });

  int arrows = 1;
  vector<int>& prev = points[0];
  for (int i = 1; i < points.size(); i++) {
    if (points[i][0] > prev[1]) {
      arrows++;
      prev = points[i];
    }
  }

  return arrows;
}

int main() {
  vector<vector<int>> points{{1,2},{2, 3},{3,4},{4, 5}};
  cout << findMinArrowShots(points) << endl;
  return 0;
}