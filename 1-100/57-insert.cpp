#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void printIntervals(const vector<vector<int>>& intervals) {
  printf("{");
  for (int i = 0; i < intervals.size(); i++) {
    if (i != 0) printf(",");
    printf("{%d, %d}", intervals[i][0], intervals[i][1]);
  }
  printf("}");
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  intervals.push_back(newInterval);
  sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>& b) {
    return a[0] < b[0];
  });

  vector<vector<int>> inserted;

  vector<int>& prev = intervals[0];
  int start = prev[0], end = prev[1];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] <= end) {
      end = max(end, intervals[i][1]);
    } else {
      inserted.push_back(vector<int>{start, end});
      prev = intervals[i];
      start = prev[0], end = prev[1];
    }
  }
  inserted.push_back(vector<int>{start, end});

  return inserted;
}

int main() {
  vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> newInterval{4, 8};
  printIntervals(insert(intervals, newInterval));

  return 0;
}