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

constexpr int mod = 998244353;
#define int long long
void solve() {
  int n, m; cin >> n >> m;
  vector<ll> w(n); for(ll &x: w) cin >> x;
  vector<int> d(n); 
  vector<vector<int> > son(n, vector<int>());
  vector<vector<int> > g(n, vector<int>());
  vector<int> dd(n);
  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v; -- u, -- v;
    son[u].push_back(v);
    d[v] ++;
    dd[u] ++;
  }
  ll mx = *max_element(w.begin(), w.end());

  if(mx == 0ll) {
    cout << "0\n";
    return;
  }

  vector<bool> st(n);

  ll ans = 0;
  while(true) {
    bool flag = true;
    for(int i = 0; i < n; i ++ ) if(!st[i] && d[i] && w[i] == 0ll) {
      flag = false;
    } 
    if(flag) {
      break;
    }
    auto q = w;
    for(int i = 0; i < n; i ++ ) if(q[i]) {
      for(auto v: son[i]) {
        w[v] ++;
      }
      // if(!d[i])
      w[i] --;
    }
    for(int i = 0; i < n; i ++ ) if(!st[i] && !w[i] && d[i] == 0) {
      st[i] = true;
      for(auto &v :son[i]) {
        -- d[v];
      }
    }
    ++ ans;
  }
 
  vector<bool> vis(n);
  vector<int> q(n + 100);
  int hh = 0, tt = -1;
  for(int i = 0; i < n; i ++ ) if(!st[i] && d[i] == 0) {
    q[++ tt] = i;
  }

  while(hh <= tt) {
    int u = q[hh ++ ];
    for(auto v: son[u]) {
      w[v] += w[u];
      w[v] %= mod;
      if(-- d[v] == 0) {
        q[++ tt] = v;
      }
    }
  }

  for(int i = 0; i < n; i ++ ) if(dd[i] == 0) {
    ans += w[i];
    ans %= mod;
    cout << ans << "\n";
  }
  
  

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}