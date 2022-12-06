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

constexpr int N = 1E5 + 10;
#define int ll 
ll n, m;
ll a[N], b[N];

bool chk(ll x) {
  
  for(int i = 1; i <= n; i ++ ) {
    b[i] = a[i] + x * i;
  }

  sort(b + 1, b + 1 + n);
  ll sum = 0;
  for(int i = 1; i <= x; i ++ ) {
    sum += b[i];
  }
  return sum <= m;
  
}

void solve() {
  int ans = 0;
  cin >> n >> m;

  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }

  int l = 0,r = n;

  while(l < r) {
    int mid = (l + r + 1) / 2;
    if(chk(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}