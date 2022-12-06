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

void solve() {
  int n = 4;
  vector<array<double, 5> > point(n);
  point[0] = {1, 1, 0.8, 0.5, 0};
  point[1] = {2, 2, 1.6, 1.0, 0};
  point[2] = {3, 3, 2.4, 1.5, 0};
  point[3] = {5, 5, 2.5, 2, 0};
  double ans = 0;
  double ret = 0;
  double bk1 = 0, bk2 = 0;
  vector<double> extra{1, 0.5, 0.4, 0.3, 0};
  
  vector<array<int, 5> > a(n);
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < 5; j ++ ) {
      cin >> a[i][j];
      ans += point[i][j] * a[i][j];
      ret += point[i][0] * a[i][j];
      if(i == 3) {
        bk1 += extra[0] * a[i][j];
        bk2 += extra[j] * a[i][j];
      }
    } 
  }

  double res = 100 * ans / ret + 100 * bk2 / (bk1 * 100);

  cout << fixed << setprecision(10) << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}