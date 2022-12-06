#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  int res = 0;
  ll ans = 1;
  for(int i = 2; i <= n / i; i ++ ) if(n % i == 0) {
    int cnt = 0;
    while(n % i == 0) {
      n /= i;
      cnt ++;
      if(~cnt & 1) ans *= i;
    }
    if(cnt & 1) res ++, ans *= i;
  }
  if(n != 1) res ++, ans *= n;
  if(res) res ++;
  cout << ans << " " << res << "\n";

  return 0;
}