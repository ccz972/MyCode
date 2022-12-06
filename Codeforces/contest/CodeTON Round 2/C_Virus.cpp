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
  int n, m; cin >> n >> m;
  vector<int> a(m); for(int &x: a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> x(m);
  x[0] = a[0] + n - a.back() - 1;
  for(int i = 1; i < m; i ++ ) {
    x[i] = a[i] - a[i - 1] - 1;
  }
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());

  int now = 0, day = 0;

  for(int i = 0; i < m; i ++ ) {
    if(x[i] <= day * 2) break;
    now += max(1, x[i] - day * 2 - 1);
    day += 2;
  }
  cout << n - now << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}