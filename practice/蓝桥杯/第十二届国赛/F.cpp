#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int N = 2e6 + 10;

ll sum[N];

ll get(ll x) {
  ll l = 1, r = 2e6;
  while(l < r) {
    ll mid = (l + r) / 2;
    if(mid * (mid + 1) / 2 >= x) r = mid;
    else l = mid + 1;
  }
  if(l * (l + 1) / 2 == x) {
    return sum[l];
  }
  ll ret = sum[l - 1];
  ll cnt = x - (l - 1) * l / 2;
  ret += cnt * (cnt + 1) / 2;
  return ret;
}

void solve() {
  ll l, r; scanf("%lld%lld", &l, &r);
  printf("%lld\n", get(r) - get(l - 1));
}

int main() {
  for(ll i = 1; i < N; i ++ ) {
    sum[i] = sum[i - 1] + i * (i + 1) / 2;
  }
  int T; scanf("%d", &T);
  while(T -- )
    solve();
  
  return 0;
}