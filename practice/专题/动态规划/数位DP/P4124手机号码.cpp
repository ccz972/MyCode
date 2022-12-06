// @created by Nanfeng1997
// @url https://www.luogu.com.cn/problem/P4124

#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int a[20];
int cnt;
ll dp[20][11][2][2][4][2][2];

ll dfs(int pos, int last, bool flag4, bool flag8, int now, bool lead, bool limit) {
  if(pos == cnt) {
    return now >= 3;
  }
  ll &ret = dp[pos][last][flag4][flag8][now][lead][limit];
  if(~ret) return ret;
  ret = 0;
  for(int i = 0; i <= (limit ? a[pos] : 9); i ++ ) {
    if((i == 4 && flag8) || (i == 8 && flag4))  continue;
    ret += dfs(pos + 1, i, flag4 | (i == 4), flag8 | (i == 8), now >= 3 ? now : (i == last ? now + 1 : 1), lead && !i, limit && (i == a[pos]));
    // ret += dfs(pos + 1, i, flag4 | (i == 4), flag8 | (i == 8),  min(now + (i == last), 3), lead && !i, limit && (i == a[pos]));
  }
  return ret;
}

ll solve(ll x) {
  cnt = 0;
  while(x) {
    a[cnt ++ ] = x % 10;
    x /= 10;
  }
  reverse(a, a + cnt);
  memset(dp, -1, sizeof dp);
  return dfs(0, 10, false, false, 0, true, true);
}

void solve() {
  ll l, r; cin >> l >> r;
  if(l == 10000000000ll) {
    cout << solve(r) - solve(l) + 1;
  } else {
    cout << solve(r) - solve(l - 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}