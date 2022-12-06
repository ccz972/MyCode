/***************************************************

@File    : P3354Riv河流.cpp
@Time    : 2022/07/07 22:56:20
@Author  : Nanfeng1997 
@Url     : https://www.luogu.com.cn/problem/P3354

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
#ifdef LOCAL
  freopen("P3354.in", "r", stdin);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  

  int n, k; cin >> n >> k;
  vector<int> val(n + 1);
  vector son(n + 1, vector<pair<int, int> > ());

  for(int i = 1; i <= n; i ++ ) {
    int x, y;
    cin >> val[i] >> x >> y;
    son[x].emplace_back(i, y);
  }

  //f[i][j][k] 表示以 i 为根的子树，j(伐木场) 是 i 的某个祖先(不一定是父亲) 建了 k 个伐木场 并且 i 不是伐木场 的最小花费
  //g[i][j][k] 表示以 i 为根的子树，j(伐木场) 是 i 的某个祖先(不一定是父亲) 建了 k 个伐木场 并且 i 是伐木场 的最小花费

  vector f(n + 1, vector<vector<int> > (n + 1, vector<int>(n + 1)));
  vector g(n + 1, vector<vector<int> > (n + 1, vector<int>(n + 1)));
  vector<int> stk(n + 1), dep(n + 1);
  int tt = 0;
  function<void(int)> dfs = [&](int u) {
    stk[++ tt] = u;
    for (auto& [v, w] : son[u])  {
      dep[v] = dep[u] + w;
      dfs(v);      
      for(int j = 1; j <= tt; j ++ ) {
        int fa = stk[j];
        for(int l = k; l >= 0; l -- ) {
          //相当于初始化，就是假设当前的儿子一个伐木场都没有(最坏情况)，然后接下来枚举取 min
          f[u][fa][l] += f[v][fa][0];
          g[u][fa][l] += f[v][u][0]; //如果 u 是伐木场，那么儿子肯定是优先去 u
          for(int m = 0; m <= l; m ++ ) {
            //枚举儿子建了多少伐木场，然后类似于背包进行转移
            chkmin(f[u][fa][l], f[v][fa][m] + f[u][fa][l - m]);
            chkmin(g[u][fa][l], f[v][u][m] + g[u][fa][l - m]);
          }
        }
      }
    }
    //最后进行合并两种方案到 f
    for(int i = 1; i <= tt; i ++ ) {
      int fa = stk[i];
      for(int j = k; j >= 0; j -- ) {
        f[u][fa][j] += val[u] * (dep[u] - dep[fa]);
        if(j >= 1) chkmin(f[u][fa][j], g[u][fa][j - 1]);
      }
    }
    -- tt;
  };

  dfs(0);
  cout << f[0][0][k];
  return 0;
}