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

const int N = 2e5 + 10;

vector<int> son[N];

ll ans[N];
int d[N];
int depth[N];
int fa[N][20];
int q[N];
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
        // father[v] = u;
        depth[v] = depth[u] + 1;
        fa[v][0] = u;
        for(int k = 1; k < 20; k ++ ) {
          fa[v][k] = fa[fa[v][k - 1]][k - 1];
        }
        q[++ tt] = v;
      }
    }
  }
   
}

int lca(int a, int b) {
  if(depth[a] < depth[b]) swap(a, b);
  for(int k = 19; k >= 0; k -- ) {
    if(depth[fa[a][k]] >= depth[b]) {
      a = fa[a][k];
    }
  }

  if(a == b) return a;

  for(int k = 19; k >= 0; k -- ) {
    if(fa[a][k] != fa[b][k]) {
      a = fa[a][k];
      b = fa[b][k];
    }
  }
  return fa[a][0];

}


void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x; //mp[x] ++;
  if(n == 1) {
    cout << "YES\n";
    return ;
  }
  int x = a[0], y = a[1];

  auto dis = [&] (int X, int Y) {
    return depth[X] + depth[Y] - 2 * depth[lca(X, Y)];
  };

  for(int i = 2; i < n; i ++ ) {
    int z = a[i];
    vector<int> l(3);
    l[0] = dis(x, y), l[1] = dis(y, z), l[2] = dis(x, z);
    auto r = l;
    sort(l.begin(), l.end());
    if(l[0] + l[1] != l[2]) {
      cout << "NO\n";
      return ;
    }

    if(r[1] == l.back()) {
      x = y;
      y = z;
    } else if(r[2] == l.back()) {
      y = z;
    }
  }

  cout << "YES\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  bfs(1);
  int Q; cin >> Q;
  while(Q -- ) solve();


  return 0;
}