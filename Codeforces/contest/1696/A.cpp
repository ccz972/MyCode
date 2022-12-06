#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for(int &x: a) {
      cin >> x;
      ans = max(ans, x | k);
    }
    cout << ans << "\n";
  }
}