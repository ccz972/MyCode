/***************************************************

@File    : C.cpp
@Time    : 2022/07/26 14:26:31
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

  auto solve = [&] () {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    auto chk = [&] (int x) {
      int p = k;
      for(int i = x; i < n; i ++ ) {
        if(a[i] > p) {
          -- p;
        }
      }
      return p >= 0;
    };
    int l = 0, r = n - 1;
    while(l < r) {
      int mid = (l + r) / 2;
      if(!chk(mid)) l = mid + 1;
      else r = mid;
    } 
    for(int i = 0; i < n; i ++ ) if(i < l) {
      if(a[i] <= k) cout << "1";
      else cout << "0";
    } else {
      cout << "1";
    }
    cout << "\n";
  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}