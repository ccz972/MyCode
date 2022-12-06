#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

#include <random>

int seed;
  std::mt19937 rng(seed);
  std::uniform_int_distribution<> u(1,400);
#define ay3 array<int, 3> 

constexpr int N = 410;

int dp[10][N][N];

constexpr int p = 998244353;

ll ksm(ll a, ll b, ll ret = 1) {
  while(b) {
    if(b & 1) ret = ret * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return ret;
}

void solve() {
  int n, q; cin >> n >> q;
  vector<vector<array<int, 3> > > a(n, vector<array<int, 3> > ());

  memset(dp, 0x3f, sizeof dp);

  for(int i = 0; i < n; i ++ ) {
    int m; cin >> m;
    a[i].resize(m);
    for(int j = 0; j < 3 * m; j ++ ) {
      cin >> a[i][j / 3][j % 3];
    }
    for(int j = 0; j < m; j ++ ) {
      chkmin(dp[i][a[i][j][0]][a[i][j][1]], a[i][j][2]);
    }
  }
  for(int k = 0; k < n; k ++ ) {
    for(int i = 1; i <= 400; i ++ ) {
      for(int j = 1; j <= 400; j ++ ) {
        chkmin(dp[k][i][j], dp[k][i - 1][j]);
        chkmin(dp[k][i][j], dp[k][i][j - 1]);
      }
    }
  }
  
  // for(int i = 0; i < n; i ++ ) {
  //   // debug(a[i]);
  //   sort(a[i].begin(), a[i].end());
  // }
  cin >> seed;

  // sort(a.begin(), a.end());

  auto solve = [&] (int iq, int eq, int aq)  {
    ll ans = 0;
    for(int i = 0; i < n; i ++ ) {
      if(aq >= dp[i][iq][eq]) ++ ans;
    }
    return ans;

  };

  ll lastans=0;

  ll ans = 0;

  for (int i=1;i<=q;i++)
  {
    int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
    int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
    int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
    lastans=solve(IQ,EQ,AQ);  // The answer to the i-th friend
    ans += (lastans * ksm(seed, q - i)) % p;
    ans %= p;
  }  
  cout << ans;


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
