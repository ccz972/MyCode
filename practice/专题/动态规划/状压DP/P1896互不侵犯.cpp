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

const int N = 10, M = 82, K = 1 << 10;

int n, m;
ll f[N][M][K];
vector<int> state;
vector<int> head[K];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;

  for(int i = 0; i < 1 << n; i ++ ) {
    bool flag = true;
    for(int j = 0; j < n && flag; j ++ ) {
      if((i >> j & 1) && (i >> j + 1 & 1)) {
        flag = false;
      }
    }
    if(flag) state.push_back(i);
  }

  for(int a: state) {
    // debug(a);
    for(int b: state) if(!(a & b) && !((a << 1) & b) && !((a >> 1) & b)) {
      head[a].push_back(b);
      // debug(a, b);
    }
  }
  for(int x: state) {
    f[1][__builtin_popcount(x)][x] = 1;
  }


  for(int i = 1; i < n; i ++ ) {
    for(int j = 0; j <= m; j ++ ) {
      for(int a: state) if(f[i][j][a]) {
        // debug(i, j, a, f[i][j][a]);
        for(int b: head[a]) {
          f[i + 1][__builtin_popcount(b) + j][b] += f[i][j][a];
          // if(i == 2) {
          //   debug(i + 1, __builtin_popcount(b) + j, b, f[i + 1][__builtin_popcount(b) + j][b]);
          // }
        }
      }
    }
  }

  ll ans = 0;

  for(int x: state) {
    ans += f[n][m][x];
  }
  cout << ans << "\n";

  return 0;
}