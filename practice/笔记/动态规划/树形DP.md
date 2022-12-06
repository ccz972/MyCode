##  DP on Trees 

### 问题一

给定一个有 $N$ 个节点的树 $T$ ，点 $i$ 有一个权值 $w_i$  ，在树上挑选一些不相连的节点，求最大权值和。

~~树形DP 一般定义状态选择以某个点为子树的情况下的一些状态~~。
题目要求挑选的节点不能相邻，因此我们可以定义 $f_i$ 表示在 $i$ 的子树中挑选且可以选 $i$ 的最大权值和， $g_i$ 表示在 $i$ 的子树中挑选且不可以选 $i$ 的最大权值和。
状态转移：
$$
f_i = \max(w_i + \sum{g_j (j \in subtree(i))}, \sum{f_j (j \in subtree(i))})
$$

$$
g_i = \sum{\max(f_j, g_j) (j \in subtree(i))} 
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e5 + 10;

ll w[N], f[N], g[N];
vector<int> son[N];

void dfs(int u, int fa) {
  ll s1 = 0, s2 = 0; //z
  for(auto v: son[u]) if(v != fa) {
    dfs(v, u);
    s1 += f[v], s2 += g[v];
    g[u] += max(f[v], g[v]);
  }
  f[u] = max(w[u] + s2, s1);
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> w[i];
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  dfs(1, 0);
  cout << max(f[1], g[1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
```



### 问题二

给定一个有 $N$ 个节点的树 $T$ ，求树上最长路径，即树的直径长度。

对于经过某个点的路径来说，可以分为两种，第一种是以该点为端点的路径，第二种是经过该点且该点不是端点的路径。
因此我们可以定义状态： $f_i$ 表示以 $i$ 为端点的最长路径， $g_i$ 表示经过 $i$ 且不以 $i$ 为端点的最长路径。
则 $f_i$ 为以 $i$ 为父节点的所有节点 $j$ 的最大 $f_j + 1$， $g_i$ 为以以 $i$ 为父节点的所有节点 $j$ 的最大$f_j$ 和 次大 $f_j$ 之和。 

状态转移：
$$
f_i = \max(f_j (j \in sbutree(i))) + 1
$$

$$
g_i = \max(f_j (j \in subtree(i))) + cmax(f_j (j \in subtree(i)))
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e5 + 10;

int ans, f[N], g[N];
vector<int> son[N];

void dfs(int u, int fa) {
  int mx = 0, cmx = 0;
  for(auto v: son[u]) if(v != fa) {
    dfs(v, u);
    if(f[v] >= mx) {
      cmx = mx; mx = f[v];
    } else if(f[v] > cmx) {
      cmx = f[v];
    }
  }
  f[u] = mx + 1;
  g[u] = mx + cmx;
  ans = max(ans, max(f[u], g[u]));
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
```





