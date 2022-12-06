/***************************************************

@File    : F.cpp
@Time    : 2022/07/17 13:14:06
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

constexpr ll INF = 1E9 + 1;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  map<ll, int> mp;
  for(ll i = 1; i * i * i <= INF; i ++ ) {
    mp[i * i * i] ++;
  }
  while (T--) {
    int n; cin >> n;
    int ans = 0;
    for(auto [k, v]: mp) {
      if(n % k == 0) {
        ++ ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}