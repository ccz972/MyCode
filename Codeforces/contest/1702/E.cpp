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

const int N = 2e5 + 10, M = N << 1;

vector<int> g[N];
int st[N];
bool flag = true;
bool dfs(int u) {
  for(int v: g[u]) {
    if(!st[v]) {
      st[v] = 3 - st[u];
      if(!dfs(v)) return false;
    } else if(st[v] == st[u]) return false;
  }
  return true;
    
}
#define all(x) begin(x), end(x)

void solve() {
  int n, m; cin >> n ;
  vector<int> cnt(n + 1);
  for(int i = 0; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    cnt[u] ++;
    cnt[v] ++;
    if(cnt[u] > 2 || cnt[v] > 2 || u == v) flag = false;
  }

  for(int i = 1; i <= n;  i ++ ) {
    sort(all(g[i]));
    g[i].erase(unique(all(g[i])), g[i].end());
  }

  for(int i = 1; i <= n && flag; i ++ ) {
    if(st[i] == 0) {
      if(!dfs(i)) {
        flag = false;
      }
    }
  }

  if(flag) cout << "YES\n";
  else cout << "NO\n";
  
  for(int i = 1; i <= n; i ++ ) g[i].clear(), st[i] = false;
  flag = true;

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}