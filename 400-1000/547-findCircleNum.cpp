#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int vertex) {
  visited[vertex] = true;
  for (int i = 0; i < isConnected.size(); i++) {
    if (isConnected[vertex][i] && !visited[i]) {
      dfs(isConnected, visited, i);
    }
  }
}

int findCircleNum(vector<vector<int>>& isConnected) {
  vector<bool> visited(isConnected.size());
  int circles = 0;

  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      dfs(isConnected, visited, i);
      circles++;
    }
  }

  return circles;
}

int main() {
  vector<vector<int>> isConnected{{1,0,0},{0,1,0},{0,0,1}};
  cout << findCircleNum(isConnected) << endl;
  return 0;
}