#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
  int size = nums.size();

  vector<int> nextNeg(nums.size());
  vector<bool> withZero(nums.size());

  int negPos = -1;
  bool zeroAppeared = false;
  for (int i = size-1; i >= 0; i--) {
    if (nums[i] < 0) {
      nextNeg[i] = negPos;
      negPos = i;
      withZero[i] = zeroAppeared;
      zeroAppeared = false;
    } else if (nums[i] == 0) {
      zeroAppeared = true;
    }
  }

  int maxProd = nums[0], curProd = nums[0];
  int l = 0, r = 0;
  
  while (l < size || r < size) {
    if (curProd > 0) {
      while (++r < size && nums[r] > 0) {
        curProd *= nums[r];
      }
      maxProd = max(maxProd, curProd);
      if (r >= size) {
        break;
      }
      curProd *= nums[r];
    } else if (curProd < 0) {
      if (nextNeg[r] != -1 && !withZero[r]) {
        int nextNegRight = nextNeg[r];
        while (r < nextNegRight) {
          curProd *= nums[++r];
          maxProd = max(maxProd, curProd);
        }
      } else {
        while (nums[l] > 0) {
          curProd /= nums[l++];
        }
        if (l == r) {
          maxProd = max(maxProd, nums[r]);
          if (r+1 < size) {
            l = ++r;
            curProd = nums[r];
            maxProd = max(maxProd, curProd);
          } else break;
        } else {
          curProd /= nums[l++];
          maxProd = max(maxProd, curProd);
        }
      }
    } else {
      while (r < size && nums[r] == 0) r++;
      while (l < r) l++;
      if (r >= size) {
        break;
      } else {
        curProd = nums[r];
      }
    }
  }

  return maxProd;
}

int maxProductDP(vector<int>& nums) {
  vector<int> maxP(nums.size());
  vector<int> minP(nums.size());
  maxP[0] = nums[0], minP[0] = nums[0];

  for (int i = 1; i < int(nums.size()); i++) {
    maxP[i] = max(max(maxP[i-1] * nums[i], minP[i-1] * nums[i]), nums[i]);
    minP[i] = min(min(maxP[i-1] * nums[i], minP[i-1] * nums[i]), nums[i]);
  }

  int maxProd = maxP[0];
  for (int i = 1; i < int(maxP.size()); i++) {
    maxProd = max(maxProd, maxP[i]);
  }
  return maxProd;
}

int main() {
  vector<int> nums{2,3,-2,4};
  cout << maxProductDP(nums) << endl;
  return 0;
}
