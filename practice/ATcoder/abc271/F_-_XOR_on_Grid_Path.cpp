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

constexpr int N = 21;

int n; 
int g[N][N];
map<int, int> mp[N * N];
ll ret;

void dfs1(int i, int j, int step, int x) {
  if (step == n - 1) {
    mp[i * n + j][x] ++;
    return ;
  } 
  dfs1(i + 1, j, step + 1, x ^ g[i][j]);
  dfs1(i, j + 1, step + 1, x ^ g[i][j]);
}

void dfs2(int i, int j, int step, int x) {
  if (step == n - 1) {
    ret += mp[i * n + j][x ^ (g[i][j])];
    return ;
  } 
  dfs2(i - 1, j, step + 1, x ^ g[i][j]);
  dfs2(i, j - 1, step + 1, x ^ g[i][j]);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      cin >> g[i][j];
    }
  }
  
  dfs1(1, 1, 0, 0);
  dfs2(n, n, 0, 0);

  cout << ret;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}