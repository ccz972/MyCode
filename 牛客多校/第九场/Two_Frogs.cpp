#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

constexpr int N = 8010;
constexpr int P = 998244353;

int ksm(int a, int b, int ret = 1) {
  while(b) {
    if(b & 1) ret = 1ll * ret * a % P;
    b >>= 1;
    a = 1ll * a * a % P;
  }
  return ret;
}

ll a[N], inv[N];
ll f[N][N];

void solve() {
  ll n; cin >> n;
  for(int i = 1; i < n; i ++ ) {
    cin >> a[i]; 
    inv[i] = ksm(a[i], P - 2);
  }

  f[0][1] = 1;

  for(int i = 0; i < n; i ++ ) {
    for(int j = i + 1; j < n; j ++ ) {
      ll now = 1ll * f[i][j] * inv[j] % P;
      f[i + 1][j + 1] += now; f[i + 1][j + 1] %= P;
      f[i + 1][min(n + 1,j + a[j] + 1)] += P - now;   
      f[i + 1][min(n + 1,j + a[j] + 1)] %= P;
    }
    f[i + 1][0] %= P;
    for(int j = 1; j <= n + 1; j ++ ) {
      f[i + 1][j] += f[i + 1][j - 1];
      f[i + 1][j] %= P;
    }
  }

  ll ans = 0;

  for(int i = 1; i < n; i ++ ) {
    ll now = f[i][n];
    now = 1ll * now * now % P;
    ans += now; ans %= P;
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