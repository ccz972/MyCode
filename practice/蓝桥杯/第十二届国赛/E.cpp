#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
  string s; cin >> s;
  for(char &c: s) if(c >= 'a' && c <= 'z') c += ('A' - 'a');
  cout << s;
}

int main() {
  solve();
  return 0;
}