#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
constexpr int N = 2E5 + 10;


int n;
vector<pair<int, int> > son[N];
int f[N], g[N], sz[N], ans[N];

void dfs(int u, int fa) {
  sz[u] = 1;
  for (auto &[v, w]: son[u]) if (v != fa) {
    dfs(v, u);
    f[u] += f[v] + w;
    sz[u] += sz[v];
  }
}

void DFS(int u, int fa) {
  for (auto &[v, w]: son[u]) if (v != fa) {
    g[v] = g[u] + f[u] - f[v];
    if (w) g[v] --;
    else g[v] ++;
    DFS(v, u);
  }
}

void solve() {
  cin >> n; 
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v, 1); son[v].emplace_back(u, 0);
  }
  dfs(1, 0);
  DFS(1, 0);

  int mi = INT_MIN;

  for (int i = 1; i <= n; i ++ ) {
    ans[i] = f[i] + g[i];
    chkmax(mi, ans[i]);
  }

  cout << n - 1 - mi << "\n";
  for (int i = 1; i <= n; i ++ ) if (ans[i] == mi) {
    cout << i << " ";
  }

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}