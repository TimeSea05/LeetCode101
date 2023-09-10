#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  vector<int> degrees(n);
  vector<vector<int>> adjMatrix(n);
  vector<bool> removed(n);

  for (int i = 0; i < edges.size(); i++) {
    int first = edges[i][0];
    int second = edges[i][1];

    degrees[first]++;
    degrees[second]++;
    adjMatrix[first].push_back(second);
    adjMatrix[second].push_back(first);
  }

  int remain = n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (degrees[i] == 1) {
      q.push(i);
    }
  }

  while (remain > 2) {
    remain -= q.size();

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      degrees[node]--;
      for (int i = 0; i < adjMatrix[node].size(); i++) {
        if (!removed[adjMatrix[node][i]]) {
          degrees[adjMatrix[node][i]]--;
        }
      }

      removed[node] = true;
    }

    for (int i = 0; i < n; i++) {
      if (degrees[i] == 1) {
        q.push(i);
      }
    }
  }

  vector<int> roots;
  if (q.empty()) {
    for (int i = 0; i < n; i++) {
      if (!removed[i]) {
        roots.push_back(i);
        break;
      }
    }
  } else {
    while (!q.empty()) {
      roots.push_back(q.front());
      q.pop();
    }
  }

  return roots;
}

int main() {
  int n = 1;
  vector<vector<int>> edges{};
  auto res = findMinHeightTrees(n, edges);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}