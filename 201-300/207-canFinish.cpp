#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> indegrees(numCourses);
  vector<vector<int>> graph(numCourses);

  for (int i = 0; i < int(prerequisites.size()); i++) {
    int dest = prerequisites[i][0], src = prerequisites[i][1];
    graph[src].push_back(dest);
    indegrees[dest]++;
  }

  queue<int> zeroIndegreesQueue;
  for (int i = 0; i < numCourses; i++) {
    if (indegrees[i] == 0) {
      zeroIndegreesQueue.push(i);
    }
  }

  int learned = 0;
  while (!zeroIndegreesQueue.empty()) {
    int course = zeroIndegreesQueue.front();
    zeroIndegreesQueue.pop();
    learned++;

    for (int i = 0; i < int(graph[course].size()); i++) {
      int nextCourse = graph[course][i];
      indegrees[nextCourse]--;
      if (indegrees[nextCourse] == 0) {
        zeroIndegreesQueue.push(nextCourse);
      }
    }
  }

  return learned == numCourses;
}

int main() {
  vector<vector<int>> prerequisites{{1,0},{0,1}};
  std::cout << (canFinish(2, prerequisites) ? "true" : "false") << std::endl;
}