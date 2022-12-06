/***************************************************

@File    : C.cpp
@Time    : 2022/07/26 14:42:33
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
    vector<int> a(n), ans(n);
    for (auto& x : a) cin >> x;
    int p = 0;
    int now = n - 1;
  
    while(now >= 0 && p < k) {
      if(a[now] > p) ++ p;
      ans[now -- ] = 1;
    }
    for(int i = 0; i <= now; i ++ ) {
      if(a[i] <= k) ans[i] = 1;
    }
    for(int i = 0; i < n; i ++ ) {
      cout << ans[i];
    }
    cout << "\n";
    

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}