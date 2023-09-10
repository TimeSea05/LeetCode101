#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size() / 2; i++) {
    int start = i, end = matrix.size()-1 - start;
    swap(matrix[start][start], matrix[start][end]);
    swap(matrix[start][start], matrix[end][end]);
    swap(matrix[start][start], matrix[end][start]);

    for (int j = start+1; j < end; j++) {
      swap(matrix[start][j], matrix[j][end]);
      swap(matrix[start][j], matrix[end][matrix.size()-1-j]);
      swap(matrix[start][j], matrix[matrix.size()-1-j][start]);
    }
  }
}

void printMatrix(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<vector<int>> matrix{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
  printMatrix(matrix);

  rotate(matrix);
  printMatrix(matrix);

  vector<vector<int>> ans{{21,16,11,6,1},{22,17,12,7,2},{23,18,13,8,3},{24,19,14,9,4},{25,20,15,10,5}};
  printMatrix(ans);
  return 0;
}