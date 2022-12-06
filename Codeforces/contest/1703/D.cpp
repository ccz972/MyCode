#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<string> s(n);
    map<string, int> mp;
    for(auto &x: s) cin >> x, mp[x] ++;
    for(int i = 0; i < n; i ++ ) {
      int m = s[i].size();
      if(m == 1) {
        cout << "0";
        continue;
      }
      
      string t;
      bool f = false;
      for(int j = 0; j < m - 1 && !f; j ++ ) {
        t += s[i][j];
        string u = s[i].substr(j + 1, m);
        if(mp[t] && mp[u]) {
          f = 1;
        }
      }
      cout << f;
    }
    cout << "\n";
    
  }
  return 0;
}