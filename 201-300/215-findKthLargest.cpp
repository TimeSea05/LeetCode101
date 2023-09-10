#include <iostream>
#include <vector>
using namespace std;

int median3(vector<int>& nums, int l, int r) {
  int mid = (l+r)/2;
  if (nums[l] < nums[mid]) swap(nums[l], nums[mid]);
  if (nums[mid] < nums[r]) swap(nums[mid], nums[r]);
  if (nums[l] < nums[mid]) swap(nums[l], nums[mid]);

  int pivot = nums[mid];
  swap(nums[mid], nums[r]);
  return pivot;
}

int quicksort(vector<int>& nums, int l, int r) {
  int pivot = median3(nums, l, r);
  int oldr = r; r--;

  while (1) {
    while (nums[l] >= pivot && l < oldr) l++;
    while (nums[r] < pivot && r > 0) r--;
    if (l < r) swap(nums[l], nums[r]);
    else break;
  }

  swap(nums[l], nums[oldr]);
  return l;
}

int findKthLargest(vector<int>& nums, int k) {
  int l = 0, r = nums.size()-1;
  while (r - l >= 2) {
    int idx = quicksort(nums, l, r);
    if (idx > k-1) r = idx-1;
    else if (idx < k-1) l = idx+1;
    else {l++, r--;}
  }

  if (nums[r] > nums[l]) swap(nums[r], nums[l]);

  return nums[k-1];
}

int main() {
  vector<int> nums{1,2,3,4,5,6};  // 6 5 5 4 3 3 2 2 1
  for (int i = 1; i <= nums.size(); i++) {
    cout << findKthLargest(nums, i) << endl;
  }
  return 0;
}
