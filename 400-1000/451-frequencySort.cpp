#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Uppercase Letters: 26
// Lowercase Letters: 26
// Digits: 10

struct entry {
  char c;
  int times;
};

string frequencySort(string s) {
  vector<entry> bucket(62);

  for (int i = 0; i < 26; i++) {
    bucket[i].c = 'A' + i;
  }
  for (int i = 0; i < 26; i++) {
    bucket[i+26].c = 'a' + i;
  }
  for (int i = 0; i < 10; i++) {
    bucket[i+52].c = '0' + i;
  }

  for (int i = 0; i < s.size(); i++) {
    if (isupper(s[i])) {
      bucket[s[i] - 'A'].times++;
    } else if (islower(s[i])) {
      bucket[s[i] - 'a' + 26].times++;
    } else {
      bucket[s[i]-'0'+52].times++;
    }
  }

  sort(bucket.begin(), bucket.end(), [](entry a, entry b) {
    return a.times > b.times;
  });

  int i = 0;
  for (int j = 0; j < bucket.size(); j++) {
    for (int k = 0; k < bucket[j].times; k++) {
      if (bucket[j].times == 0) {
        return s;
      }
      s[i++] = bucket[j].c;
    }
  }

  return s;
}

int main() {
  cout << frequencySort("Aabb") << endl;
  return 0;
}