#include <vector>
#include <cstdio>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int i = 0, j = numbers.size() - 1;
  int sum = numbers[i] + numbers[j];

  while (sum != target) {
    if (sum < target) i++;
    else j--;
    sum = numbers[i] + numbers[j];
  }

  return vector<int>{i+1, j+1};
}

int main() {
  vector<int> numbers{-1, 0};
  int target = -1;
  vector<int> res = twoSum(numbers, target);

  printf("%d %d\n", res[0], res[1]);
  return 0;
}