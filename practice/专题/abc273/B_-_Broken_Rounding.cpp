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
  ll x; cin >> x;
  int k; cin >> k;
  ll p = 1;
  for (int i = 1; i <= k; i ++ ) {
    p *= 10;
    ll res = x % p; //2048  8
    if (res < p - res) {
      x -= res;
    } else {
      x += p - res;
    }
  }
  cout << x << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}