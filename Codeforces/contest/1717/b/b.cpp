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

constexpr int N = 510;

char s[N][N];
bool st[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void solve() {
  int n, k, r, c;
  cin >> n >> k >> r >> c;
  for (int i = 0; i <= n; i ++ ) {
    for (int j = 0; j <= n; j ++ ) {
      s[i][j] = '.';
      st[i][j] = false;
    }
  }
  -- r, -- c;
  s[r][c] = 'X';
  int p = r / k, q = c / k;
  int X = p * k, Y = q * k;
  r -= X, c -= Y;
  for (int p = 0; p < k; p ++ ) {
    s[X + ((r + p) % k)][Y + ((c + p) % k)] = 'X';
  }
  queue<pair<int, int> > Q;
  for (int i = X; i < X + k; i ++ ) {
    for (int j = Y; j < Y + k; j ++ ) if (s[i][j] == 'X') {
      Q.push(make_pair(i, j));
      st[i][j] = true;
    }
  }

  while (!Q.empty()) {
    auto t = Q.front(); Q.pop();
    // auto [sx, sy] = t;
    for (int i = 0; i < 4; i ++ ) {
      auto [nx, ny] = t;
      nx += dx[i] * k, ny += dy[i] * k;
      if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
        if (!st[nx][ny]) {
          Q.push(make_pair(nx, ny));
          s[nx][ny] = 'X';
          st[nx][ny] = true;
        }
      }
    }
  }

  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < n; j ++ ) {
      cout << s[i][j];
    }
    cout << "\n";
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
