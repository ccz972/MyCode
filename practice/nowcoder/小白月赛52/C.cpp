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
  vector<ll> s(n + 10);
  rep(i, 1, m) {
    int op, x, y; cin >> op;
    if(op == 1) {
      cin >> x >> y;
      s[1] ++;
      s[x] --;
      s[y + 1] ++;
      s[n + 1] --;
      // s[x] ++;
      // s[y + 1] -- ;
    } else if(op == 2) {
      cin >> x;
      s[1] ++;
      s[x] --;
      // s[x] ++;
      // s[n + 1] --;
    } else {
      cin >> x;
      s[x + 1] ++;
      s[n + 1] --;
      // s[1] ++;
      // s[x + 1] --;
    }
  }
  ll mx = 0;
  rep(i, 1, n) {
    s[i] += s[i - 1];
    mx = max(mx, s[i]);
  }
  cout << mx << " ";
  int cnt = 0;
  rep(i, 1, n) {
    if(s[i] == mx) {
      ++ cnt;
    }
  }
  cout << cnt ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}