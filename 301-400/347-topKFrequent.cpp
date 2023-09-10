#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void printVector(vector<int>& nums) {
  printf("[");
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) {
      printf(",");
    }
    printf("%d", nums[i]);
  }
  printf("]\n");
}

struct entry {
  int num;
  int times;
};

vector<int> topKFrequent(vector<int>& nums, int k) {
  map<int, int> bucket;
  for (int i = 0; i < nums.size(); i++) {
    bucket[nums[i]]++;
  }

  vector<entry> entries;
  for (auto it = bucket.begin(); it != bucket.end(); it++) {
    entries.push_back(entry{it->first, it->second});
  }

  sort(entries.begin(), entries.end(), [](entry entry1, entry entry2) {
    return entry1.times > entry2.times;
  });

  vector<int> res(k);
  for (int i = 0; i < k; i++) {
    res[i] = entries[i].num;
  }

  return res;
}

int main() {
  vector<int> nums{1};
  int k = 1;

  vector<int> topk = topKFrequent(nums, k);
  printVector(topk);
  return 0;
}