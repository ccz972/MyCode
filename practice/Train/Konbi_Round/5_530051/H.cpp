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

constexpr int N = 20;

int g[N][N];
ll f[1 << N][N];
//f[i][j]表示以i的lowbit为起点，j为终点的路径方案数，这样可以保证不重不漏
//然后状态转移（
void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++ ) {
    cin >> u >> v; -- u, -- v;
    g[u][v] = g[v][u] = 1;
  }
  for (int i = 0; i < 20; i ++ ) f[1 << i][i] = 1;
  ll ans = 0;
  for (int i = 1; i < 1 << n; i ++ ) {
    int now = i & -i;
    for (int j = 0; j < n; j ++ ) if ((1 << j) == now) { now = j; break; }
    for (int j = 0; j < n; j ++ ) if (f[i][j]) {
      if (g[now][j]) ans += f[i][j];
      for (int k = now + 1; k < n; k ++ ) if (!(i >> k & 1) && g[j][k]) {
        f[i | (1 << k)][k] += f[i][j];
      }
    }
  }

  ans = ans - m; 
  ans >>= 1;

  cout << ans << "\n";
  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}