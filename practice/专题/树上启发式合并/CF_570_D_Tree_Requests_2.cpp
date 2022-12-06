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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> father(n + 1);
  vector<vector<int>> son(n + 1);
  for (int i = 2; i <= n; i++ ) {
    cin >> father[i];
    son[father[i]].push_back(i); 
  }
  /** 题意
   *  给定一棵树，每个节点有个字符
   *  q次询问，每次问一个点u的子树中，所有深度为k的点的字符重排后能否构成回文串
   *  题意转化为 每次问一个点u的子树中，所有深度为k的点的字符中奇数个的字符个数是否小于等于 1
  */

  /** 由于字符集大小为 26 ，而且每个字符的状态只有 奇数和偶数两种
   * 因此可以状态压缩一下，而且对于某个点的子树中深度为 k 的节点在dfs序上一定是单调递增的
   * 因此可以预处理出每个深度的所有节点的前缀异或和 和 所有的 dfs序， 每次查询二分左右边界的位置
   * 然后用亦或前缀和求解即可。
   * 
  */
  string s; cin >> s;
  s = " " + s;
  vector<int> depth(n + 1), sz(n + 1), hson(n + 1), dfn(n + 1);
  int cur = 0;
  vector<vector<int> > xorsum(n + 1, {0});
  vector<vector<int> > Dep(n + 1, {-1});
  function<void(int)> dfs1 = [&] (int u) {
    sz[u] = 1; dfn[u] = ++ cur;
    int dep = depth[u];
    int sum = xorsum[dep].empty() ? 0 : xorsum[dep].back();
    xorsum[dep].eb(sum ^ (1 << (s[u] - 'a')));
    Dep[dep].push_back(dfn[u]);
    for (int &v: son[u]) {
      depth[v] = depth[u] + 1;
      dfs1(v);
      if (!hson[u] || sz[v] > sz[hson[u]]) hson[u] = v;
      sz[u] += sz[v];
    } 
  };

  depth[1] = 1;
  dfs1(1);

  Rep(i, 0, m) {
    int u, k; cin >> u >> k;
    int l = dfn[u], r = dfn[u] + sz[u] - 1;
    l = lower_bound(all(Dep[k]), l) - Dep[k].begin();
    r = lower_bound(all(Dep[k]), r + 1) - Dep[k].begin() - 1;
    int suml = xorsum[k][l - 1];
    int sumr = xorsum[k][r];
    cout << (__builtin_popcount(sumr ^ suml) <= 1 ? "Yes" : "No") << "\n";    
  }
  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}