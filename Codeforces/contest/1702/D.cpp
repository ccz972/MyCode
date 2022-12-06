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
    string s; cin >> s;
    string t; t = s;
    int n = s.size();
    int p; cin >> p;
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    int res = 0;
    for(char c: t) {
      res += (c - 'a') + 1;
    }
      
    vector<int> cnt(27);
    // debug(s, res);
    for(int i = 0; i < n; i ++ ) {
      if(res <= p) break;
      int now = (t[i] - 'a') + 1;
      res -= now;
      // debug(res);
      cnt[now] ++;
    }
    // cout << res << " " << p << "\n";
    // for(int i = 0; i < 27; i ++ ) {
    //   cout << cnt[i] << " ";
    // }
    // cout << "\n";
    for(int i = 0; i < n; i ++ ) {
      int now = (s[i] - 'a') + 1;
      if(cnt[now]) {
        cnt[now] --;
      } else {
        cout << s[i];
      }
    }

    cout << "\n";
  }
  return 0;
}