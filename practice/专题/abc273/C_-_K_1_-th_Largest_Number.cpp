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
  for (int &x: a) cin >> x;

  map<int, int> mp;
  auto b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int m = b.size();
  for (int i = 0; i < m; i ++ ) {
    mp[b[i]] = m - i - 1;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i ++ ) {
    ans[mp[a[i]]] ++;
    // cout << mp[a[i]] << "\n";
  }
  for (int i = 0; i < n; i ++ ) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}