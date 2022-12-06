/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-10-23 15:50:11
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

constexpr int N = 2E5 + 10;



void solve() {
  int n; cin >> n;

  vector<pair<int, int> > pos;
  for (int i = 1; i <= n; i ++ ) {
    int x; cin >> x;
    if (x) {
      pos.emplace_back(i, x);
    }
  }

  int m = pos.size();

  if (m & 1) return cout << "-1\n", void();

  if (pos.empty()) {
    cout << "1\n";
    cout << 1 << " " << n << "\n";
    return ;
  }

  vector<pair<int, int> > ans;

  if (pos.front().first != 1) {
    ans.emplace_back(1, pos.front().first - 1);
  }

  for (int i = 0; i < m; i += 2) {
    auto [i1, x1] = pos[i];
    auto [i2, x2] = pos[i + 1];
    if (x1 == x2) {
      if ((i1 & 1) == (i2 & 1)) {
        ans.emplace_back(i1, i2 - 2);
        ans.emplace_back(i2 - 1, i2);
      } else {
        ans.emplace_back(i1, i2);
      }
      
    } else {
      //1 -1
      if ((i1 & 1) != (i2 & 1)) {
        ans.emplace_back(i1, i2 - 1);
        ans.emplace_back(i2, i2);
      } else { //
        ans.emplace_back(i1, i2);
      }
    }
    if (i + 2 < m) {
      auto [i3, x3] = pos[i + 2];
      if (i3 != i2 + 1) {
        ans.emplace_back(i2 + 1, i3 - 1);
      }
    }
  }

  if (pos.back().first != n) {
    ans.emplace_back(pos.back().first + 1, n);
  }

  cout << ans.size() << "\n";
  for (auto [x, y]: ans) cout << x << " " << y << "\n";

  

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
