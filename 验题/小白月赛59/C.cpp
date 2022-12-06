#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    ll l, r, k; cin >> l >> r >> k;
    auto chk = [&] (ll x) {
      if (x >= l && x <= r) return true;
      return false;
    };
    if (k == 0) {
      //1 0 0 0 0 0 
      if (chk(0) && chk(1)) {
        cout << "0 1\n";
      } else if (chk(0) || chk(1)) {
        cout << (chk(0) ? "0\n" : "1\n");
      } else {
        cout << "None.\n";
      }
    } else if (k == 1) {
      //1 1 1 
      if (chk(1)) {
        cout << "1\n";
      } else {
        cout << "None.\n";
      }
    } else {
      ll s = 1;
      vector<ll> ans;
      while (true) {
        if (chk(s)) ans.emplace_back(s);
        // s * k > r             break
        
        if (s > r / k) break;
        s *= k;
      }
      if (ans.empty()) {
        cout << "None.\n";
      } else {
        for (auto x: ans) cout << x << " ";
        cout << "\n";
      }
    }

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}