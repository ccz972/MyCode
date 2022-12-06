#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i(a); i <= b; ++ i)
using ll = long long;

constexpr int mod = 998244353;
constexpr int N = 1e6 + 10;

int n;
ll x;
ll a[N], s[N];


void solve() {
  cin >> n >> x;
  a[0] = s[0] = 1;
  
  rep(i, 1, n) {
    cin >> a[i];
  } 

  if(!x) {
    ll ans = 1ll * n * (n + 1) / 2;
    ll cnt = 0;
    rep(i, 1, n) {
      if(a[i] == 0) {
        ans -= cnt * (cnt + 1) / 2;
        cnt = 0;
      } else {
        cnt ++;
      }
    }
    ans -= cnt * (cnt + 1) / 2;
    cout << ans << "\n";
    return ;
  }

  ll ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    if(a[i] == 0) continue;
    int j = i;
    while(j < n && a[j + 1] != 0) {
      ++ j;
    }
    map<ll, ll> mp;
    ll now = 1;
    for(int k = i; k <= j; k ++ ) {
      now *= a[k];
      now %= mod;
      mp[now] ++;
    }
    now = x;
    ll del = 1;
    for(int k = i; k <= j; k ++ ) {
      ans += mp[now];
      now *= a[k];
      del *= a[k];
      now %= mod;
      del %= mod;
      mp[del] --;
    }
    i = j;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

