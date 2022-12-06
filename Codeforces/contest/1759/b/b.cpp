/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-11-20 17:57:35
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

#define all(a) a.begin(), a.end()

void solve() {
  int n, s; cin >> n >> s;
  vector<int> a(n); for (int &x: a) cin >> x;

  int m = *max_element(all(a));

  int p = 0;
  for (int i = 1; i <= m; i ++ ) {
    p += i;
  }
  for (int x: a) p -= x;
  for (int i = m + 1; i <= 1000; i ++ ) {
    if (p == s) {
      return cout << "YES\n", void();
    }
    p += i;
  }

  cout << "NO\n";
  
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1; cin >> T;
  while (T --) solve();
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
