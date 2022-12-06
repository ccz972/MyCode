#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i++)
#define Rep(i, a, b) for (int i(a); i < (b); i++)
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int>

mt19937 rng(random_device{}());
int rnd(int x) { return rng() % x; }

constexpr int N = 1E5 + 10;
ll n, w[N], t[N];
bool vis[N];
vector<int> son[N];

// g[i]表示在i的子树中选，且不选i处的蝴蝶的最大价值
// f[i]表示在i的子树中选，且选i处的蝴蝶的最大价值
// h[i]表示在i的子树中选，且选i处的蝴蝶且所有的儿子都不选的最大价值

// h[i] = \sum g[i]
// f[i] = h[j] + f[j] + \sum g[j] + w[i]
// g[i] = h[j] + g[j] + \sum g[j]
ll f[N], g[N], h[N];
void dfs1(int u, int fa) {
ll sumg = 0, mx = 0;
f[u] = h[u] = w[u];
ll mx1 = -1e18, mx2 = -1e18;

for (int &v : son[u]) if (v != fa) {
   dfs1(v, u);
   h[u] += f[v] - w[v];
   chkmax(mx, w[v]);

   ll tmp = h[v] - f[v] + w[v];
   if (mx1 < tmp) mx2 = mx1, mx1 = tmp;
   else if (mx2 < tmp) mx2 = tmp;
    
  }

f[u] = h[u] + mx;
for (auto v : son[u])
  if (v != fa)
  {
    if (t[v] == 3) 
   {
       if (h[v] - f[v] + w[v] == mx1) f[u] =
          max(f[u], h[u] + w[v] + mx2);
       else f[u] = max(f[u], h[u] + w[v] + mx1);
     
    }
  
  }
 // cout<<u<<": "<<"f[u]: "<<f[u]<<" g[u]: "<<g[u]<<" h[u]: "<<h[u]<<'\n';
}

 void solve() {
 cin >> n;
 rep(i, 1, n) {
    son[i].clear();
    f[i] = g[i] = h[i] = 0;
  }
 rep(i, 1, n) cin >> w[i];
 rep(i, 1, n) cin >> t[i];
 Rep(i, 1, n) {
    int u, v;
    cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  
  }

 dfs1(1, 0);
 cout << f[1] << "\n";
  
}

 int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T = 1;
 cin >> T;
 while (T--)
  solve();
 return 0;
  
}
