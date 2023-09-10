#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) return 0;

  sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
  });

  int erase = 0;
  vector<int>& prev = intervals[0];

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < prev[1]) {
      erase++;
    } else {
      prev = intervals[i];
    }
  }

  return erase;
}

int main() {
  vector<vector<int>> intervals{ {1,2}, {2,3} };
  cout << eraseOverlapIntervals(intervals) << endl;
}