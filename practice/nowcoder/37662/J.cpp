/***************************************************

@File    : J.cpp
@Time    : 2022/07/14 23:09:52
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {

    ll a, b, c; cin >> a >> b >> c;
    if(a == b && b == c) {
      cout << "-1\n";
      continue;
    }

    ll x = abs(a - b), y = abs(a - c), z = abs(b - c);
    ll p = __gcd(x, __gcd(y, z));
    vector<ll> ans;
    for(ll i = 1; i <= p / i; i ++ ) if(p % i == 0) {
      if(x % i == y % i && y % i == z % i) {
        ans.push_back(i);
      } 
      if(p / i != i) {
        if(x % (p / i) == y % (p / i) && y % (p / i) == z % (p / i)) {
          ans.push_back(p / i);
        } 
      }
    }
    sort(ans.begin(), ans.end());
    for(ll x: ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}