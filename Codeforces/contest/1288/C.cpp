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

constexpr int N = 11;
constexpr int M = 1010;
constexpr int P = 1E9 + 7;

ll ksm(ll a, ll b, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % P;
    b >>= 1;
    a = a * a % P;
  }
  return ret;
}

//结论，只要a[n] <= b[n] 即可
//预处理出f[i][j]表示长度为i结尾是j的最长不下降子序列的个数
//预处理出g[i][j]表示长度为i结尾是j的最长不上升子序列的个数
//暴力枚举即可
void solve1() {
  int n, m;
  cin >> m >> n;
  vector<vector<ll> > f(n + 1, vector<ll>(m + 1));
  vector<vector<ll> > g(n + 1, vector<ll>(m + 1));
  for (int i = 1; i <= m; i ++ ) {
    f[1][i] = g[1][i] = 1;
  }
  for (int i = 2; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      for (int k = 1; k <= j; k ++ ) {
        f[i][j] += f[i - 1][k]; f[i][j] %= P;
      }
    }
    for (int j = 1; j <= m; j ++ ) {
      for (int k = j; k <= m; k ++ ) {
        g[i][j] += g[i - 1][k]; g[i][j] %= P;
      }
    }
  }
  
  ll ans = 0;
  for (int i = 1; i <= m; i ++ ) {
    for (int j = i; j <= m; j ++ ) {
      ans += f[n][i] * g[n][j]; 
      ans %= P;
    }
  }
  cout << ans << "\n";
}

//题目等价于构造一个长度为 2 * n 的最长不下降子序列，暴力DP
void solve2() {
  int n, m; cin >> m >> n;
  n *= 2;
  vector<vector<ll> > f(n + 1, vector<ll>(m + 1));
  f[0][0] = 1;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      for (int k = 0; k <= j; k ++ ) {
        f[i][j] += f[i - 1][k]; f[i][j] %= P;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; i ++ ) {
    ans += f[n][i]; ans %= P;
  }
  cout << ans << "\n";
}
//f[i][j][k]表示长度为i，a结尾是j，b结尾是k的合法子序列个数，前缀和优化DP
void solve3() {
  int n, m; cin >> m >> n;
  vector<vector<vector<ll> > > f(2, vector<vector<ll> > (m + 1, vector<ll>(m + 1)));
  vector<vector<vector<ll> > > s(2, vector<vector<ll> > (m + 1, vector<ll>(m + 1)));
  
  for (int i = 1; i <= m; i ++ ) {
    for (int j = i; j <= m; j ++ ) {
      f[1][i][j] = 1;
    }
  }

  auto Get = [&] (int flag, int l1, int r1, int l2, int r2, ll ret = 0) -> ll {
    ret += s[flag][l2][r2];
    ret -= s[flag][l1 - 1][r2];
    ret -= s[flag][l2][r1 - 1];
    ret += s[flag][l1 - 1][r1 - 1];
    ret = ((ret % P) + P) % P;
    return ret;
  };

  auto Set = [&] (int flag) -> void {
    for (int i = 1; i <= m; i ++ ) {
      for (int j = 1; j <= m; j ++ ) {
        ll &ret = s[flag][i][j];
        ret = s[flag][i - 1][j] + s[flag][i][j - 1] - s[flag][i - 1][j - 1] + f[flag][i][j];
        ret = ((ret % P) + P) % P;
      }
    }
  };

  Set(1);

  for (int i = 2; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      for (int k = j; k <= m; k ++ ) {
        f[i & 1][j][k] = Get(i - 1 & 1, 1, k, j, m);
      }
    }
    Set(i & 1);
  }
  cout << s[n & 1][m][m];

}
//答案即是C(m + 2 * n - 1, 2 * n)
void solve4() {
  int n, m; cin >> m >> n;
  int nn = m + 2 * n; // mm = 2 * n + 1;
  vector<ll> fact(nn), infact(nn);
  fact[0] = infact[0] = 1;
  for (int i = 1; i < nn; i ++ ) fact[i] = fact[i - 1] * i % P;
  infact[nn - 1] = ksm(fact[nn - 1], P - 2);
  for (int i = nn - 2; i >= 1; i -- ) infact[i] = infact[i + 1] * (i + 1) % P;
  auto get = [&] (int x, int y) -> ll {
    if (x < y) return 0ll;
    return fact[x] * infact[y] % P * infact[x - y] % P;
  };
  cout << get(m + 2 * n - 1, 2 * n);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve4();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
