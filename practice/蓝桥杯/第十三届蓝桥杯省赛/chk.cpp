#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

void solve() {
  int n, m; cin >> n >> m;
  n += m;
  int ans = 0;
  for(int i = 0; i < (1 << n); i ++ ) {
    int now = 2, cnt = 0;
    for(int j = 0; j < n; j ++ ) if(i >> j & 1) {
      ++ cnt;
    }
    if(cnt != n - m) continue;
    bool flag = true;
    for(int j = n - 1; j >= 0 && flag; j -- ) {
      if(!(i >> j & 1)) {
        if(now <= 0) {
            flag = false;
          } else {
            -- now;
          }
        } else {
          now *= 2;
        }
    }
      

    if(flag && !now) {
      ++ ans;
      for(int j = n - 1; j >= 0; j -- ) 
        cout << (i >> j & 1);
      cout << "\n";
    }
  }
  cout << ans;
}

void gg() {
  string s = "010111000000001";
  int now = 2;
  for(char c: s) {
    if(c == '0') {
      now -- ;
    } else {
      now *= 2;
    }
    debug(now);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // solve();
  gg();
  return 0;
}