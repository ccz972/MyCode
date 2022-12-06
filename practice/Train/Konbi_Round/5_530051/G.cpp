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

constexpr int MOD =  1E9 + 7;

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
  fact[0] = 1; for(int i = 1; i <= N; ++ i ) { fact[i] = fact[i - 1] * i; }
  infact[N] = ksm(fact[N], MOD - 2); for(int i = N - 1; i >= 0; -- i ) infact[i] = infact[i + 1] * (i + 1);
  inv[0] = inv[1] = 1; for(int i = 2; i <= N; ++ i) inv[i] = inv[MOD % i] * (MOD - MOD / i);
}

mint C(int a, int b) {
  if (a < b) return 0;
  return fact[a] * infact[b] * infact[a - b];
}

bool check(int x) {
  for (int j = 2; j <= x / j; j ++ ) if (x % j == 0) {
    return false;
  }
  return true;
}

bool ok(int x) {
  for (int i = 1; i <= 9; i ++ ) if (i * i == x) return true;
  return false;
}


void solve() {
  init();
  int n; cin >> n;
  vector<int> cnt(71);
  rep(i, 1, n) {int x; cin >> x; cnt[x] ++ ;}
  vector<int> p, mp(32, -1);
  for (int i = 2; i <= 31; i ++ ) if (check(i)) p.pb(i);
  for (int i = 0; i < 11; i ++ ) mp[p[i]] = i;
  int m = 1 << 11;
  vector<mint> f(m, 0);
  f[0] = 1;
  for (int i = 1; i <= 70; i ++ ) if (cnt[i]) {
    if (ok(i)) {
      mint res = ksm(2, cnt[i]);
      for (int j = 0; j < m; j ++ ) {
        f[j] *= res;
      }
    } else if (!check(i) || i <= 31) {
      // map<int, int> p; 
      int x = i, bit = 0;
      for (int j = 2; j <= x / j; j ++ ) if (x % j == 0) {
        int ct = 0;
        while (x % j == 0) {
          ++ ct; x /= j;
        }
        if (ct & 1) bit |= 1 << (mp[j]);
      }

      if (x != 1) bit |= 1 << mp[x];

      auto g = f;

      mint res = ksm(2, cnt[i] - 1) - 1;
      for (int j = 0; j < m; j ++ ) {
        f[j] += g[j] * res;
      }

      res += 1;
      
      for (int j = 0; j < m; j ++ ) {
        f[j] += g[bit ^ j] * res;
      }

    } else {
      mint res = ksm(2, cnt[i] - 1) - 1;
      for (int j = 0; j < m; j ++ ) {
        f[j] += f[j] * res; //ksm(2, cnt[i] - 1);
      }
    }
  }
  f[0] -= 1;
  cout << f[0] << "\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}