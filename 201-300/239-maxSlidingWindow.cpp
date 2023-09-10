#include <vector>
#include <deque>
#include <iostream>

using std::vector;
using std::deque;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int n = nums.size();
  deque<int> q;
  for (int i = 0; i < k; i++) {
    while (!q.empty() && nums[q.back()] <= nums[i]) {
      q.pop_back();
    }
    q.push_back(i);
  }
  vector<int> res = {nums[q.front()]};

  for (int i = k; i < n; i++) {
    while (!q.empty() && nums[q.back()] <= nums[i]) {
      q.pop_back();
    }
    q.push_back(i);

    while (q.front() <= i - k) {
      q.pop_front();
    }

    res.push_back(nums[q.front()]);
  }

  return res;
}

int main() {
  vector<int> nums{1,3,-1,-3,5,3,6,7};
  auto v = maxSlidingWindow(nums, 3);
  for (int i: v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}