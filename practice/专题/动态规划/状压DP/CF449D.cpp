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

inline int mod(int x) {return x >= MOD ? x - MOD : (x < 0 ? x + MOD : x);}

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




const int N = 1E6 + 10;

mint pow2[N + 1];

void init() {
  pow2[0] = 1;
  rep(i, 1, N) pow2[i] = pow2[i - 1] * 2;
}


int n, a[N], sum[1 << 20];

void solve() {
  /*
  sum[i]表示状态为i的子集的所有的个数

  题目求 & 的和为 0 的方案数

  考虑求不为0的方案数，然后不为0即有 1、2、3、4...位不为0，考虑容斥
  
  于是现在只要求对于任意 bitmask x，x 内的位不被满足，其他位随便的方案数。这显然就是只有 x 的补 bitmask 的子集才能选，
  而且任意一种选的方案都是可以的，那么设 x 的补 bitmask 的子集中有 cnt 个给定的，
  那么它对答案的贡献就是 2^{cnt} 乘以容斥系数(1 / -1)。
  
  */

  cin >> n;
  int bit = (1 << 20) - 1;
  rep(i, 1, n) { cin >> a[i]; sum[bit ^ a[i]] ++; }
  
  for (int j = 0; j < 20; j ++ ) {
    for (int i = 0; i < 1 << 20; i ++ ) if (i >> j & 1) {
      sum[i] += sum[i ^ (1 << j)];
    }
  }

  mint ans = pow2[n];

  for (int i = 0; i < bit; i ++ ) {
    int now = __builtin_popcount(i);
    now = (now & 1) ? -1 : 1;
    ans += pow2[sum[i]] * now;
  }

  cout << ans << "\n";




}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  init();
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}