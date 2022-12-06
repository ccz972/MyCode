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
  vector<int> cnt(1000010);
  vector<int> a(n); for(int &x: a) cin >> x, cnt[x] ++;
  
  int mx = *max_element(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i <= mx; i ++ ) {
    int ct = 0;
    for (int j = i; j <= mx; j += i) {
      ct += cnt[j];
    }
    if (ct >= 2) {
      chkmax(ans, i);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}