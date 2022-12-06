#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, m; cin >> n >> m;
  ll ans = n * (n + 1) * (2 * n + 1) / 6;
  ans *= m;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();
  return 0;
}

