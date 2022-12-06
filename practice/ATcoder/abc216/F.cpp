// https://www.cnblogs.com/Kanoon/p/15208104.html#f---max-sum-counting
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

const int MOD = 998244353;

inline int mod(int x) {return x >= MOD ? x - MOD : x;}


template<int MOD> 
struct modint {
  int x;
  modint() {x = 0; }
  modint(int y) {x = y;}
  explicit inline operator int() { return x; }
  friend inline modint operator + (const modint &a, const modint& b) { return modint(mod(a.x + b.x)); }
  friend inline modint operator - (const modint &a, const modint& b) { return modint(mod(a.x - b.x + MOD)); }
  friend inline modint operator * (const modint &a, const modint& b) { return modint(1ll * a.x * b.x % MOD); }
  friend inline modint operator / (const modint &a, const modint& b) { return modint(1ll * a.x * b.inv().x % MOD); }
  friend inline modint operator - (const modint &a) { return modint(mod(MOD - a.x)); }
  friend inline modint& operator += (modint &a, const modint& b) { return a = a + b; }
  friend inline modint& operator -= (modint &a, const modint& b) { return a = a - b; }
  friend inline modint& operator *= (modint &a, const modint& b) { return a = a * b; }
  friend inline modint& operator /= (modint &a, const modint& b) { return a = a / b; }
  friend auto &operator >> (istream &i, modint &a) {return i >> a.x; }
  friend auto &operator << (ostream &o, const modint &z) { return o << z.x; }
  inline bool operator == (const modint &b) { return x == b.x; }
  inline bool operator != (const modint &b) { return x != b.x; }
  inline bool operator < (const modint &a) { return x < a.x; }
  inline bool operator <= (const modint &a) { return x <= a.x; }
  inline bool operator > (const modint &a) { return x > a.x; }
  inline bool operator >= (const modint &a) { return x >= a.x; }
  operator int() const {
    return x;
  }
  // inline void
};

typedef modint<MOD> mint;

void solve() {
  // 排个序，然后问题转化为一个背包问题()
  int n; cin >> n;
  vector<pair<int, int> > v(n);
  for (auto& [x, y]: v) cin >> x;
  for (auto& [x, y]: v) cin >> y;
  sort(v.begin(), v.end());

  mint ans = 0;
  vector<mint> dp(v.back().first + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i ++ ) {
    auto [a, b] = v[i];
    for (int j = 0; j + b <= a; j ++ ) {
      ans += dp[j]; 
    } 
    for (int j = v.back().first; j >= b; j -- ) {
      dp[j] += dp[j - b];
    }
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