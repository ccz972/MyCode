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
constexpr int N = 1E3 + 10;
constexpr int M = 25;
int a[N][M];
ll f[N];
ll ans[N];
void solve() {
  int n, k; cin >> n >> k;
  map<ll, int> mp;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= k; j ++ ) {
      cin >> a[i][j];
      // (i - 1) * 2, (i - 1) * 2 + 1
      int bit1 = (j - 1) * 2, bit2 = (j - 1) * 2 + 1;
      if (a[i][j] == 0) {
        //0 1
        f[i] |= 1ll << bit1;
      }  else if (a[i][j] == 1) {
        f[i] |= 1ll << bit2;
      } else {
        f[i] |= 1ll << bit1;
        f[i] |= 1ll << bit2;
      }
      // cout << f[i] << " \n"[j == k];
      //0 1, 2 3, 4 5
    }
    // cout << f[i] << " \n"[i == n];
    mp[f[i]] = i;
  }

  for (int i = 1; i <= n; i ++ ) {
    for (int j = i + 1; j <= n; j ++ ) {
      ll P = 0;
      for (int l = 1; l <= k; l ++ ) {
        int p;
        if (a[i][l] == a[j][l]) {
          p = a[i][l];
        } else {
          p = (a[i][l] ^ a[j][l] ^ 0 ^ 1 ^ 2);
        } 
        int bit1 = (l - 1) * 2, bit2 = (l - 1) * 2 + 1;
        if (p == 0) {
          P |= 1ll << bit1;
        } else if (p == 1) {
          P |= 1ll << bit2;
        } else {
          P |= 1ll << bit1;
          P |= 1ll << bit2;
        }
      }
      if (mp.count(P)) {
        ans[mp[P]] ++;
        // cout << i << " " << j << " " << mp[p] << "\n";
      }
    }
  }
  // for (int i = 1; i <= n; i ++ ) {
  //   cout << ans[i] << " \n"[i == n];
  // }
  ll ret = 0;
  for (int i = 1; i <= n; i ++ ) {
    //C(n, 2)
    ll res = ans[i];
    if (ans[i] >= 2) {
      ret += (ans[i] * (ans[i] - 1)) / 2;
    }
  }

  cout << ret << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}