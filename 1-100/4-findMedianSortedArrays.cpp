#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int total = nums1.size() + nums2.size();
  double median = 0;

  if (total == 1) {
    if (nums1.size()) return nums1[0];
    return nums2[0];
  } else if (total == 2) {
    if (nums1.size() == 2) median += (nums1[0] + nums1[1]);
    else if (nums2.size() == 2) median += (nums2[0] + nums2[1]);
    else median += (nums1[0] + nums2[0]);

    return median / 2;
  }

  int k = total / 2 + total % 2;
  int p1 = 0, p2 = 0;

  while (k > 1 && p1 < nums1.size() && p2 < nums2.size()) {
    // 防止计算 p1 + k/2 - 1, p2 + k/2 -1的时候数组越界
    int p1_add, p2_add;
    if (p1 + k/2 - 1 >= nums1.size()) {
      p1_add = (nums1.size()-1) - p1;
      p2_add = (k-2) - p1_add;
    } else if (p2 + k/2 - 1 >= nums2.size()) {
      p2_add = (nums2.size()-1) - p2;
      p1_add = (k-2) - p2_add;
    } else {
      p1_add = p2_add = k/2 - 1;
    }

    if (nums1[p1 + p1_add] <= nums2[p2 + p2_add]) {
      p1 += (p1_add + 1);
      k -= (p1_add + 1);
    } else {
      p2 += (p2_add + 1);
      k -= (p2_add + 1);
    }
  }

  if (p1 == nums1.size()) {
    p2 += k-1;
  } else if (p2 == nums2.size()) {
    p1 += k-1;
  }

  if (total % 2 == 1) {
    if (p1 == nums1.size()) {
      return nums2[p2];
    } else if (p2 == nums2.size()) {
      return nums1[p1];
    }

    return min(nums1[p1], nums2[p2]);
  }

  if (p1 == nums1.size()) {
    return ((double)(nums2[p2] + nums2[p2+1])/2);
  } else if (p2 == nums2.size()) {
    return ((double)(nums1[p1] + nums1[p1+1])/2);
  }

  if (nums1[p1] <= nums2[p2]) {
    median += nums1[p1];
    p1++;
  } else {
    median += nums2[p2];
    p2++;
  }

  if (p1 == nums1.size()) {
    median += nums2[p2];
  } else if (p2 == nums2.size()) {
    median += nums1[p1];
  } else {
    median += min(nums1[p1], nums2[p2]);
  }

  return median / 2;
}

int main() {
  vector<int> nums1{4, 5, 6, 8, 9};
  vector<int> nums2{};
  cout << findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}