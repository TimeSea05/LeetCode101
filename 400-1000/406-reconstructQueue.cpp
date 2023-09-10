#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Solution:
  先对输入数组排序，h升序，k降序，从头循环遍历，
  当前这个人就是剩下未安排的人中最矮的人，他的k值就代表他在剩余空位的索引值，
  如果有多个人高度相同，要按照k值从大到小领取索引值
  示例：
  [ 0, 1, 2, 3, 4, 5 ] [ 4, 4 ] 4
  [ 0, 1, 2, 3, 5 ]    [ 5, 2 ] 2
  [ 0, 1, 3, 5 ]       [ 5, 0 ] 0
  [ 1, 3, 5 ]          [ 6, 1 ] 3
  [ 1, 5 ]             [ 7, 1 ] 5
  [ 1 ]                [ 7, 0 ] 1
  [ [ 5, 0 ], [ 7, 0 ], [ 5, 2 ], [ 6, 1 ], [ 4, 4 ], [ 7, 1 ] ]
*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  sort(people.begin(), people.end(), [](vector<int>& person1, vector<int>& person2) {
    if (person1[0] != person2[0]) {
      return person1[0] < person2[0];
    } else {
      return person1[1] > person2[1];
    }
  });

  vector<vector<int>> res(people.size());
  vector<bool> occupied(people.size());

  for (int i = 0; i < people.size(); i++) {
    int index = people[i][1];
    for (int j = 0; j < occupied.size(); j++) {
      if (j <= index) {
        if (occupied[j]) index++;
      } else {
        break;
      }
    }

    res[index] = people[i];
    occupied[index] = true;
  }

  return res;
}

void print2DArray(vector<vector<int>>& v) {
  printf("{");
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) printf(",");
    printf("{%d,%d}", v[i][0], v[i][1]);
  }
  printf("}\n");
}

int main() {
  vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  vector<vector<int>> v = reconstructQueue(people);
  print2DArray(v);
  return 0;
}