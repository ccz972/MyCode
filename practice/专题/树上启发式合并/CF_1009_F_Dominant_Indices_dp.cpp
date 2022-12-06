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

  /** 长链剖分
   *  考虑dp  f[i][j]表示以点i为根的子树，深度为j的点的个数， 转移： f[i][j] = \sigma f[v][j - 1] 
   *  由于数组是开不下的，因此考虑长链剖分，数组复用
   *  即每个点的f数组可以继承它的长儿子的数组， 可以利用 vector的 swap 
   *  按深度递增的顺序存储的话，因为合并重儿子信息时要在开头插入元素，效率低下。所以考虑按深度递减的顺序存储信息。
   *  然后 对短儿子 DP 转移即可
  */
  int n; cin >> n;
  vector<vector<int>> son(n + 1);
  for (int i = 1; i < n; i++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v), son[v].push_back(u);
  }

  vector<vector<int> > f(n + 1);
  vector<int> father(n + 1), lson(n + 1), len(n + 1), ans(n + 1);

  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    father[u] = fa;
    for (int &v: son[u]) if (v != fa) {
      dfs1(v, u);
      if (len[v] >= len[lson[u]]) {
        lson[u] = v; len[u] = len[v] + 1;
      }
    }
  };

  function<void(int)> dfs2 = [&] (int u) {
    if (lson[u]) {
      dfs2(lson[u]);
      swap(f[u], f[lson[u]]); // 直接交换，降低时间空间的开销
      f[u].push_back(1); // 尾部插入深度为0的结果
      ans[u] = ans[lson[u]];
      if (f[u][ans[u]] == 1) ans[u] = len[u];
      for (int &v: son[u]) if (v != father[u] && v != lson[u]) {
        dfs2(v);
        for (int i = len[v]; i >= 0; i -- ) {
          int tmp = i + len[u] - len[v] - 1;
          f[u][tmp] += f[v][i];
          if (f[u][tmp] > f[u][ans[u]] || (f[u][tmp] == f[u][ans[u]] && tmp > ans[u])) {
            ans[u] = tmp;
          }
        }
      }
    } else {
      f[u].push_back(1);
      ans[u] = 0;
    }
  };
  dfs1(1, 0);
  dfs2(1);
  rep(i, 1, n) cout << len[i] - ans[i] << "\n";
  
  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}