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
constexpr int N = 1 << 22;
// constexpr int N = 2E5 + 10;

/**  题意
 * 一棵根为 1 的树，每条边上有一个字符（a-v 共 22 种）。 
 * 一条简单路径被称为 Dokhtar-kosh 当且仅当路径上的字符经过重新排序后可以变成一个回文串。 
 * 求每个子树中最长的 Dokhtar-kosh 路径的长度。
*/

/** 错误思路 
  /**
   * 字符一共 22 种，因此可以考虑路径压缩
   * 令dp[u]为u的答案，则 : 
   * dp[fa] = max(dp[fa], dp[u])  这是是考虑 fa 的子树中，不经过 fa 的最大值
   * 考虑经过fa，那么要选 1 条 or 2 条 子树的边
   * 选 1 条： 那么对于所有的儿子的异或前缀和 w[u']
   * 、
   * 
*/


void solve() {
  /** 看题解后思路如下
   *  首先需要知道状态压缩，一共的状态只有 2 ^ 22 次方种
   *  考虑对于某个点 u 的子树中组成的最长带权路径 ans[u] ，可分为两种 
   * 第一种是不包含 u ，直接枚举 所有的儿子 v : chkmax(ans[u], ans[v]) 即可
   * 第二种是包含 u ， 考虑最多选两个儿子，
   * 
  */

  int n; cin >> n;
  vector<vector<int> > son(n + 1);

  for (int i = 2; i <= n; i++ ) {
    int u; cin >> u; son[u].eb(i);
  }
  
  vector<int> w(n + 1), depth(n + 1), sz(n + 1), hson(n + 1), ans(n + 1);

  function<void(int)> dfs1 = [&] (int u) {
    sz[u] = 1;
    for (auto &[v, val]: son[u]) {
      w[v] = w[u] ^ val;
      depth[v] = depth[u] + 1;
      dfs1(v);
      if (!hson[u] || sz[v] > sz[hson[u]]) hson[u] = v;
      sz[u] += sz[v];
    }
  };

  depth[1] = 1; dfs1(1);

  vector<int> now(1 << 22);

  function<void(int)> del = [&] (int u) {
    now[w[u]] = 0;
    for (auto &[v, val]: son[u]) del(v);
  };

  function<void(int)> update = [&] (int u) {
    chkmax(now[w[u]], depth[u]);
  };

  function<void(int, int)> getans = [&] (int u, int fa) {
    Rep(i, 0, 22) if (now[w[u] ^ (1 << i)]) {
      chkmax(ans[fa], depth[u] + now[w[u] ^ (1 << i)] - 2 * depth[fa]);
      
    }
    if (now[w[u]]) {
      chkmax(ans[fa], depth[u] + now[w[u]] - 2 * depth[fa]);
    }
    for (auto &[v, val]: son[u]) getans(v, fa);
  };

  function<void(int, int)> add = [&] (int u, int fa) {
    update(u);
    for (auto &[v, val]: son[u]) add(v, fa);
  };

  function<void(int)> dfs2 = [&] (int u) {
    for (auto &[v, val]: son[u]) if (v != hson[u]) {
      dfs2(v); chkmax(ans[u], ans[v]); del(v);
    }

    if (hson[u]) {
      dfs2(hson[u]);
      chkmax(ans[u], ans[hson[u]]);
    }

    update(u);

    for (auto &[v, val]: son[u]) if (v != hson[u]) {
      getans(v, u);
      add(v, u);
    }

    chkmax(ans[u], now[w[u]] - depth[u]);
    Rep(i, 0, 22) if (now[w[u] ^ (1 << i)]) {
      chkmax(ans[u], now[w[u] ^ (1 << i)] - depth[u]);
    }

  };

  dfs2(1);

  rep(i, 1, n) cout << ans[i] << " \n"[i == n];


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}