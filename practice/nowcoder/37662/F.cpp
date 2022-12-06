/***************************************************

@File    : F.cpp
@Time    : 2022/07/14 23:56:46
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

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

const double pi = acos(-1);
double alpha;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;

  struct TPoint {double x, y; };
  auto swap = [&] (TPoint a, TPoint b) {
    TPoint tmp; tmp.x = b.x, tmp.y = b.y;
    b.x = a.x, b.y = a.y;
    a.x = tmp.x, a.y = tmp.y;
  };
  while (T--) {
    TPoint a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if(a.x > b.x) swap(a, b);
    TPoint p = {b.x - a.x, b.y - a.y};
    TPoint tmp;
    alpha = pi / 3.0;
    tmp.x = p.x * cos(alpha) - p.y * sin(alpha);
    tmp.y = p.y * cos(alpha) + p.x * sin(alpha);
    ///tmp
    vector<double> ans(2);
    ans[0] = a.x + tmp.x;

    alpha = -pi / 3.0;
    tmp.x = p.x * cos(alpha) - p.y * sin(alpha);
    tmp.y = p.y * cos(alpha) + p.x * sin(alpha);
    ans[1] = a.x + tmp.x;
    sort(ans.begin(), ans.end());
    for(auto x: ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}