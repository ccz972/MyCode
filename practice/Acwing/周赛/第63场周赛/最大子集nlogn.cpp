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

constexpr int N = 2E5 + 10;

ll a[N];
int nxt[N];
ll ans[2];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  sort(a + 1, a + 1 + n);
  a[n + 1] = 1E18;
  for(int k = 0; k <= 31; k ++ ) {
    ll now = 1ll << k;
    memset(nxt, 0, sizeof nxt);
    for(int i = 1, j = 1; i <= n; i ++ ) {
      while(j + 1 <= n && a[j + 1] - a[i] <= now) ++ j;
      if(a[j] - a[i] == now) {
        nxt[i] = j;
      } else {
        nxt[i] = -1;
      }
    }

    for(int i = 1; i <= n; i ++ ) {
      // cout << nxt[i] << " \n"[i == n];
      if(nxt[i] != -1) {
        ans[0] = a[i], ans[1] = a[nxt[i]];
        if(nxt[nxt[i]] != -1) {
          cout << "3\n";
          cout << a[i] << " " << a[nxt[i]] << " " << a[nxt[nxt[i]]] << "\n";
          return ;
        }
      }
    }
  }
  if(ans[0] == 0 && ans[1] == 0) {
    cout << "1\n";
    cout << a[1] << "\n";
  } else {
    cout << "2\n";
    cout << ans[0] << " " << ans[1] << "\n";
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();

  return 0;
}
