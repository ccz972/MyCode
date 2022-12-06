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
  int n, m; 
  cin >> n >> m;
  vector<vector<int> > a(n);
  for (int i = 0; i < n; i ++ ) {
    int k; cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j ++ ) {
      cin >> a[i][j];
    }
  }
  while (m -- ) {
    int i, j; cin >> i >> j;
    -- i, -- j;
    cout << a[i][j] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}