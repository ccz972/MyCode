#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

void solve() {
  string s;
  while(getline(cin, s)) {
    cout << "\"";
    for(char c: s) {
      if(c == '\"') {
        cout << "\\";
      } else {
        cout << c;
      }
    }
    cout << "\",";
    cout << "\n";
  }
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  freopen("x.txt", "w", stdout);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}

