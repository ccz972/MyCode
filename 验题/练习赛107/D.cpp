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
// constexpr int N = 2E5 + 10;
struct DSU {
  vector<int> f, siz, rank;
  int cnt; //统计还剩多少个连通块
  DSU(int n) : cnt(n), f(n), rank(n, 0), siz(n, 1) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return -1;
    else -- cnt;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; //按秩合并 and 路径压缩 
 
void getSerect() {
  
  int n = 7;
  bool vis[n + 1][n + 1
  ];
  int m = n * n;
  int ok = 100;
  for (int i = 0; i < 1 << m; i ++ ) if (__builtin_popcount(i) == m / 2) {
    memset(vis, false, sizeof vis);
    for (int j = 0; j < m; j ++ ) if (i >> j & 1) {
        vis[j / n][j % n] = true;
    }
    DSU d(m + 10);
    bool flag = true;
    for (int j = 0; j < n && flag; j ++ ) {
      for (int k = 0; k < n && flag; k ++ ) if (vis[j][k]) {
        int now = j * n + k;
        if (j + 1 < n && vis[j + 1][k]) {
          if (d.same(now, (j + 1) * n + k)) {
            flag = false; break;
          }
          d.merge(now, (j + 1) * n + k);
        }
        if (k + 1 < n && vis[j][k + 1]) {
          if (d.same(now, now + 1)) {
            flag = false; break;
          }
          d.merge(now, now + 1);
        } 
      }
    }   
    if (flag) {
      Rep(j, 0, n) {
        Rep(k, 0, n) {
          cout << vis[j][k] << " ";
        }
        cout << "\n";
      }
      // exit(0);
      cout << "\n";
      ok --;
      if (!ok) exit(0);
    }
  }
}

void solve() {
  getSerect();
}

int main() {
  // ios::sync_with_stdio(false); 
  // cin.tie(nullptr); 
  // freopen("1.txt", "w", stdout);
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}