#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

string startWord;
string lastWord;

bool isOneCharDiff(string word1, string word2) {
  int diff = 0, len = word1.size();
  for (int i = 0; i < len; i++) {
    if (word1[i] != word2[i]) {
      diff++;
    }
  }

  return diff == 1;
}

void getPaths(vector<string>& temp, vector<vector<string>>& res, vector<string>& wordList, vector<int>& dist, vector<vector<int>>& fathers, int index) {
  if (dist[index] == 1) {
    temp.push_back(wordList[index]);

    vector<string> path(temp.size() + 2);
    path[0] = startWord;
    for (int i = 1; i < path.size() - 1; i++) {
      path[i] = temp[temp.size() - i];
    }
    path[path.size() - 1] = lastWord;
    res.push_back(path);

    temp.pop_back();
    return;
  }

  for (int i = 0; i < fathers[index].size(); i++) {
    temp.push_back(wordList[index]);
    getPaths(temp, res, wordList, dist, fathers, fathers[index][i]);
    temp.pop_back();
  }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
  startWord = beginWord, lastWord = endWord;
  vector<vector<string>> res;
  vector<int> dist(wordList.size());
  vector<vector<int>> fathers(wordList.size());
  vector<string> temp;

  queue<int> q; // store index of words
  stack<string> s;  // store strings in the path

  for (int i = 0; i < wordList.size(); i++) {
    if (isOneCharDiff(beginWord, wordList[i])) {
      dist[i] = 1;
      q.push(i);
    }
  }

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    if (wordList[index].compare(endWord) == 0) {
      if (fathers[index].size() == 0) {
        res.push_back(vector<string>{beginWord, endWord});
      } else {
        for (int i = 0; i < fathers[index].size(); i++) {
          getPaths(temp, res, wordList, dist, fathers, fathers[index][i]);
        }
      }
    }

    for (int i = 0; i < wordList.size(); i++) {
      if (isOneCharDiff(wordList[index], wordList[i]) && (dist[i] == 0 || dist[i] == dist[index]+1) && wordList[i].compare(startWord) != 0) {
        if (dist[i] == 0) {
          dist[i] = dist[index] + 1;
          q.push(i);
        }
        fathers[i].push_back(index);
      }
    }
  }

  return res;
}

void print2DStringVector(vector<vector<string>>& res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    if (i != 0) cout << ",";
    cout << "[";
    for (int j = 0; j < res[0].size(); j++) {
      if (j != 0) cout << ",";
      cout << "\"" << res[i][j] << "\"";
    }
    cout << "]";
  }
  cout << "]\n";
}

int main() {
  vector<string> wordList{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim"};
  auto res = findLadders("cet", "ism", wordList);
  print2DStringVector(res);

  return 0;
}