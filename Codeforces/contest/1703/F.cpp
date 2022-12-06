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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    int now = 0;
    ll ans = 0;
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i ++ ) {
      cin >> a[i];
      s[i] = s[i - 1];
      if(a[i] >= i) continue;
      if(a[i])
        ans += s[a[i] - 1];
      s[i] ++;
    }  
    cout << ans << "\n";  
  }
  return 0;
}