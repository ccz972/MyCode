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

constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x % MOD + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  // auto operator<=>(const Z &) const = default;
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

Z dp[8][10];

void solve() {
  string s; cin >> s;
  int n = s.size();
  // 长度为7
  for (int i = 0; i < 8; i ++ ) {
    for (int j = 0; j < 10; j ++ ) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i ++ ) {
    int p = s[i] - '0';
    for (int j = 0; j < 10; j ++ ) {
      if (dp[0][j].x != 0) {
        dp[1][p] += dp[0][j];
      }
      if (dp[1][j].x != 0 && j < p) {
        dp[2][p] += dp[1][j];
      }
      if (dp[2][j].x != 0 && j > p) {
        dp[3][p] += dp[2][j];
      }
      if (dp[3][j].x != 0 && j < p) {
        dp[4][p] += dp[3][j];
      }
      if (dp[4][j].x != 0 && j > p) {
        dp[5][p] += dp[4][j];
      }
      if (dp[5][j].x != 0 && j > p) {
        dp[6][p] += dp[5][j];
      }
      if (dp[6][j].x != 0 && j > p) {
        dp[7][p] += dp[6][j];
      }
    }
  }
  Z ans = 0;
  for (int i = 0; i < 10; i ++ ) if (dp[7][i].x) {
    ans += dp[7][i];
  }

  cout << ans << "\n";


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
