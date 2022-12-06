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

constexpr int N = 1e5 + 10, M = 1 << 20;

int a[N], f[M];
int s[20][N];
int mx[20];
int main() {

  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    a[i] --;
    for(int j = 0; j < m; j ++ ) {
      s[j][i] = s[j][i - 1] + (a[i] == j);
    }
    chkmax(mx[a[i]], i);
  }

  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for(int i = 0; i < 1 << m; i ++ ) {
    int cnt = 0;
    for(int j = 0; j < m; j ++ ) if(i >> j & 1) {
      cnt += s[j][n];
    }
    for(int j = 0; j < m; j ++ ) if(not(i >> j & 1)) {
      int l = cnt, r = cnt + s[j][n];
      chkmin(f[i ^ (1 << j)], f[i] + r - l - (s[j][r] - s[j][l]) );
    }
  }
  cout << f[(1 << m) - 1] << "\n";


  return 0;
}