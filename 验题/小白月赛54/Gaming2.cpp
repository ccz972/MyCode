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
  vector<ll> S(m + 2);
  ll sum = 0, ans = 0;

  while(n -- ) {
    int l, r, s; cin >> l >> r >> s;
    S[l] += s, S[r + 1] -= s;
    sum += s;
  }  

  for(int i = 1; i <= m; i ++ ) {
    S[i] += S[i - 1];
    chkmax(ans, sum - S[i]);
  }

  cout << ans << "\n";



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}