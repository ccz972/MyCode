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
    map<char, int> mp;
    int n; cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(char c: s) {
      if(mp[c]) ans ++;
      else ans += 2;
      mp[c] ++;
    }
    cout << ans << "\n";
  }
  return 0;
}