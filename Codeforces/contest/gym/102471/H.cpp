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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto ksm = [&] (int A, int B, int ret = 1) {
      if(!B) return (int)(A != 0);
      while(B) {
        if(B & 1) ret = 1ll * ret * A % p;
        B >>= 1;
        A = 1ll * A * A % p;
      }
      return ret;
    };

    auto solve = [&] (int l, int r) {
      int inv = ksm(a[l], p - 2);
      int q = 1ll * a[r] * inv % p;
      int cnt = 2;
      int now = 1ll * a[r] * q % p;
      for(int i = r + 1; i < n; i ++ ) {
        if(a[i] == now) {
          cnt ++;
          now = 1ll * now * q % p;
        }
      }
      q = ksm(q, p - 2);
      now = 1ll * a[l] * q % p;
      for(int i = l - 1; i >= 0; i -- ) {
        if(a[i] == now) {
          cnt ++;
          now = 1ll * now * q % p;
        }
      }
      return cnt;
    };

    int ans = 0;
    vector<bool> cnt(n);
    for(int i = 0; i < 50; i ++ ) {
      int idx = rng() % n;
      if(cnt[idx]) continue;
      cnt[idx] = true;
      if(idx + 1 < n)
        chkmax(ans, solve(idx, idx + 1));
      if(idx + 2 < n)
        chkmax(ans, solve(idx, idx + 2));
      if(idx > 0) 
        chkmax(ans, solve(idx - 1, idx));
      if(idx > 1) 
        chkmax(ans, solve(idx - 2, idx));
    }
    if(ans < (n + 1) / 2) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}