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

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

char s[100];
int n, cnt, a[100];
ll dp[25][4][2][2];

ll dfs(int pos, int len, bool flag, bool lead) {
  if (pos == n) {
    // cout << len << "\n";
    return len == 3;
  } 
  ll &ret = dp[pos][len][flag][lead];
  if (~ret) return ret; ret = 0;
  for (int i = 0; i <= (flag ? min(a[pos], 1) : 1); i ++ ) {
    ret += dfs(pos + 1, (i == 1) ? min(3, len + 1) : (len >= 3 ? 3 : 0), flag && (i == a[pos]), lead && !i);
  } 
  return ret;
}
//111
//111


void solve() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i ++ ) a[i] = (s[i] - '0');
  memset(dp, -1, sizeof dp);
  cout << dfs(0, 0, true, true);
}

int main() {
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}