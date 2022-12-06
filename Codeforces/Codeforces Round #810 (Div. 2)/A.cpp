/***************************************************

@File    : A.cpp
@Time    : 2022/07/24 22:30:56
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
    int n; cin >> n;
    if(n & 1) {
      cout << "1 ";
      for(int i = 2; i <= n; i ++ ) {
        cout << ((i & 1) ? i - 1 : i + 1) << " ";
      }
      cout << "\n";
    } else {
      for(int i = 1; i <= n; i ++ ) {
        cout << ((i & 1) ? i + 1 : i - 1) << " ";
      }
      cout << "\n";
    }
  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}