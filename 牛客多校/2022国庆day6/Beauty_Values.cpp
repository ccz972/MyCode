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


constexpr int N = 1E5 + 10;

int n;
int a[N], last[N], vis[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    last[i] = vis[a[i]];
    vis[a[i]] = i;
  } 
  //12 121 1231
  //
  ll ans = 0;
  for (int i = 1; i <= n; i ++ ) {
    int l = i - last[i];
    int r = n - i + 1;
    ans += 1ll * l * r ; 
  }
  cout << ans << "\n";  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}