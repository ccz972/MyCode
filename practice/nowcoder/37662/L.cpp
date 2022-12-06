/***************************************************

@File    : L.cpp
@Time    : 2022/07/15 00:07:35
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

constexpr int p = 1E9 + 7;
constexpr int N = 1E5 + 10;

int fact[N + 1], infact[N + 1];
int pow2[N + 1];
ll ans[N + 1];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;

  auto ksm = [&] (int a, int b, int ret = 1) {
    while(b) {
      if(b & 1) ret = 1ll * ret * a % p;
      b >>= 1;
      a = 1ll * a * a % p;
    }
    return ret;
  };

  fact[0] = pow2[0] = 1;

  for(int i = 1; i <= N; i ++ ) {
    fact[i] = 1ll * fact[i - 1] * i % p;
    pow2[i] = 1ll * pow2[i - 1] * 2 % p;
  }

  infact[N] = ksm(fact[N], p - 2);
  infact[0] = fact[0] = 1;

  for(int i = N - 1; i >= 1; i -- ) {
    infact[i] = 1ll * infact[i + 1] * (i + 1) % p;
  }


  while (T--) {
    int n; cin >> n;
    int ans = 1ll * fact[n] * ksm(pow2[n - __builtin_popcount(n)], p - 2) % p;
    cout << ans << "\n";

  }
  return 0;
}