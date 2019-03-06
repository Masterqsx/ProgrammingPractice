#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> find_match(string &p){
  vector<int> match = vector<int>(p.size(), 0);
  for (int i=1, j=0;i<p.size();i++){
    while (j != 0 && p[j] != p[i]) j = match[j-1];
    if (p[j] == p[i]) match[i] = (j++) + 1;
    else match[i] = j;
  }
  return match;
}

string kmp(string s, string p){
  if (p.size() > s.size() || p.empty() || s.empty()) return string();
  vector<int> match = find_match(p);
  int i = 0, j = 0;
  for (;i<=s.size();i++){
    if (j == p.size()) return s.substr(i - p.size());
    while (j != 0 && s[i] != p[j]) j = match[j-1];
    if (s[i] == p[j]) j++;
  }
  if (j == p.size()) return s.substr(i - p.size());
  return string();
}

int main(int argc, char **argv){
  if (argc != 3) return 0;
  cout << kmp(string(argv[1]), string(argv[2])) << endl;
  return 0;
}
