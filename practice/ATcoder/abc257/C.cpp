#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  vector<array<int, 2> > a(n);
  int ct = 0;  
  for(int i = 0; i < n; i ++ ) {
    cin >> a[i][0];
    a[i][1] = (s[i] - '0');
    ct += a[i][1];
  }
  sort(a.begin(), a.end());
  int now = 0;
  int ans = max(ct, n - ct);
  // for(int i = 0; i < n; i ++ ) {
  //   cout << a[i][0] << " " << a[i][1] << "\n";
  // }
  for(int i = 0; i < n; i ++ ) {
    now += (a[i][1] == 0);
    ct -= a[i][1];
    if(i == n - 1 || a[i][0] != a[i + 1][0])
      ans = max(ans, now + ct);
    // cout << ans << "\n";
  }
  cout << ans << "\n";

  return 0;
}