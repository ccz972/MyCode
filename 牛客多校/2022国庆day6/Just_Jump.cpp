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

namespace Nanfeng1 {
  constexpr int N = 1E7 + 10;
  constexpr int M = 3E3 + 10;
  constexpr int P = 998244353;

  int L, d, m; 
  int f[N], s[N];
  int fact[N + 10], infact[N + 10];
  ll dp[M];

  struct node {
    int t, p;
    bool operator< (const node &T) const {
      return p < T.p;
    }
  } a[M];

  ll ksm(ll a, ll b, ll ret = 1) {
    while (b) {
      if (b & 1) ret = 1ll * ret * a % P;
      b >>= 1;
      a = 1ll * a * a % P;
    }
    return ret;
  }

  void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= N; i ++ ) fact[i] = 1ll * fact[i - 1] * i % P;
    infact[N] = ksm(fact[N], P - 2);
    for (int i = N - 1; i >= 1; i -- ) infact[i] = 1ll * infact[i + 1] * (i + 1) % P;
  }

  int C(int a, int b) {

    if (a < 0 || a < b) return 0;
    assert(a < N && b < N);
    assert(a >= b && a >= 0 && b >= 0);
    return 1ll * fact[a] * infact[b] % P * infact[a - b] % P;
  }

  int F(ll a, ll b) {
    if (a == 0) {
      return (b == 0);
    }
    if (a < 0) return 0;
    if (b < a * d) return 0;
    return C(b - d * a + a - 1, a - 1);
  }

  void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
  }

  void solve() {
    cin >> L >> d >> m;
    f[0] = s[0] = 1;
    for (int i = 1; i <= L; i ++ ) {
      if (i >= d) {
        f[i] = s[i - d];
      }
      s[i] = s[i - 1];
      add(s[i], f[i]);
    }
    for (int i = 0; i < m; i ++ ) {
      cin >> a[i].t >> a[i].p;
    }
    sort(a, a + m);
    for (int i = 0; i < m; i ++ ) {
      auto [ti, pi] = a[i];
      dp[i] = F(ti, pi);
      if (dp[i] == 0) continue;
      for (int j = 0; j < i; j ++ ) {
        auto [tj, pj] = a[j];
        if (tj >= ti) continue;
        if (pi - pj < (ti - tj) * d) continue;
        dp[i] = (((1ll * dp[i] - (1ll * dp[j] * F(ti - tj, pi - pj) % P)) % P) + P) % P;
        //
      }
    }
    ll ans = f[L];
    for (int i = 0; i < m; i ++ ) {
      auto [ti, pi] = a[i];
      ans = (((ans - 1ll * dp[i] * f[L - pi]) % P) + P) % P;
    }
    cout << ans << "\n";
  }
}

namespace Nanfeng {
  constexpr int N = 1E7 + 10;
  constexpr int M = 3E3 + 10;
  constexpr int P = 998244353;

  int L, d, m; 
  int f[N], s[N];
  int fact[N + 10], infact[N + 10];
  ll dp[2][M];

  struct node {
    int t, p;
    bool operator< (const node &T) const {
      return t < T.t;
    }
  } a[M];

  ll ksm(ll a, ll b, ll ret = 1) {
    while (b) {
      if (b & 1) ret = 1ll * ret * a % P;
      b >>= 1;
      a = 1ll * a * a % P;
    }
    return ret;
  }

  void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= N; i ++ ) fact[i] = 1ll * fact[i - 1] * i % P;
    infact[N] = ksm(fact[N], P - 2);
    for (int i = N - 1; i >= 1; i -- ) infact[i] = 1ll * infact[i + 1] * (i + 1) % P;
  }

  int C(int a, int b) {

    if (a < 0 || a < b) return 0;
    assert(a < N && b < N);
    assert(a >= b && a >= 0 && b >= 0);
    return 1ll * fact[a] * infact[b] % P * infact[a - b] % P;
  }

  int F(ll a, ll b) {
    if (a == 0) {
      return (b == 0);
    }
    if (a < 0) return 0;
    if (b < a * d) return 0;
    return C(b - d * a + a - 1, a - 1);
  }

  void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
  }

  void solve() {
    cin >> L >> d >> m;
    for (int i = 1; i <= m; i ++ ) {
      cin >> a[i].t >> a[i].p;
    }

    sort(a + 1, a + 1 + m);
    f[0] = s[0] = 1;

    for (int i = 1; i <= L; i ++ ) {
      if (i >= d) {
        f[i] = s[i - d];
      }
      s[i] = s[i - 1];
      add(s[i], f[i]);
    }

    ll ans = f[L];
    dp[0][0] = 1;
    for (int i = 1; i <= m; i ++ ) {
      for (int k = 0; k < 2; k ++ ) {
        for (int j = 0; j < i; j ++ ) {
          ll delta_p = a[i].p - a[j].p, Delta_t = a[i].t - a[j].t;
          if (delta_p <= 0 || Delta_t <= 0 || delta_p < Delta_t * d) continue;
          // dp[k][i] += (dp[k ^ 1][j] * F(Delta_t, delta_p)) % P;
          // dp[k][i] %= P;
          dp[k][i] = (dp[k][i] + ((dp[k ^ 1][j] * F(Delta_t, delta_p)) % P)) % P;
        }  
      }
      // ans += ((dp[0][i] - dp[1][i] + P) % P) * f[L - a[i].p] % P;
      // ans %= P;
      ans = (ans + (((dp[0][i] - dp[1][i]) % P + P) % P) * f[L - a[i].p] % P) % P;
    }
    cout << (ans + P) % P << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Nanfeng::init();
  Nanfeng::solve();

  return 0;
}