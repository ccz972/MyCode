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

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> w(n); for(ll &x: w) cin >> x;
  vector<int> d(n); 
  vector<vector<int> > son(n, vector<int>());
  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v; -- u, -- v;
    son[u].push_back(v);
    d[v] ++;
  }
  vector<int> q(n + 100);
  vector<bool> st(n);
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j){
    return w[i] < w[j]; 
  });

  int hh = -1, tt = 0;
  ll ans = 0;
  while(true) {
    int cnt = 0;
    for(int i = 0; i < n; i ++ ) if(!st[i]) {
      ++ cnt;
    }

    if(cnt == 1) {
      for(int i = 0; i < n; i ++ ) if(!st[i]) {
        cout << ans + w[i] - 1 << "\n";
      }
      break;
    }

    int id = -1;
    for(int i = 0; i < n; i ++ ) if(!st[i] && d[i] == 0) {
      if(id == -1) {
        id = i;
      } else {
        if(w[i] < w[id]) {
          id = i;
        }
      }
    }
    ll val = w[id];
    // debug(id,);
    ans += val;
    for(int i = 0; i < n; i ++ ) if(!st[i] && d[i] == 0) {
      //w[id]
      w[i] -= val;
      for(auto& v: son[i]) {
        w[v] += val;
      }
    }

    st[id] = true;
    for(auto v: son[id]) {
      -- d[v];
    }
  }

  
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}