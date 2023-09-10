#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
  map<char, int> map_t;
  for (int i = 0; i < t.size(); i++) {
      map_t[t[i]]++;
  }

  map<char, int> map_s;
  int p1 = 0, p2 = 0;
  int min_length = INT_MAX, min_p1 = 0, min_p2 = 0; 
  while (p2 < s.size()) {
      map_s[s[p2]]++;
      
      // 判断子字符串是否已经覆盖t
      bool cover = true;
      for (auto it = map_t.begin(); it != map_t.end(); it++) {
          if (map_s[(*it).first] < (*it).second) {
              cover = false;
              break;
          }
      }

  if (cover) {
      while (map_s[s[p1]] > map_t[s[p1]]) map_s[s[p1++]]--;
      if (min_length > p2 - p1 + 1) {
          min_length = p2 - p1 + 1;
          min_p1 = p1, min_p2 = p2;
      }
  }
  p2++;    
        }

        string res = "";
        if (min_length == INT_MAX) {
            return res;
        }

        for (int i = min_p1; i <= min_p2; i++) {
            res.push_back(s[i]);
        }
        return res;
    }