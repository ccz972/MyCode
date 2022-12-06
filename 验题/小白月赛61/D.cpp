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
 
void solve() {
  int n, m; cin >> n >> m;
  DSU d(n * m + 10);
  vector<string> s(n);
  for (auto &x : s) cin >> x;
  auto merge = [&] (int x, int y, int p, int q) {
    if (p < 0 || p >= n || q < 0 || q >= m) return ;
    if (s[p][q] == '*') return ;
    d.merge(x * n + y, p * n + q);
  };
  pair<int, int> st, ed;
  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < n; j ++ ) if (s[i][j] != '*') {
      merge(i, j, i + 1, j); merge(i, j, i - 1, j);
      merge(i, j, i, j + 1); merge(i, j, i, j - 1);
      if (s[i][j] == 'P') st = {i, j};
      if (s[i][j] == 'M') ed = {i, j};
    }
  }

  if (!d.same(st.first * n + st.second, ed.first * n + ed.second)) return cout << "-1\n", void();
  
  vector<int> dx{0, 0, -1, 1}, dy{-1, 1, 0, 0};
  

  int ans = INT_MAX;
  for (int i = 0; i < 4; i ++ ) {
    // auto
    // chkmin(ans, sol())
  }
  
  /*

  
  
  
  */


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}