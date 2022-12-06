#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= b; ++ i)

constexpr int N = 1E5 + 10;

int a[N];

void solve() {
  int n, k; cin >> n >> k;
  rep (i, 1, n) cin >> a[i];
  int id = 1;
  rep (i, 1, n) if (a[i] > a[id]) {
    id = i;
  }
  
  if (id <= k || (n - id + 1 <= k)) {
    cout << (n - 1 + k - 2) / (k - 1);
  } else {
    int ans = INT_MAX;
    for (int i = id - 1; i >= max(0, id - k); i -- ) {
      int now = (i + k - 2) / (k - 1);
      now += 1;//[i + 1,i + k], [i + k + 1, n]
      if (i + k + 1 <= n) {
        now += (n - (i + k + 1) + 1 + k - 2) / (k - 1);
      }
      // cout << i << " " << now << "\n";
      ans = min(ans, now);
    }
    cout << ans; 
  }


  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}