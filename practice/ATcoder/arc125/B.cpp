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

inline void out(bool flag) {
  cout << (flag ? "Yes" : "No" ) << "\n";
}

void solve() {
  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n / i; i ++ ) {
    ll l = i, r = n / i;
    ans += (r - l) / 2 + 1; 
    ans %= 998244353;
  }
  cout << ans;
  // set<int> s;for(int i = 0; i <= 100; i ++ ) s.insert(i * i);
  // for(int i = 1; i <= 10; i ++ ) {
  //   for(int j = 1; j <= 10; j ++ ) {
  //     if(s.count(i * i - j)) {
  //       cout << i - sqrt(i * i - j) << "\n";
  //     }
  //   }
  // }
  /*

  x ^ 2 - y = z ^ 2
  //
  y = x^2 - z^2 = (x + z) * (x - z)
  p = x + z, q = x - z
  p * q = y 
  //
  p * q = y <= n
  q <= p
  x = (p + q) / 2




  */
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}