#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if(m == 1) {
      cout << (n - 2 + 1) / 2 << "\n";
      continue;
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i ++ ) {
      if(a[i] > a[i - 1] + a[i + 1]) {
        ++ ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}