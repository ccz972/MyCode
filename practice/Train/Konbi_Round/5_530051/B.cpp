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

vector<int> son[N];
int dep[N];
int f[N][3]; // 0/1/2 被自己、儿子、父亲 覆盖

void dfs1(int u, int fa) {
  for (int &v: son[u]) if (v != fa) {
    dep[v] = dep[u] + 1;
    if (dep[v] >= 2) f[v][0] = 1;
    dfs1(v, u);
  }
}

void dfs2(int u, int fa) {
  int sum = INF;
  for (int &v: son[u]) if (v != fa) {
    dfs2(v, u);
    f[u][2] += min(f[v][0], f[v][1]);
    f[u][0] += min({f[v][0], f[v][1], f[v][2]});
    if (f[v][1] > f[v][0]) f[u][1] += f[v][0], sum = 0;
    else f[u][1] += f[v][1], chkmin(sum, f[v][0] - f[v][1]);
  }
  f[u][1] += sum;
}



void solve() {
  int n; cin >> n;
  for (int i = 1, u, v; i < n; i ++ ) {
    cin >> u >> v;
    son[u].eb(v); son[v].eb(u);
  }
  dfs1(1, 0); dfs2(1, 0);
  cout << min(f[1][1], f[1][0]);
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}