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



int n, m;
ll val[N], f[N], sz[N];
vector<int> A, B, C;
vector<pair<int, int> > son[N];

void dfs1(int u, int fa) {
  for (auto &[v, w]: son[u]) if (v != fa) {
    dfs1(v, u);
    sz[u] += sz[v];
    val[u] += val[v] + sz[v] * w;
  }
}

void dfs2(int u, int fa) {
  ll sum = val[u] + f[u];
  for (auto &[v, w]: son[u]) if (v != fa) {
    f[v] = sum - val[v] - sz[v] * w + (m - sz[v]) * w;
    dfs2(v, u);
  }
}

ll get(vector<int> &a, vector<int> &b, ll ans = 0) {
  memset(val, 0, sizeof val);
  memset(f, 0, sizeof f);
  memset(sz, 0, sizeof sz);
  m = SZ(a);
  for (int &x: a) sz[x] = 1;
  dfs1(1, 0);
  dfs2(1, 0);
  for (int &x: b) ans += f[x] + val[x];
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i < n; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    son[u].eb(v, w); son[v].eb(u, w);
  }  
  cin >> m; 
  A.resize(m); for (int &x: A) cin >> x;
  cin >> m; 
  B.resize(m); for (int &x: B) cin >> x;
  cin >> m; 
  C.resize(m); for (int &x: C) cin >> x;
  
  ll mul = 1ll * SZ(A) * SZ(B) * SZ(C);

  ll sumab = get(A, B);
  ll sumac = get(A, C);
  ll sumbc = get(B, C);

  double ans = 0;

  ans += 1. * sumab / SZ(A) / SZ(B);
  ans += 1. * sumac / SZ(A) / SZ(C);
  ans += 1. * sumbc / SZ(B) / SZ(C);
  ans /= 2;
  
  cout << ans << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  cout << fixed << setprecision(10);
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}