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

constexpr int N = 5010;

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

char str[N];

Z f[N][N], sum[N][N];
int lcp[N][N];
int n, a[N];
string s;

void solve() {
  cin >> n;
  cin >> s;
  s = " " + s;

  for (int i = n; i >= 1; i -- ) {
    for (int j = n; j >= 1; j -- ) if (s[i] == s[j]) {
      lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }

  for (int i = 1; i <= n; i ++ ) f[1][i] = 1;
  sum[1][1] = 1;

  auto check = [&] (int l, int r) {
    //l... r....
    if (lcp[l][r] >= r - l) return false;
    return s[l + lcp[l][r]] < s[r + lcp[l][r]];
  };

  for (int j = 2; j <= n; j ++ ) {
    for (int i = 2; i <= j; i ++ ) {
      if (s[i] == '0') continue;
      //12345i.....j
      //len = j - i + 1
      //j-i=i-1-k
      int k = 2 * i - j; //k=4  i=5
      k = max(1, k);
      //sum[i][j] 表示右端点为i且左端点为1-j的总方案数
      Z ret = sum[i - 1][i - 1] - sum[i - 1][k - 1];
      f[i][j] += ret;
      // if (i == 5 && j == 6) cout << f[i][j] << " ::\n";
      -- k; //k... | i....j
      
      // if (i == 5 && j == 6) cout << k << " ::\n";
      if (k >= 1 && i - 1 >= k && check(k, i)) f[i][j] += f[k][i - 1];
      // if (i == 5 && j == 6) cout << f[i][j] << " ::\n";
    }

    for (int i = 1; i <= j; i ++ ) {
      sum[j][i] = sum[j][i - 1] + f[i][j];
      // if (i == 1 && j == 2) cout << sum[j][i] << " " << f[i][j] << "\n";
    }

  }

  // if (check(3,5)) cout << "FUCK\n";

  // cout << "f[1][2] = " << f[1][2] << "\n";
  Z ans = 0;
  // for (int j = 1; j <= n; j ++ ) {
  //   for (int i = 1; i <= j; i ++ ) {
  //     cout << sum[j][i] << " \n"[i == j];
  //   }
  // }
  for (int i = 1; i <= n; i ++ ) {
    // debug(i, f[i][n]);
    // cout << i << " " << f[i][n] << "\n";
    ans += f[i][n];
  }
  cout << ans << "\n";
  //  123456



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
