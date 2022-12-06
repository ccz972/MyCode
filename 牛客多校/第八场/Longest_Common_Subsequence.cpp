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


struct splitmix64 {
  size_t operator()(size_t x) const {
    static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
    x += 0x9e3779b97f4a7c15 + fixed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};
unordered_map<int, int, splitmix64> mp;

void solve() {
  int n, m; cin >> n >> m;
  int p, A, B, C; ll x; cin >> p >> x >> A >> B >> C;
  vector<int> a(n + 1), b(m + 1);
  for(int i = 1; i <= n; i ++ ) {
    x = (x * x % p * A % p + x * B % p + C) % p;
    a[i] = x;    
    if(!mp.count(a[i])) mp[a[i]] = i; 
  }
  int ans = 0;
  for(int i = 1; i <= m; i ++ ) {
    x = (x * x % p * A % p + x * B % p + C) % p;
    b[i] = x;    
    if(mp.count(b[i])) chkmax(ans, min(n - mp[b[i]] + 1, m - i + 1) );
    
  }
  // debug(a);
  // debug(b);
  cout << ans << "\n";
  mp.clear();
  



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}