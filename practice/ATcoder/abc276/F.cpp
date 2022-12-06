#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

constexpr int MOD = 998244353;

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
  for (; b; b >>= 1, a = a * a) if (b & 1) ret = ret * a; 
  return ret;
}

const int N = 2e5 + 10;

mint fact[N + 1], infact[N + 1], inv[N + 1];

void init() {
  fact[0] = 1; for(int i = 1; i <= N; ++ i ) { fact[i] = mint(i) * i; }
  for (int i = 1; i <= N; i ++ ) infact[i] = fact[i].inv();
  // infact[N] = ksm(fact[N], MOD - 2); for(int i = N - 1; i >= 0; -- i ) infact[i] = infact[i + 1] * (i + 1);
  // inv[0] = inv[1] = 1; for(int i = 2; i <= N; ++ i) inv[i] = inv[MOD % i] * (MOD - MOD / i);
}

mint C(int a, int b) {
  if (a < b) return 0;
  return fact[a] * infact[b] * infact[a - b];
}

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  T get(int l, int r) {
    return get(r) - get(l - 1);
  }

};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  fenwick<mint> fen(N + 1);
  fenwick<int> cnt(N + 1);
  vector<mint> dp(n);
  dp[0] = a[0];
  fen.modify(a[0], a[0]);
  cnt.modify(a[0], 1);
  Rep(i, 1, n) {
    dp[i] = dp[i - 1] * fact[i] * infact[i + 1];
    mint Cnt = cnt.get(a[i]) * 2;
    mint ret = Cnt * a[i];
    ret += a[i];
    ret += fen.get(a[i] + 1, N) * 2;
    ret *= infact[i + 1];
    dp[i] += ret;  
    cnt.modify(a[i], 1);
    fen.modify(a[i], a[i]);
  }
  Rep(i, 0, n) {
    cout << dp[i] << "\n";
  }
  //dp[i] 表示前i个的期望值

  //
  /**
   * 对于多一个 a_{i+1}来说，首先他会将前面的期望值dp[i] * ()
   * i次的次数是 i!, 则会将前面的期望除以 (i+1)!  XXXX
   * i次的次数是 i * i, 则会将前面的期望除以 (i+1) * (i + 1)  YESYESYES  
   * 然后考虑 a_{i+1}造成的期望，对于小于等于 a_{i+1}的期望值是 cnt * a_{i+1}
   * 大于a_{i+1}是 sum{} 
   * 做法是维护两个树状数组，一个统计次数，一个统计和
   * 然后dp转移即可。 
   * 感觉是很裸，我都能看出来（
  */
  // Bye ~~~
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  init();
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}