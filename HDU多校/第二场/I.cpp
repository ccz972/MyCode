/***************************************************

@File    : L.cpp
@Time    : 2022/07/27 09:08:33
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

bool isok(ll x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x % 2 == 0) return false;
  for(ll i = 3; i <= x / i; i += 2) if(x % i == 0) {
    return false;
  }
  return true;
}

void solve() {
  ll p, q, e; scanf("%lld%lld%lld", &p, &q, &e);
  ll m = p * q - 1;

  for(ll i = 1; i <= m / i; i ++ ) if(m % i == 0) {
    ll j = m / i;
    ll r = e * q % i;
    if(i > max({p, q, e}) && e == r * p % i && isok(i)) {
      printf("%lld\n", r);
      return ;
    }
    r = e * q % j;
    if(j > max({p, q, e}) && e == r * p % j && isok(j)) {
      printf("%lld\n", r);
      return ;
    }
  }
  puts("shuanQ");
}

int main() {
// #ifdef LOCAL
//   // freopen("L.out", "w", stdout);
// #endif
  int T = 1; 
  scanf("%d", &T);
  while(T -- ) {
    solve();
  }
}