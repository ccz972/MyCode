#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll INFF = 0x3f3f3f3f3f3f3f3f;
// constexpr int N = 2E5 + 10;

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;
  vector<int> a(n); for (int &x: a) cin >> x;
  sort(all(a)); reverse(all(a));
  //d days  c coins
  if (d * a[0] < c) return cout << "Impossible\n", void();
  ll res = 0;
  for (int i = 0; i < min(d, n); i ++ ) res += a[i];
  if (res >= c) return cout << "Infinity\n", void();

  ll l = 0, r = d;

  auto chk = [&] (ll x) -> bool {
    /*
    一共有 n 个数字，d 天， 每x+1天可以取 
    */
    ll ret = 0;
    for (ll i = 0; i < min({x + 1, n, d}); i ++ ) {
      ret += max(0ll, (d + x - i) / (x + 1) * a[i]);  
    }
    return ret >= c;
  };

  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (chk(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}