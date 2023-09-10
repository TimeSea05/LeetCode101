#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int placed = 0;
  bool canPlace = false;
  for (int i = 0; i < flowerbed.size(); i++) {
    canPlace = false; 
    if (flowerbed[i] == 0) {
      if (i == 0) {
        if (flowerbed.size() == 1) {
          canPlace = true;
        } else if (flowerbed[i+1] == 0) {
          canPlace = true;
        }
      } else if (i == flowerbed.size() - 1) {
        if (flowerbed[i-1] == 0) {
          canPlace = true;
        }
      } else {
        if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
          canPlace = true;
        }
      }

      if (canPlace) {
        flowerbed[i] = 1;
        placed++;
      }
    }
  }

  return placed >= n;
}

int main() {
  vector<int> flowerbed{1,0,0,0,1};
  cout << canPlaceFlowers(flowerbed, 2) << endl;
  return 0;
}
