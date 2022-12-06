#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2E5 + 10;

int n, m, a[N], stk[N], ans[N];
vector<int> son[N];
void dfs (int u, int fa) {
  for (int &v: son[u]) if (v != fa) {
    int p = lower_bound(stk + 1, stk + 1 + m, a[v]) - stk;
    ans[v] = max(m, p);
    auto res1 = stk[p];
    auto res2 = m;
    stk[p] = a[v]; 
    chkmax(m, p);
    dfs (v, u);
    stk[p] = res1;
    m = res2;
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  
  ans[1] = 1; 
  stk[++ m] = a[1];
  dfs (1, 0);
  for (int i = 1; i <= n; i ++ ) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}