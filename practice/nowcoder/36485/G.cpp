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

constexpr int mod = 1e9 + 7;

void solve() {

  int n, k; cin >> n >> k;
  ++ k;

  vector f(n + 1, vector<int>(k + 1));
  vector sum(n + 1, vector<int>(k + 1));
  vector son(n, vector<int>());
  vector<ll> tmp(k + 1);
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
    son[v].push_back(u);
  } 

  function<void(int, int)> dfs = [&] (int u, int fa) {
    f[u][1] = 1;
    for (int i = 1; i <= k; i ++ ) sum[u][i] = (sum[u][i - 1] + f[u][i]) % mod;

    for (int v: son[u]) if(v != fa) {

      dfs(v, u);

      for (int j = 1; j <= k; j ++ ) {
        tmp[j] = f[u][j] * sum[v][k] % mod;
        tmp[j] = (tmp[j] + f[u][j]     * sum[v][min(j - 1, k - j)]     % mod) % mod;
        tmp[j] = (tmp[j] + f[v][j - 1] * sum[u][min(j - 1, k - j + 1)] % mod) % mod;
      }6


      for (int j = 1; j <= k; j ++ ) {
        f[u][j] = tmp[j];
        sum[u][j] = (sum[u][j - 1] + f[u][j]) % mod;
      }

    }
    
  };
  
  dfs(0, -1);

  ll ans = 0;
  for(int i = 1; i <= k; i ++ ) ans = (ans + f[0][i]) % mod;
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}