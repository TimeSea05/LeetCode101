#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
  int n = prices.size();

  vector<int> withoutShares(n);
  vector<int> withShares(n);
  withoutShares[0] = 0, withShares[0] = -prices[0];

  for (int i = 1; i < n; i++) {
    withoutShares[i] = max(withoutShares[i-1], withShares[i-1] + prices[i] - fee);
    withShares[i] = max(withShares[i-1], withoutShares[i-1] - prices[i]);
  }

  return withoutShares.back();
}

int main() {
  vector<int> prices{1,3,7,5,10,3};
  cout << maxProfit(prices, 3) << endl;
  return 0;
}