#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
  vector<int> candies(ratings.size());
  for (int i = 0; i < ratings.size() - 1; i++) {
    if (ratings[i] < ratings[i+1] && candies[i+1] < candies[i] + 1) {
      candies[i+1] = candies[i] + 1;
    } else if (ratings[i] > ratings[i+1] && candies[i] < candies[i+1]+1) {
      candies[i] = candies[i+1]+1;
    }
  }

  for (int i = ratings.size() - 1; i > 0; i--) {
    if (ratings[i-1] < ratings[i] && candies[i] < candies[i-1] + 1) {
      candies[i] = candies[i-1] + 1;
    } else if (ratings[i-1] > ratings[i] && candies[i-1] < candies[i]+1) {
      candies[i-1] = candies[i]+1;
    }
  }

  return accumulate(candies.begin(), candies.end(), candies.size());
}

int main() {
  vector<int> ratings{1, 6, 10, 8, 7, 3, 2};
  cout << candy(ratings) << endl;
  return 0;
}