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



void solve() {
  int n; cin >> n;
  vector<int> d(n);
  vector son(n, vector<int>());

  rep(i, 1, n - 1) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    d[u] ++;
    d[v] ++;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  if(n == 1) {
    cout << "0\n";
    return ;
  }  else if(n == 2) {
    cout << "1\n";
    return ;
  }
  vector<int> f(n);
  function<void(int, int)> dfs = [&] (int u, int fa) {
    int cnt = 0;
    for(int v: son[u]) if(v != fa) {
      dfs(v, u);
      if(!f[v]) cnt ++;
      f[u] += f[v];
    }
    if(cnt > 2) f[u] ++ ;
  };  
  int ans = n;
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < n; j ++ ) f[j] = 0;
    dfs(i, -1);
    int cnt = 0;
    for(int j = 0; j < n; j ++ ) cnt += (f[j] > 0);
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}