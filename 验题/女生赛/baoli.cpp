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
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

void solve() {
  ll x, t, k, n, d;
  cin >> x >> t >> k >> n >> d;
  vector<ll> a(n); for (ll &x: a) cin >> x;
  auto now = x;
  ll inc = 0;
  for (int tt = 0; tt < 100; tt ++ ) {
    // debug(a, b);
    
    if (inc == t) {
      // cout << inc << " " << t << "\n";
      // cout << "t = " << t << "\n";
      return cout << "YES\n", void();
    }
    for (int i = 0; i < SZ(a); i++) {
      if (a[i] <= d) {
        now--;
      } else {
        now++;
      }
      if (now <= k) {
        inc++;
      } else {
        inc = 0;
      }
      if (inc == t) {
        // cout << "t = " << t << "\n";
        return cout << "YES\n", void();
      }
    }
  }
  cout << "NO\n";
  // for (ll &x: a) {
  //   if (x <= d) {
  //     x = -1;
  //   } else {
  //     x = 1;
  //   }
  // }


  // cout << x << " " << t << " " << k << " " << n << " " << d << "\n";
  // for (auto &x: a) cout << x << " ";
  // cout << "\n";
  // ll sum = accumulate(all(a), 0ll);
  // cout << sum << "\n";
}

void solve2() {
  ll x, t, k, n, d;
  cin >> x >> t >> k >> n >> d;
  vector<ll> a(n); for (ll &x: a) cin >> x;
  for (ll &x: a) {
    if (x <= d) {
      x = -1;
    } else {
      x = 1;
    }
  }
  cout << x << " " << t << " " << k << " " << n << " " << d << "\n";
  for (auto &x: a) cout << x << " ";
  cout << "\n";
  ll sum = accumulate(all(a), 0ll);
  cout << sum << "\n";
}


int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; cin >> T;
  while (T --) solve();
  return 0;
}