// Problem: F - Pre-order and In-order
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1), pos(n + 1);
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i], pos[b[i]] = i;
  if(a[1] != 1) {
    cout << "-1\n";
    return ;
  }
  vector<array<int, 2> > ans(n + 1);
  int now = 0;
  function<int(int, int)> dfs = [&] (int l, int r) {
    if(l == r) {
      if(pos[a[++ now]] != l) {
        cout << "-1\n";
        exit(0);
      }
      return a[now];
    } else {
      int root = a[++ now], mid = pos[root];
      debug(l, r, mid);
      if(l <= mid - 1) ans[root][0] = dfs(l, mid - 1);
      if(mid + 1 <= r) ans[root][1] = dfs(mid + 1, r);
      return root;
    }
  };
  dfs(1, n);
  rep(i, 1, n) {
    cout << ans[i][0] << " " << ans[i][1] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
