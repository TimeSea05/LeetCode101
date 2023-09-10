#include <cstdio>
#include <vector>
using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  vector<int> merged(nums1.size());
  int i = 0, j = 0;
  int p = 0;

  while (i < m && j < n) {
    if (nums1[i] < nums2[j]) {
      merged[p++] = nums1[i++];
    } else {
      merged[p++] = nums2[j++];
    }
  }

  while (i < m) {
    merged[p++] = nums1[i++];
  }
  while (j < n) {
    merged[p++] = nums2[j++];
  }

  nums1 = merged;
}