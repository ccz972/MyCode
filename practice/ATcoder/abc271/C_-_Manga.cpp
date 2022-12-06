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
constexpr int N = 3E5 + 10;
int a[N];
int vis[N];
void solve() {
  int n; cin >> n;
  int cnt = 0;

  rep (i, 1, n) {
    cin >> a[i];
    if (a[i] > n || vis[a[i]]) {
      ++ cnt;
    } else {
      vis[a[i]] = 1;
    }
  }

  auto chk = [&] (int x) -> bool {
    int res = cnt;
    for (int i = x + 1; i <= n; i ++ ) {
      res += vis[i];
    }
    for (int i = 1; i <= x; i ++ ) if (!vis[i]) {
      if (res < 2) return false;
      res -= 2;
    }
    return true;
  };

  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (chk(mid)) l = mid;
    else r = mid - 1; 
  }
  cout << l << "\n";
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}