// Problem: E - Lucky Numbers
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

// constexpr int N = 1e5 + 10, M = 110, mod = 998244353;

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> s(n), l(m);
  rep(i, 1, n - 1) cin >> s[i];
  rep(i, 0, m - 1) cin >> l[i];
  map<ll, int> cnt;
  bool flag = true;
  ll now = 0;
  //a_1 = x
  //a_2 = s_1 - x 
  //a_3 = s_2 - s_1 + x 
  //a_4 = s_3 - (s_2 - s_1) - x
  auto add = [&] (bool flag, ll now) {
    if(flag) {
      //x + now == lucky
      rep(i, 0, m - 1) {
        cnt[l[i] - now] ++;
      }
    } else {
      rep(i, 0, m - 1) {
        cnt[now - l[i]] ++;
      }
    }
  }; 
  add(flag, now);
  rep(i, 1, n - 1) {
    flag ^= true;
    now = s[i] - now;
    add(flag, now);
  }
  int ans = 0;
  for(auto [k, v]: cnt) chkmax(ans, v);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;// cin >> T;
  while(T --) solve();

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
