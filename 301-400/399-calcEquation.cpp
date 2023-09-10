#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

/*
  a/b = 2.0, b/c = 3.0
  a/c
*/

// vector<double> calcEquation(
//   vector<vector<string>>& equations,
//   vector<double>& values, vector<vector<string>>& queries
// ) {
//   int neq = equations.size(), nquery = queries.size();
//   unordered_map<string, unordered_map<string, double>> hash;

//   for (int i = 0; i < neq; i++) {
//     string dividend = equations[i][0], divisor = equations[i][1];
//     hash[dividend][divisor] = values[i];
//     hash[divisor][dividend] = 1/values[i];
//   }

//   bool changed = true;
//   while (changed) {
//     changed = false;
//     for (auto it = hash.begin(); it != hash.end(); it++) {
//       string dividend = it->first;
//       unordered_map<string, double>& v1 = it->second;

//       for (auto it1 = v1.begin(); it1 != v1.end(); it1++) {
//         string eliminate = it1->first;

//         double val1 = it1->second;
//         unordered_map<string, double>& v2 = hash[eliminate];

//         for (auto it2 = v2.begin(); it2 != v2.end(); it2++) {
//           string divisor = it2->first;
//           if (dividend.compare(divisor) == 0) {
//             continue;
//           }

//           double val2 = it2->second;
//           if (!v1.count(divisor)) {
//             hash[dividend][divisor] = val1 * val2;
//             changed = true;
//           }
//           if (!hash[divisor].count(dividend)) {
//             hash[divisor][dividend] = 1/(val1 * val2);
//             changed = true;
//           }
//         }
//       }
//     }
//   }
  

//   vector<double> ans;
//   for (vector<string>& query: queries) {
//     if (query[0].compare(query[1]) == 0) {
//       ans.push_back((hash.count(query[0]) ? 1 : -1));
//       continue;
//     }

//     if (!hash.count(query[0])) {
//       ans.push_back(-1);
//       continue;
//     }

//     if (!hash[query[0]].count(query[1])) {
//       ans.push_back(-1);
//       continue;
//     }

//     ans.push_back(hash[query[0]][query[1]]);
//   }

//   return ans;
// }

class UnionFind {
private:
  int *parent;
  double *weight;

public:
  UnionFind(int n) {
    this->parent = new int[n];
    this->weight = new double[n];
    for (int i = 0; i < n; i++) {
      this->parent[i] = i;
      this->weight[i] = 1;
    }
  }
  ~UnionFind() {
    delete [] parent;
    delete [] weight;
  }

  void join(int x, int y, double val) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return;
    }

    parent[rootX] = rootY;
    weight[rootX] = val * weight[y] / weight[x];
  }

  int find(int x) {
    if (parent[x] != x) {
      int origin = parent[x];
      parent[x] = find(parent[x]);
      weight[x] *= weight[origin];
    }
    return parent[x];
  }

  double check(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return weight[x] / weight[y];
    }
    return -1;
  }
};

vector<double> calcEquation(
  vector<vector<string>>& equations,
  vector<double>& values, vector<vector<string>>& queries
) {
  int neq = equations.size(), nquery = queries.size();

  unordered_map<string, int> nameToID;
  int id = 0;
  for (int i = 0; i < neq; i++) {
    if (!nameToID.count(equations[i][0])) {
      nameToID[equations[i][0]] = id++;
    }
    if (!nameToID.count(equations[i][1])) {
      nameToID[equations[i][1]] = id++;
    }
  }

  UnionFind u(id);
  for (int i = 0; i < neq; i++) {
    u.join(nameToID[equations[i][0]], nameToID[equations[i][1]], values[i]);
  }

  vector<double> ans(nquery);
  for (int i = 0; i < nquery; i++) {
    string dividend = queries[i][0];
    string divisor = queries[i][1];
    
    if (!nameToID.count(dividend)) {
      ans[i] = -1;
      continue;
    }
    if (!nameToID.count(divisor)) {
      ans[i] = -1;
      continue;
    }

    ans[i] = u.check(nameToID[dividend], nameToID[divisor]);
  }

  return ans;
}

int main() {
  vector<vector<string>> equations{{"a","b"},{"b","c"},{"bc","cd"}};
  vector<double> values{1.5,2.5,5.0};
  vector<vector<string>> queries{{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

  vector<double> ans = calcEquation(equations, values, queries);
  for (double d: ans) {
    cout << d << " ";
  }
  cout << endl;
}