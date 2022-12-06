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

const int MOD = 1000000007;

inline int mod(int x) {return x >= MOD ? x - MOD : x;}

inline int ksm(int a, int b) {
  int ret = 1; a = mod(a);
  for(; b; b >>= 1, a = 1LL * a * a % MOD) if(b & 1) ret = 1LL * ret * a % MOD;
  return ret;
}

template<int MOD> 
struct modint {
  int x;
  modint() {x = 0; }
  modint(int y) {x = y;}
  inline modint inv() const { return modint{ksm(x, MOD - 2)}; }
  explicit inline operator int() { return x; }
  friend inline modint operator + (const modint &a, const modint& b) { return modint(mod(a.x + b.x)); }
  friend inline modint operator - (const modint &a, const modint& b) { return modint(mod(a.x - b.x + MOD)); }
  friend inline modint operator * (const modint &a, const modint& b) { return modint(1ll * a.x * b.x % MOD); }
  friend inline modint operator / (const modint &a, const modint& b) { return modint(1ll * a.x * b.inv().x % MOD); }
  friend inline modint operator + (const modint &a, const int& b) { return modint(mod(a.x + b)); }
  friend inline modint operator - (const modint &a, const int& b) { return modint(mod(a.x - b + MOD)); }
  friend inline modint operator * (const modint &a, const int& b) { return modint(1ll * a.x * b % MOD); }
  friend inline modint operator / (const modint &a, const int& b) { return modint(1ll * a.x * ksm(b, MOD - 2) % MOD); } 
  friend inline modint operator - (const modint &a) { return modint(mod(MOD - a.x)); }
  friend inline modint& operator += (modint &a, const modint& b) { return a = a + b; }
  friend inline modint& operator -= (modint &a, const modint& b) { return a = a - b; }
  friend inline modint& operator *= (modint &a, const modint& b) { return a = a * b; }
  friend inline modint& operator /= (modint &a, const modint& b) { return a = a / b; }
  friend inline modint& operator += (modint &a, const int& b) { return a = a + b; }
  friend inline modint& operator -= (modint &a, const int& b) { return a = a - b; }
  friend inline modint& operator *= (modint &a, const int& b) { return a = a * b; }
  friend inline modint& operator /= (modint &a, const int& b) { return a = a / b; }
  friend auto &operator >> (istream &i, modint &a) {return i >> a.x; }
  friend auto &operator << (ostream &o, const modint &z) { return o << z.x; }
  inline bool operator == (const modint &b) { return x == b.x; }
  inline bool operator == (const int &b) { return x == b; }
  inline bool operator != (const modint &b) { return x != b.x; }
  inline bool operator != (const int &b) { return x != b; }
  inline bool operator < (const modint &a) { return x < a.x; }
  inline bool operator < (const int &b) { return x < b; }
  inline bool operator <= (const modint &a) { return x <= a.x; }
  inline bool operator <= (const int &b) { return x <= b; }
  inline bool operator > (const modint &a) { return x > a.x; }
  inline bool operator > (const int &a) { return x > a; }
  inline bool operator >= (const modint &a) { return x >= a.x; }
  inline bool operator >= (const int &a) { return x >= a; }
  operator int() const {
    return x;
  }
  // inline void
};

typedef modint<MOD> mint;

inline mint ksm(mint a, int b, mint ret = 1) {
	for(; b; b >>= 1, a = a * a ) if(b & 1) ret = ret * a ;
	return ret;
}


constexpr int N = 1E5 + 10;

int n, m, fa[N][18];

int find(int x, int k) {
  if (fa[x][k] != x) fa[x][k] = find(fa[x][k], k);
  return fa[x][k];
}

void merge(int x, int y, int k) {
  x = find(x, k), y = find(y, k);
  if (x != y) fa[y][k] = x;
}

void solve() {
  int n, m; cin >> n >> m;
  int bit = __lg(n);
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 0; j <= bit; j ++ ) {
      fa[i][j] = i;
    }
  }
  while (m -- ) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    for (int k = bit; k >= 0; k -- ) {
      if (l1 + (1 << k) - 1 <= r1) {
        merge(l1, l2, k);
        l1 += 1 << k;
        l2 += 1 << k;
      }
    }
  }
  for (int k = bit; k >= 1; k -- ) {
    for (int i = 1; i + (1 << k) - 1 <= n; i ++ ) {
      int pos = find(i, k);
      merge(i, pos, k - 1), merge(i + (1 << k - 1), pos + (1 << k - 1), k - 1);
    }
  }
  mint ans = 0;
  for (int i = 1; i <= n; i ++ ) if (find(i, 0) == i) {
    if (ans == 0) ans = 9;
    else ans *= 10;
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
