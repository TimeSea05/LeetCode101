#include <iostream>
#include <vector>
using std::vector;

vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> res(n);

  res[0] = 1, res[n-1] = 1;
  int prod = nums[n-1];

  for (int i = n-2; i >= 0; i--) {
    res[i] = prod;
    prod *= nums[i];
  }

  prod = nums[0];
  for (int i = 1; i < n; i++) {
    res[i] *= prod;
    prod = prod * nums[i];
  }

  return res;
}

int main() {
  vector<int> v{-1,1,0,-3,3};
  auto r = productExceptSelf(v);
  for (auto i: r) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}