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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    bool f = true;
    for(int i = 0; i < n - 1; i ++ ) {
      if(a[i] != 0) {
        f = false;
      }
    }
    if(f) {
      cout << "0\n";
      continue;
    } 

    ll ans = 0;
    int i = 0;
    while(a[i] == 0) i ++;
    for(; i < n - 1; i ++ ) {
      if(a[i] == 0) ans ++;
      else ans += a[i];
    }
    cout << ans << "\n";

    //[ xxxxxxx0+++++++]
  }
  return 0;
}