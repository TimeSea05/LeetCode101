#include <iostream>
#include <vector>
using std::vector;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  vector<int> diag{mat[0][0]};
  if (n == 1) {
    for (int i = 1; i < m; i++) {
      diag.push_back(mat[i][0]);
    }
    return diag;
  }

  int direct = 1;  // 左下->右上: 0; 右上->左下: 1
  int inc[2][2] = {{-1,1},{1,-1}};

  int x = 0, y = 1;
  while (!(x == m-1 && y == n-1)) {
    while (x >= 0 && x < m && y >= 0 && y < n) {
      diag.push_back(mat[x][y]);
      x += inc[direct][0], y += inc[direct][1];
    }
    x -= inc[direct][0], y -= inc[direct][1];

    if (direct) {
      if (x == m-1) y++; else x++;
    } else {
      if (y == n-1) x++; else y++;
    }

    direct = !direct;
  }

  diag.push_back(mat[m-1][n-1]);
  return diag;
}

int main() {
  vector<vector<int>> mat{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  auto v = findDiagonalOrder(mat);
  for (auto i: v) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
