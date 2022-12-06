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

ll t, n; 
int m, k; 

void fuck() {
  cout << "Wrong Record\n";
  exit(0);
}

void solve() {
  cin >> t >> n;
  cin >> m >> k;
  vector<pair<ll, ll> > a(m);
  for (auto &[ti, x]: a) cin >> ti >> x;
  sort(all(a));
  if (a[0].first < t) {
    ll now = a[0].second;
    for (int i = 1; i < m; i ++ ) {
      auto [ti, x] = a[i];
      auto [lti, lx] = a[i - 1];
      if (ti < t) {
        now -= (ti - lti) * k;
        chkmax(now, 0ll);
        now += x;
      } else if (ti == t) {
        // chkmin(now, (ti - lti) * k); 
        now -= (ti - lti) * k;
        chkmax(now, 0ll);
        now += x;
        if (now != n) fuck();
      } else if (ti > t) {
        auto tmp = now;
        now -= (t - lti) * k;
        chkmax(now, 0ll);
        if (now != n) fuck();
        //lti  t  ti
        swap(now, tmp);
        ll mx = inf, idx = i;
        for (int j = i; j < m; j ++ ) {
          auto [Ti, X] = a[j];
          auto [lTi, lX] = a[j - 1];  
          now -= (Ti - lTi) * k;
          chkmax(now, 0ll);
          now += X;
          if ((now + 1 + k - 1) / k  <= mx) {
            mx = (now + 1 + k - 1) / k;
            idx = j;            
          }
        }
        cout << a[idx].first << " " << mx << "\n";
        exit(0);
      }
    }
  } else {
    if (n != 0) fuck();
    t = inf;
    ll now = a[0].second;
    ll mx = (now + 1 + k - 1) / k, idx = 0;
    for (int i = 1; i < m; i ++ ) {
      auto [Ti, X] = a[i];
      auto [lTi, lX] = a[i - 1];  
      now -= (Ti - lTi) * k;
      chkmax(now, 0ll);
      now += X;
      // cout << (now + 1 + k - 1) / k << "\n";
      if ((now + 1 + k - 1) / k  <= mx) {
        mx = (now + 1 + k - 1) / k;
        idx = i;            
      }
    }
    cout << a[idx].first << " " << mx << "\n";
    exit(0);
  }

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}