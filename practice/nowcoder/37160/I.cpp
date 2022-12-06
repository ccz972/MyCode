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
  int n, m; cin >> n >> m;
  int left = -1, right = -1;
  string s(n, '?');
  for(int i = 0; i < m; i ++ ) {
    int idx; char c; cin >> idx >> c;
    idx --; s[idx] = c;
    if(c == 'L') {
      left = idx;
    } else {
      right = idx;
    }
  }

  vector<int> l(n, -1), r(n, -1);
  int now = left;
  while(now >= 0 && l[now] == -1) {
    l[now] = left;
    now = (now + n - 1) % n;
    if(s[now] == 'L') left = now;
  }

  now = right;
  while(now >= 0 && r[now] == -1) {
    r[now] = right;
    now = (now + 1) % n;
    if(s[now] == 'R') right = now;
  }

  int ans = 0;

  for(int i = 0; i < n; i ++ ) {
    int x = 1e9;
    if(l[i] != -1) {
      if(l[i] >= i) x = l[i] - i;
      else x = (l[i] + n - i);
    } 
    if(r[i] != -1) {
      if(r[i] <= i) chkmin(x, i - r[i]);
      else chkmin(x, i + n - r[i]);
    }
    chkmax(ans, x);
    // cout << x << " \n"[i == n - 1];
  }
  cout << ans ;

  return 0;
}