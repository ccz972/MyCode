/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-09-29 22:35:13
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

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      bool flag = true;
      for (int k = 0; k < 8; k ++ ) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m) flag = false;
      }
      if (flag) {
        cout << i << " " << j << "\n";
        return ;
      }
    }
  }

  cout << "1 1\n";
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
