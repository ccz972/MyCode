#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

constexpr int N = 1E5 + 10;
int n, w[N], t[N];
bool vis[N];
vector<int> son[N];

//g[i]表示在i的子树中选，且不选i处的蝴蝶的最大价值
//f[i]表示在i的子树中选，且选i处的蝴蝶的最大价值
//h[i]表示在i的子树中选，且选i处的蝴蝶且所有的儿子都不选的最大价值

//h[i] = \sum g[i]
//f[i] = h[j] + f[j] + \sum g[j] + w[i]
//g[i] = h[j] + g[j] + \sum g[j]
ll f[N], g[N], h[N];
void dfs1(int u, int fa) {
  ll sumg = 0, mx = 0;
  f[u] = h[u] = w[u];
  bool flag = false;

  ll idf[2] = {-1, -1};
  ll idh[2] = {-1, -1};
  ll valh[2] = {0, 0};
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u);
    sumg += g[v];
    chkmax(mx, f[v] - g[v]);
    if (vis[v]) {
      flag = true;
      if (idf[0] == -1) {
        idf[0] = v;
      } else {
        if (w[idf[0]] <= w[v]) {
          idf[1] = idf[0];
          idf[0] = v;
        } else if (w[idf[1]] < w[v]) {
          idf[1] = v;
        }
      }
    }

    ll tmp = h[v] - g[v];
    if (tmp <= 0) continue;
    if (idh[0] == -1) {
      idh[0] = v;
      valh[0] = tmp;
    } else {
      if (valh[0] <= tmp) {
        idh[1] = idh[0]; valh[1] = valh[0];
        idh[0] = v; valh[0] = tmp;
      } else if (valh[1] < tmp) {
        idh[1] = v;
        valh[1] = tmp;
      }
    }
  }

  f[u] += sumg + mx;
  g[u] += sumg + mx;
  h[u] += sumg;

  if (flag) {
    if (idf[0] != -1 && idh[0] != -1) {
      if (idf[0] == idh[0]) {
        ll tmp1 = (idf[1] == -1 ? 0 : w[idf[1]]);
        ll tmp2 = (idh[1] == -1 ? 0 : valh[1]);
        ll sum = tmp1 + valh[0]; 
        chkmax(sum, tmp2 + w[idf[0]]);
        chkmax(f[u], w[u] + sum + sumg);
        chkmax(g[u], sum + sumg);
      } else {
        ll sum = w[idf[0]] + valh[0];
        chkmax(f[u], w[u] + sum + sumg);
        chkmax(g[u], sum + sumg);
      }
    } else if (idf[0] != -1) {
      ll sum = w[idf[0]];
      chkmax(f[u], w[u] + sum + sumg);
      chkmax(g[u], sum + sumg);
    } else if (idh[0] != -1) {
      ll sum = valh[0];
      chkmax(f[u], w[u] + sum + sumg);
      chkmax(g[u], sum + sumg);
    } 
  }

  // if (!flag) {
  //   // 没有等于3的点
  //   //选一个 h, 一个 f,其他的都是 g
  //   f[u] += sumg + mx;
  //   g[u] += sumg + mx;
  //   h[u] = sumg;
  // } else {

  // }


}

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> w[i];
  rep(i, 1, n) {cin >> t[i]; if(t[i] == 3) vis[i] = true; }
  Rep(i, 1, n) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  dfs1(1, 0);
  cout << f[1] << "\n";
  // rep(i, 1, n) cout << f[i] << " \n"[i == n];
  // rep(i, 1, n) cout << g[i] << " \n"[i == n];
  // rep(i, 1, n) cout << h[i] << " \n"[i == n];
  rep(i, 1, n) {son[i].clear(), vis[i] = false; f[i] = g[i] = h[i] = 0; }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- )
  solve();
  return 0;
}