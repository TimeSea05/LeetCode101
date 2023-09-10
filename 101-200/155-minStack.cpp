#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
class MinStack {
private:
  std::vector<int> arr;
  std::vector<int> mins;
public:
  MinStack() {}
  void push(int val) {
    arr.push_back(val);

    if (mins.empty()) {
      mins.push_back(val);
    } else {
      mins.push_back(std::min(mins.back(), val));
    }
  }

  void pop() {
    arr.pop_back();
    mins.pop_back();
  }

  int top() {
    return arr.back();
  }

  int getMin() {
    return mins.back();
  }
};

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  std::cout << minStack.getMin() << std::endl;
  minStack.pop();
  std::cout << minStack.top() << std::endl;
  std::cout << minStack.getMin() << std::endl;
}