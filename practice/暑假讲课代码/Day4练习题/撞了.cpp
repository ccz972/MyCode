#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is(ll x) {
  if(x == 1) return false;
  ll l = 0, r = 1000000;
  while(l < r) {
    ll mid = (l + r) / 2;
    if(mid * mid >= x) r = mid;
    else l = mid + 1;
  }
  return l * l == x;
}

void solve() {
  ll n; cin >> n;
  vector<ll> factor;
  for(ll i = 1; i <= n / i; i ++ ) if(n % i == 0) {
    factor.push_back(i);
    if(i != n / i) factor.push_back(n / i);
  }

  sort(factor.begin(), factor.end());
  reverse(factor.begin(), factor.end());
  for(int i = 0; i < factor.size(); i ++ ) {
    ll x = factor[i];
    if(is(x)) continue;
    bool flag = true;
    for(ll j = 2; j <= x / j && flag; j ++ ) if(x % j == 0) {
      if(is(j) || is(x / j)) {
        flag = false;
      }
    }
    if(flag) {
      cout << x << "\n";
      return ;
    } 
  }


}

int main() {
  solve();
  return 0;
}