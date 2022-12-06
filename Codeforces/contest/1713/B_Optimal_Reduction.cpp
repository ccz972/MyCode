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
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int mx = *max_element(a.begin(), a.end());
  int idx = -1;
  for(int i = 0; i < n; i ++ ) if(a[i] == mx) {
    idx = i;
    break;
  }
  auto p = idx;
  while(idx > 0) {
    if(a[idx - 1] > a[idx] ) {
      cout << "NO\n";
      return;
    }
    -- idx;
  }
  while(p + 1 < n) {
    if(a[p + 1] > a[p]) {
      cout << "NO\n";
      return;
    }
    ++ p;
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}