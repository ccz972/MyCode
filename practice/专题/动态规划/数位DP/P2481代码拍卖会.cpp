#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

const int MOD = 999911659;

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

};

typedef modint<MOD> mint;

inline mint ksm(mint a, int b) {
	mint ret = 1; 
	for(; b; b >>= 1, a = a * a ) if(b & 1) ret = ret * a ;
	return ret;
}

constexpr int N = 510;

mint fact[N + 1], infact[N + 1], inv[N + 1];
mint C[N][12];
// dp[i][j][k] 表示考虑到第i个数字，选了k个，和模p为j的方案数字
mint dp[N][N][12]; 
int p, pos[N], e;
ll n, cnt[N];

void init() {
  inv[1] = 1;
  for(int i = 2; i < 9; i ++ ) inv[i] = inv[MOD % i] * (MOD - MOD / i);

  int sum = 0;
  if(n <= p) {
    for(int i = 1; i <= n; i ++ ) {
      sum = (sum * 10 + 1) % p;
      cnt[sum] ++;
    }
    e = sum;
  } else {
    int st, len; //循环节的起点和长度
    for(int i = 1; i <= p + 1; i ++ ) {
      sum = (sum * 10 + 1) % p;
      if(pos[sum]) {
        st = pos[sum];
        len = i - pos[sum];
        break;
      }
      pos[sum] = i;
      cnt[sum] ++;
    }
    for(int i = 0; i < p; i ++ ) if(cnt[i] && pos[i] >= st) {
      cnt[i] = (n - st + 1) / len;
      if(pos[i] - st + 1 <= (n - st + 1) % len) cnt[i] ++;
      if((pos[i] - st + 1) % len == (n - st + 1) % len) e = i;
      cnt[i] %= MOD;
    }
  }

  for(int i = 0; i < p; i ++ ) {
    C[i][0] = 1; if(cnt[i]) {
      for(int j = 1; j < 9; j ++ ) {
        C[i][j] = (C[i][j - 1] * cnt[i]) * inv[j];
        cnt[i] = (cnt[i] + 1) % MOD;
      }
    }
  }

}

void gen() {
  dp[0][e][0] = 1;
  for(int i = 0; i < p; i ++ ) {
    for(int j = 0; j < p; j ++ ) {
      for(int k = 0; k < 9; k ++ ) {
        for(int l = 0; l <= k; l ++ ) if(dp[i][(p + j - (l * i % p)) % p][k - l] > 0) {
          dp[i + 1][j][k] += 
          dp[i][(p + j - (l * i % p)) % p][k - l] * C[i][l];
        }
      }
    }
  }
  mint ans = 0;
  for(int i = 0; i < 9; i ++ ) {
    ans += dp[p][0][i];
  }
  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  freopen("3.in", "r", stdin);
  freopen("3.out", "w", stdout);
#else 
  cin.tie(nullptr)->sync_with_stdio(false);
#endif

  cin >> n >> p;
  init();
  gen();

    
  return 0;
}