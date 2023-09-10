#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using std::stack;
using std::vector;
using std::min;
using std::max;

int trap(vector<int>& height) {
  if (height.size() < 3) {
    return 0;
  }

  int size = height.size();
  int volume = 0;

  vector<int> leftHighs(height.size());
  vector<int> rightHighs(height.size());

  leftHighs[1] = height[0], rightHighs[size-2] = height[size-1];
  for (int i = 2; i < size-1; i++) {
    leftHighs[i] = max(leftHighs[i-1], height[i-1]);
  }
  for (int i = size-3; i >= 1; i--) {
    rightHighs[i] = max(rightHighs[i+1], height[i+1]);
  }

  for (int i = 1; i < size-1; i++) {
    int shortest = min(leftHighs[i], rightHighs[i]);
    if (shortest > height[i]) {
      volume += (shortest - height[i]);
    }
  }

  return volume;
}

int trapStack(vector<int>& height) {
  stack<int> st;
  int size = height.size();
  int sum = 0;
  for (int i = 0; i < size; i++) {
    while (!st.empty() && height[st.top()] < height[i]) {
      int btm = height[st.top()]; st.pop();
      if (st.empty()) {
        break;
      }
      int minTop = min(height[i], height[st.top()]);
      sum += (minTop - btm) * (i - st.top() - 1);
    }
    st.push(i);
  }

  return sum;
}

int main() {
  vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};
  printf("%d\n", trapStack(heights));
}