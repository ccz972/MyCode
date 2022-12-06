#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int q; cin >> q;
  vector<ll> a, s;
  // vector<double> avg;
  ll now;

  auto chk = [&] (int x) -> bool {  
    ll sum1 = s[x] + now;
    int cnt1 = x + 2;
    ll sum2 = s[x - 1] + now;
    int cnt2 = x + 1;
    // debug(x, sum1 * cnt2, sum2 * cnt1);
    if(sum1 * cnt2 <= sum2 * cnt1) return true; // 
    return false;
  };

  while(q -- ) {
    int op; cin >> op;
    if(op & 1) {
      int x; cin >> x;
      s.emplace_back(a.empty() ? x : s.back() + x);
      a.emplace_back(x);
    } else {
      if(a.size() <= 1) {
        cout << "0\n";
        continue;
      } else if(a.size() == 2) {
        cout << (double)a.back() - ((double)s.back() / (s.size())) << "\n";
        continue;
      }

      now = a.back();
      int l = 1, r = a.size() - 2;

      while(l < r) {
        int mid = (l + r + 1) / 2;
        if(chk(mid)) l = mid;
        else r = mid - 1;
      }
      // cout << l << "\n";
      // debug((double)s.back() / a.size());
      double ans = (double)now -((double)(s[l] + now) / (l + 2));
      // debug(now, ((double)(s[l] + now) / (l + 2)), ans);
      chkmax(ans, (double)now - (double)(s[0] + now) / 2 );
      cout << ans << "\n";
    }
  }
  // debug(s.back(), a.size());

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();

#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
