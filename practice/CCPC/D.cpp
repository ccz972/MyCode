#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pow2(x) (1ll * (x) * (x))

constexpr int N = 2E3 + 10;

struct node {
  int x, y, id, col;
  ll r;
  bool operator < (const node &T) {
    if (r != T.r) return r < T.r;
    return id < T.id;
  }
} a[N];

vector<int> son[N];
int parent[N];
ll w[N];

void dfs1(int u) {
  for (int &v: son[u]) {
    dfs1(v);
    w[u] -= w[v];
  }
}
//
#define chkmax(a, b)  (a = a >= b ? a : b)
ll f[N][N]; //i这个子树，操作了j次最多的白色的面积
ll g[N][N]; //i这个子树，操作了j次最多的黑色的面积
int sz[N];
int tmp1[N], tmp2[N];
void dfs(int u) {
  // sz[u] = 1;
  f[u][0] = a[u].col ? w[u] : 0;
  f[u][0] = a[u].col ? 0 : w[u];
  for (int v: son[u]) {
    dfs(v);
    sz[u] += sz[v]; //f[i][j] 
    for (int i = 0; i <= sz[u]; i ++ ) tmp1[i] = tmp2[i] = 0; 
    for (int i = 0; i <= sz[u]; i ++ ) {
      tmp1[i] = f[u][i];
      tmp2[i] = g[u][i];
      for (int j = 0; j <= sz[v]; j ++ ) {
        chkmax(tmp1[i], f[u][i] + f[v][j]);
        chkmax(tmp2[i], g[u][i] + g[v][j]); 
      }
    }
    for (int i = 0; i <= sz[u]; i ++ ) {
      f[u][i] = tmp1[i];
      g[u][i] = tmp2[i];
    }
  }
  if (u) {
    for (int i = 0; i <= sz[u]; i ++ ) {
      if (a[u].col == 1) { //白色
        //reverse
        chkmax(g[u][i + 1], f[u][i] + w[u]);
        // chkmax(f[u][i + 1], g[u][i]);
      } else {
        // chkmax(g[u][i + 1], f[u][i]);
        chkmax(f[u][i + 1], g[u][i] + w[u]);
      }
    }
  }
  
  sz[u] ++;
}

void solve() {
  int n; ll k; cin >> n >> k;
  for (int i = 1; i <= n; i ++ ) {
    int x, y, r; cin >> x >> y >> r;
    a[i] = {x, y, i, -1, r};
  }

  sort(a + 1, a + 1 + n);
  ll sum = 0;
  for (int i = 1; i <= n; i ++ ) { // 枚举半径从小到大
    bool flag = true;
    for (int j = i + 1; j <= n; j ++ ) {
      long long dist = pow2(a[i].x - a[j].x) + pow2(a[i].y - a[j].y);
      long long P = pow2(a[j].r);
      if (dist <= P) {
        son[j].emplace_back(i);
        parent[i] = j;
        flag = false;
        break;
      }
    }
    if (flag) {
      son[0].push_back(i);
      sum += pow2(a[i].r);
    }
  }

  for (int i = 1; i <= n; i ++ ) {
    w[i] = pow2(a[i].r);
  }
  for (int i = 1; i <= n; i ++ ) {
    int j = i, cnt = 0;
    while (j != 0) {
      j = parent[j];
      if (a[j].id > a[i].id) {
        ++ cnt;
      }
    }
    if (cnt & 1) {
      a[i].col = 1; // white
    } else {
      a[i].col = 0; // black
    }
  } 
  // cout << "sun = " << sum << "\n";
  dfs1(0);
  // for (int i = 1; i <= n; i ++ ) {
  //   cout << w[i] << " \n"[i == n];
  // }
  dfs(0);
  // for (int i = 0; i <= n; i ++ ) {
  //   cout << f[0][i] << "\n";
  // }

  // for (int i = 1; i <= n; i ++ ) {
  //   for (int j = 0; j <= n; j ++ ) {
  //     cout << f[i][j] << " \n"[j == n];
  //   }
  // }
  for (int i = 0; i <= n; i ++ ) if (sum - f[0][i] <= k) {
    cout << i << "\n";
    return ;
  }
  


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  // cout << INT64_MAX;
  return 0;
}