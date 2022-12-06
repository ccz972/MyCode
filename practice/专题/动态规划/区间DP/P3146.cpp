#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 250;

int a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector f(n, vector<int>(n, -1e9));
  int ans = 0;
  for (auto i = 0; i < n; i ++ ) {
    cin >> a[i];
    f[i][i] = a[i];
    ans = max(ans, a[i]);
  }

  for (int len = 2; len <= n; len ++ ) {
    for (int l = 0; l + len - 1 < n; l ++ ) {
      int r = l + len - 1;
      for (int k = l; k < r; k ++ ) {
        if(f[l][k] == f[k + 1][r] && f[l][k] > 0) {
          f[l][r] = max(f[l][r], f[l][k] + 1);
          ans = max(ans, f[l][r]);
        }
      }
    }
  }
  
  cout << ans << "\n";
  

  return 0;
}