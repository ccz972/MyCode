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

constexpr int N = 1E3 + 10;

int a[N][N];

void solve() {
  int n, p; cin >> n >> p;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= n; j ++ ) {
      cin >> a[i][j];
    }
  }
  int m = n % p;
  for(int i = 1; i <= n; i ++ ) {
    if(i <= m) cout << a[i][i] << " ";
    else cout << "0 ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}