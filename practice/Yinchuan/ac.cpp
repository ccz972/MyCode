#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define all(a) a.begin(), a.end()
#define int ll

constexpr int MOD = 998244353;

int logab(int a, int b) {
  int now = 1;
  int ans = 0;
  while (now * a <= b) {
    ++ ans;
    now *= a;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  int sum = 0;
  // cout << round(3.1) << " " << ceil(3.1) << "\n";
  for (int i = 2; i <= n; i ++ ) {
    int now = 0;
    for (int j = i; j <= n; j ++ ) {
      // cout << j << " " << log(j) << "\n";
      // assert(int((ceil)(log2(i) / log2(j))) == 1);
      // cout << j << " " << log2(j) << "\n";
      // cout << i << " " << log2(i) << "\n";
      // cout << "int((round)(log2(j) / log2(i))) = " << int(flo(log2(j) / log2(i))) << "\n";
      // cout << log2(j) / log2(i) << "\n";
      now += logab(i, j);
      // now += int(floor(log2(j) / log2(i)));// * int((ceil)(log2(i) / log2(j)));
      now %= MOD;
    } 
    
    now *= i;  now %= MOD;
    sum += now; sum %= MOD;
  }
  cout << sum << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}