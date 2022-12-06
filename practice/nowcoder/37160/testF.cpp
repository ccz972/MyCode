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

// #define int ll 

constexpr int N = 1E5 + 100;
constexpr ll INF = 1E18 + 10;

ll a[N], b[N];
array<ll, 2> p[N];
ll f[N];


signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, t; cin >> n >> m >> t;
  a[0] = 0, b[0] = t;

  for(int i = 1; i <= m; i ++ ) {
    // cin >> a[i] >> b[i];
    cin >> p[i][0] >> p[i][1];
  }

  sort(p + 1, p + 1 + m);

  for(int i = 1; i <= m; i ++ ) {
    a[i] = p[i][0], b[i] = p[i][1];
  }

  a[m + 1] = n, a[m + 2] = INT64_MAX;

  ll now = t, nxt = t;
  int ans = 0;
  for(int i = 1; i <= m + 1; i ++ ) {
    if(a[i] <= now) {
      nxt = max(nxt, a[i] + b[i]);
    } else if(nxt < a[i]) {
      cout << "-1\n";
      return 0;
    } else {
      ans ++;
      now = nxt;
      nxt = max(nxt, a[i] + b[i]);
    }
  }

  cout << ans << "\n";


  

  return 0;
}