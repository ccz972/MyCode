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

struct splitmix64 {
  size_t operator()(size_t x) const {
    static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
    x += 0x9e3779b97f4a7c15 + fixed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};
unordered_map<ll, int, splitmix64> mp;
#define pow3(i) (i * i * i)
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 1; pow3(i) <= n; i ++ ) {
    mp[pow3(i)] = i;
  }

  auto get = [&] (ll x, int ret = 0) {
    for(ll i = 2; i <= x / i; i ++ ) if(x % i == 0) {
      ++ ret;
      while(x % i == 0) {
        x /= i;
      }
    }
    if(x ^ 1) ++ ret;
    return ret;
  };

  for(ll i = 1; pow3(i) <= n; i ++ ) {
    ll g = i;
    if(!mp.count(n - pow3(g))) continue;
    ll res = mp[n - pow3(g)];
    if(res < g) break;
    if(res % g == 0) {
      ll tmp = get(res / g);
      ll res = 1ll << tmp;
      ans += res;
    }
  }
  
  cout << ans << "\n";

  return 0;
}