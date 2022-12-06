/***************************************************

@File    : B.cpp
@Time    : 2022/07/17 13:27:39
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
struct splitmix64 {
    size_t operator()(size_t x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};
unordered_map<ll, int, splitmix64> mp;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  
  ll ans = 0;
  vector<ll> a(n);
  for (auto& x : a) cin >> x; //mp[x] ++;

  // map<ll, int> mp;

  mp[a.back() * a.back()] ++;
  for(int i = n - 2; i >= 0; i -- ) {
    

    bool f = false;

    for(int j = i + 1; j < n && !f; j ++ ) {
      if(a[i] == 0) {
        if(mp[0]) f = true;
        else continue;
      }
      if(a[j] == 0 || (a[i] % a[j])) continue;
      if(mp[a[i] / a[j]]) {
        f = true;
      }
    }
    // if(f) cout << i << "\n";
    ans += f;
    for(int j = i; j < n; j ++ ) {
      mp[a[i] * a[j]] ++;
    }
  }
  

	cout << ans;
  return 0;
}

  
