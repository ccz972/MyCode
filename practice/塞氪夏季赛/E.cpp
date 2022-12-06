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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> b(n);
  for (auto& x : b) cin >> x;
  
  vector<ll> f(n * 2 + 1000, -1E18);
  f[0] = 0;
  for(int i = 1; i <= n; i ++ ) {
    chkmax(f[i], f[i - 1]);
    
  }


  return 0;
}

/*
ll dp[MAXN];

vector< vector<pair<ll, ll> > num;
for(int i = 1; i <= n; ++i) {
  for(auto &t: num[i])
    motify(1, 1, n, t.x, t.y);
    
  int l = i - a[i], r = i + a[i];
  ll vmax = 0;
  if(l >= 1) vmax = query(1, 1, n, 1, l);
  dp[i] = vmax + 1ll * a[i] * b[i];
if(r <= n) num[r].push_back({i, dp[i]});
 }


*/