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

constexpr int N = 2E6 + 10;

int fa[N][22];
int depth[N], q[N], w[N], ans[N];
vector<int> son[N];
int s[N];

void bfs(int root) {
  memset(depth, 0x3f, sizeof depth);
  depth[0] = 0, depth[root] = 1;
  int hh = 0, tt = 0; q[0] = root;
  while(hh <= tt) {
    int u = q[hh ++ ];
    int num = son[u].size();
    for(int i = 0; i < num; i ++ ) {
      int v = son[u][i];
      
      if(depth[v] > depth[u] + 1) {
        depth[v] = depth[u] + 1;
        fa[v][0] = u;
        for(int k = 1; k < 22; k ++ ) {
          fa[v][k] = fa[fa[v][k - 1]][k - 1];
        }
        q[++ tt] = v;
      }
    }
  }
}

int get(int u, int len) {
  for(int i = 21; i >= 0; i -- ) if(depth[fa[u][i]] >= len) {
    u = fa[u][i];
  }
  return u;
}

void dfs(int u, int fa) {
  for(auto& v: son[u]) if(v != fa) {
    int p = depth[v] - w[v];
      int mx = get(v, max(0, p - 1));
      s[mx] --;
      s[v] ++;
    
    dfs(v, u);
  }
}

void dfs1(int u, int fa) {
  for(auto& v: son[u]) if(v != fa) {
    
    dfs1(v, u);
    s[u] += s[v];
  }
  ans[u] = s[u];
}


void solve() {
  int n; cin >> n;
  for (int i = 1, u, v; i < n; i++ ) {
    cin >> u >> v; //u --, v --;
    son[u].push_back(v), son[v].push_back(u);
  }
  for(int i = 1; i <= n; ++ i) cin >> w[i];
  bfs(1);
  dfs(1, -1);
  dfs1(1, -1);  
  ans[1] ++;
  for(int i = 1; i <= n; ++ i) cout << ans[i] << " ";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}