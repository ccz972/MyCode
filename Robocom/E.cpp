#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define chkmax(x, y) x = ((x >= y) ? x : y)

constexpr int N = 2E3 + 10;

vector<int> son[N];
int col[N];
int depth[N];
// int lca[N][N];
bool st[N][N];
ll ans = 0;
vector<int> d[N];
int mx = 0;
void dfs(int u, int fa, int dep) {
  chkmax(mx, dep);
  depth[u] = dep;
  d[dep].push_back(u);
  // map<int, int> mp;
  for(auto& v: son[u]) if(v != fa) {
    dfs(v, u, dep + 1);
    // mp[col[v]] ++;
  }
  if(u == 1) return;
  for(auto &v1: son[u]) if(v1 != fa) {
    for(auto &v2 : son[u]) if(v2 != fa) {
      st[v1][v2] = true;
    }
  }

}


void dfs2(int u, int fa, int dep) {

  for(auto& v: son[u]) if(v != fa) {
    dfs2(v, u, dep + 1);
  }

  for(auto &v1: son[u]) if(v1 != fa) {
    for(auto &v2 : son[u]) if(v2 != fa) {
      st[v1][v2] = false;
    }
  }

}

void solve() {
  int n; cin >> n;


  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v); 
    son[v].emplace_back(u);
  }
  
  for(int i = 1; i <= n; i ++ ) cin >> col[i];
  // cout << ":1"; return;
  vector<array<int, 3> > ret;
  for(int root = 1; root <= n; root ++  ) {
    dfs(root, 0, 1);
    st[root][root] = true;
    for(int i = 1; i <= mx; i ++ ) {
      int m = d[i].size();
      for(int j = 0; j < m; j ++ ) {
        for(int k = 0; k < m; k ++ ) if(!st[d[i][j]][d[i][k]] && col[d[i][j]] != col[d[i][k]]) {
          for(int l = 0; l < m; l ++ ) if(!st[d[i][j]][d[i][l]] && !st[d[i][k]][d[i][l]] && col[d[i][j]] != col[d[i][l]] && col[d[i][k]] != col[d[i][l]]) {
            ans ++;
            ret.push_back({d[i][j], d[i][k], d[i][l]});
            sort(ret.back().begin(), ret.back().end());
            // if(ret.back()[0] == 2 && ret.back()[1] == 3 && ret.back()[2] == 10) {
            //   cout << depth[10];
            //   cout << root << "\n";
            // }
            // cout << d[i][j] << " " << d[i][k] << " " << d[i][l] << "\n";
          } 
        }
      }
      
      // sort(d[i].begin(), d[i].end());
      // int m = d[i].size();
      // ll d1 = 0, d2 = 0, d3 = 0;
      // for(int j = 0; j < m; j ++ ) {
      //   int k = j;
      //   while(k + 1 < m && d[i][k + 1] == d[i][j]) ++ k;
      //   d3 += d2 * (k - j + 1);
      //   d2 += d1 * (k - j + 1);
      //   d1 += (k - j + 1);
      //   cout << k - j + 1 << " ";
      //   j = k;
      // }
      // ans += d3;
      // cout << ans << "\n";
      d[i].clear();  
    }
    // cout << "\n";
    // cout << ans << "\n"; //return;
    dfs2(root, 0, 1);
  }
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  // for(auto& [x, y, z]: ret) cout << x << " " << y << " " << z << "\n";
  // cout << ans / 6 << "\n";
  cout << ret.size();


}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  solve();
  return 0;
}