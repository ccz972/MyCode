/***************************************************

@File    : G.cpp
@Time    : 2022/07/17 13:16:52
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int mod = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
//   int n = __lg(p) + 10;
  vector<ll> f(n + 10);
  f[1] = 1;
  f[2] = 1;
  for(int i = 3; i <= n; i ++ ) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  ll ans = 0;
  for(int i = 0; i <= n; i ++ ) {
    ans = (ans + f[i]) % mod;
  }
  cout << ans;

  return 0;
}