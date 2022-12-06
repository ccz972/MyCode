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
    string s; 
    cin >> s;
    int cnt = 0;
    int n = s.size();
    for(int i = 0; i < n; i ++ ) {
      int j = i;
      map<char, int> mp;
      mp[s[i]] ++;
      int now = 1;
      while(j < n - 1 && now + (!mp[s[j + 1]]) <= 3) {
        ++ j;
        now += (!mp[s[j]]);
        mp[s[j]] ++;
      }
      i = j;
      // debug(i, j);
      cnt ++;
    }
    // debug("---");
    cout << cnt << "\n";
  }
  return 0;
}