#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum1(vector<int>& candidates, int target, int start) {
  vector<vector<int>> res;
  for (int i = start; i < candidates.size(); i++) {
    if (candidates[i] == target) {
      res.push_back(vector<int>{candidates[i]});
      return res;
    } else if (candidates[i] > target) {
      continue;
    }

    vector<vector<int>> tmp = combinationSum1(candidates, target - candidates[i], i);
    for (int j = 0; j < tmp.size(); j++) {
      vector<int> comb{candidates[i]};
      comb.insert(comb.end(), tmp[j].begin(), tmp[j].end());
      res.push_back(comb);
    }
  }

  return res;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  return combinationSum1(candidates, target, 0);
}



int main() {
  vector<int> v{2,3,6,7};
  auto r = combinationSum(v, 7);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}