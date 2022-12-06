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

constexpr int N = 6E3 + 1;

int a[N];
int f[N][N];
int ans[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  ll ret = 0;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = i + 1; j <= n; j ++ ) {
      f[i][j] = f[i][j - 1] + (a[j] < a[i]);
    }
    ret += f[i][n];
  }


  for(int j = n; j >= 1; j -- ) {
    for(int i = j - 1; i >= 1; i -- ) {
      ans[i][j] = ans[i + 1][j] + (f[i][j]);
    }
  }

  // cout << ret << "\n";
  
  int q; cin >> q;
  while(q -- ) {
    int l, r; cin >> l >> r;
    ll len = r - l + 1;
    ll all = len * (len - 1) / 2;
    cout << ret - ans[l][r] + all - ans[l][r] << "\n";
  }

  return 0;
}