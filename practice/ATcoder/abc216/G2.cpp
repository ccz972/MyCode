#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2E5 + 10;

int d[N], cnt[N], inq[N];
vector<pair<int, int> > son[N];

void solve() {

  // 对于某条边 [u, v, w] 表示 从 u 到 v 最多可以得到多少个 0, 即最少付出 1
  
  int n, m; 
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    son[i].emplace_back(i - 1, -1);  // cnt0[i] <= cnt0[i - 1] + 1
    // son[i].emplace_back(i + 1, 1);
    son[i - 1].emplace_back(i, 0);
  }
  while (m -- ) {
    int l, r, x;
    cin >> l >> r >> x;
    son[l - 1].emplace_back(r, x);
  }
  m = (n << 1) + 5;
  vector<int> q(m);
  int hh = 0, tt = 0;
  for (int i = 0; i <= n; i ++ ) {
    q[tt ++] = i;  if (tt == m) tt = 0;
    inq[i] = 1;
    d[i] = 0;
  }
  while (hh != tt) {
    int u = q[hh ++ ]; if (hh == m) hh = 0;
    inq[u] = 0;
    for (auto& [v, w]: son[u]) {
      if (d[v] < d[u] + w) {
        d[v] = d[u] + w;
        if (inq[v] == 0) {
          q[tt ++ ] = v; if (tt == m) tt = 0;
          inq[v] = 1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i ++ ) {
    cout << d[i] - d[i - 1] << " \n"[i == n];
  }


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}