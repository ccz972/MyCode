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

const int MOD = 998244353;

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

inline mint ksm(mint a, int b, mint ret = 1) {
	for(; b; b >>= 1, a = a * a ) if(b & 1) ret = ret * a ;
	return ret;
}

constexpr int N = 2E5 + 10;

int d[N], f[N], mxf[N];
vector<int> factors[N];

void init() {
  for (int i = N - 1; i >= 2; i -- ) {
    for (int j = i; j <= N; j += i) {
      d[j] = i;
    }
  }
  for (int i = 2; i < N; i ++ ) {
    for (int j = i; j != 1; j /= d[j]) {
      factors[i].emplace_back(d[j]);
    }
  }
}

void solve() {
  int n; cin >> n;
  set<int> s;
  vector<vector<array<int, 3> > > son(n + 1, vector<array<int, 3> >());
  for (int i = 1; i < n; i ++ ) {
    int u, v, x, y; cin >> u >> v >> x >> y;
    int p = __gcd(x, y); x /= p, y /= p;
    son[u].push_back({v, x, y});
    son[v].push_back({u, y, x});
    for (int &p: factors[x]) s.insert(p);
    for (int &p: factors[y]) s.insert(p);
  }
  
  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    for (auto [v, y, x]: son[u]) if (v != fa) {
      for (int& p: factors[x]) f[p] --;
      for (int& p: factors[y]) f[p] ++, chkmax(mxf[p], f[p]);
      dfs1(v, u); 
      for (int& p: factors[x]) f[p] ++;
      for (int& p: factors[y]) f[p] --;
    }
  };

  dfs1(1, 0);

  mint R = 1, ans = 0;
  
  for (int x: s) if (mxf[x] > 0) {
    while (mxf[x] -- ) {
      R *= x;
    }
  }

  function<void(int, int, mint)> dfs2 = [&] (int u, int fa, mint res) {
    ans += res; mint tmp = res;
    for (auto [v, x, y]: son[u]) if (v != fa) {
      res = tmp;
      for (int& p: factors[y]) res *= p;
      for (int& p: factors[x]) res /= p;
      dfs2(v, u, res); 
      
    }
  };

  dfs2(1, 0, R);
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}