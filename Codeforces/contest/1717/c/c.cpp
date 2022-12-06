/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-09-02 22:35:26
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

constexpr int N = 4E5 + 10;

int a[N], b[N];
bool st[N];

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i ++ ) cin >> a[i], a[i + n] = a[i];
  for (int i = 0; i < n; i ++ ) cin >> b[i], b[i + n] = b[i];
  for (int i = 0; i < n; i ++ ) if (a[i] > b[i]) {
    cout << "NO\n";
    return ;
  }

  for (int i = 0; i < n; i ++ ) if (a[i] != b[i]) {
    if (b[i + 1] + 1 >= b[i]) {
      st[i] = true;
    } else {
      st[i] = false;
    }
  } else {
    st[i] = true;
  }

  int cnt = count(st, st + n, false);
  
  if (cnt > 0) {
    cout << "NO\n";
    return ;
  } else {
    cout << "YES\n";
  }

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
