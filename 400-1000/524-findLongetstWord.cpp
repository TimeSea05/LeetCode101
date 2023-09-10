#include <iostream>
#include <vector>
using namespace std;

string findLongestWord(string s, vector<string>& dictionary) {
  string match = "";
  for (int i = 0; i < dictionary.size(); i++) {
    int p1 = 0, p2 = 0;
    while (p1 < s.size() && p2 < dictionary[i].size()) {
      if (s[p1] == dictionary[i][p2]) p2++;
      p1++;
    }

    // match success
    if (p2 == dictionary[i].size()) {
      if (match.size() < dictionary[i].size() ||
          match.size() == dictionary[i].size() && match.compare(dictionary[i]) > 0) {
            match = dictionary[i];
          }
    }
  }

  return match;
}

int main() {
  string s = "wordgoodgoodgoodbestword";
  vector<string> dict{"word", "good", "best", "good"};

  cout << findLongestWord(s, dict) << endl;
  return 0;
}