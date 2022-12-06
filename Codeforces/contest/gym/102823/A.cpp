#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
  #include <debugger>
#endif

void solve() {
  int n, m; cin >> n >> m;
  ll ans = 0;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i ++ ) cin >> a[i];
  for(int i = 0; i < m; i ++ ) cin >> b[i];

  //2 2

  ll now = 0;
  for(int i = 0, j = 0; i < n || j < m; ) {
    ++ now;
    if(i == n) {
      ans += now * b[j ++];
    } else if(j == m) {
      ans += now * a[i ++ ];
    } else {
      if(a[i] < b[j]) {
        ans += now * a[i];
      } else {
        ans += now * b[j];
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();
  return 0;
}