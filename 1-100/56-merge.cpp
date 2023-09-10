#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>& b) {
    return a[0] < b[0];
  });

  vector<vector<int>> merged;

  vector<int>& prev = intervals[0];
  int start = prev[0], end = prev[1];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] <= end) {
      end = max(end, intervals[i][1]);
    } else {
      merged.push_back(vector<int>{start, end});
      prev = intervals[i];
      start = prev[0], end = prev[1];
    }
  }
  merged.push_back(vector<int>{start, end});

  return merged;
}

void printIntervals(const vector<vector<int>>& intervals) {
  printf("{");
  for (int i = 0; i < intervals.size(); i++) {
    if (i != 0) printf(",");
    printf("{%d, %d}", intervals[i][0], intervals[i][1]);
  }
  printf("}");
}

int main() {
  vector<vector<int>> intervals{{1,4}};
  printIntervals(merge(intervals));
  return 0;
}