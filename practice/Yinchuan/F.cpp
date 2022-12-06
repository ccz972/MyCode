#include <bits/stdc++.h>
#define int long long 
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define all(a) a.begin(), a.end()

constexpr int MOD = 998244353;

void add(int &x, int y) {
  x += y;
  // if (x >= MOD) x -= MOD;
  x %= MOD;
}

int ksm(int x, int y, int ret = 1) {
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return ret;
}

void solve() {
  int n; cin >> n;
  int t = min((long long)1E6, n);
  // t = sqrt(n + 10) + 1; t = min(t, n);
  int ans = 0;
  for(int i = 2; i <= t; i ++){
    int temp = 0;
    int j = i;  int now = 1;
    while (j <= n) {
      int k = min(n, j * i - 1);
      int cnt = k - j + 1;
      // ans += cnt * now;
      add(temp, cnt * now);
      ++ now;      
      j = k + 1;
    }
    temp *= i; temp %= MOD;
    add(ans, temp);
  }
  
  if (t < n) {
    int inv6 = ksm(6, MOD - 2);
    int inv2 = ksm(2, MOD - 2);
    auto get1 = [=] (int x) {
      int X1 = x % MOD, X2 = (x + 1) % MOD, X3 = (2 * x + 1) % MOD;
      return X1 * X2 % MOD * X3 % MOD * inv6 % MOD;
    };

    auto get2 = [=] (int x) {
      int X1 = x % MOD, X2 = (n + t + 1) % MOD, X3 = (n - t) % MOD;
      return X1 * X2 % MOD * X3 % MOD * inv2 % MOD;
    };

    int sum1 = get2(n + 1);
    int sum2 = get1(n) - get1(t);
    
    ans += sum1; ans %= MOD;
    ans -= sum2; ans %= MOD;
    ans = (ans + MOD) % MOD;
  }
  

  cout << ans << "\n";

  


  


}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}