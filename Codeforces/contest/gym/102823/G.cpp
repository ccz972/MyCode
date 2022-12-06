#include <bits/stdc++.h>
using namespace std;
#define ll long long
#ifndef ONLINE_JUDGE
  #include <debugger>
#endif

constexpr int N = 1e5 + 10;

int n;
ll a[N], b[N];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    // b[i] = a[i] - a[i - 1];
  }

  sort(a + 1, a + 1 + n);

  for(int i = 1; i <= n; i ++ ) {
    b[i] = a[i] - a[i - 1];
  }

  ll g = 0;
  for(int i = 2; i <= n; i ++ ) {
    g = __gcd(g, b[i]);
  }

  

  ll ans;

  if(g == 0) {
    if(a[1] == 1) {
      ans = 1;
    } else {
      ans = 0;
    }
  } else if(g == 1) {
    ans = -1;
  } else {
    // vector<ll> factor;
    ans = INT64_MAX;
    for(ll i = 2; i <= g / i; i ++ ) if(g % i == 0) {
      ans = min(ans, (a[1] + i - 1) / i * i - a[1]);
      while(g % i == 0) {
        g /= i;
      }
    }
    if(g != 1) ans = min(ans, (a[1] + g - 1) / g * g - a[1]);
  }

  cout << ans;


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  for(int i = 1; i <= T; i ++ ) {
    cout << "Case " << i << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}