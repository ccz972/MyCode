/***************************************************

@File    : B.cpp
@Time    : 2022/07/16 22:40:24
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

constexpr int N = 1E5 + 10;

int a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, l, r; cin >> n >> l >> r;
    bool f = true;
    for(int i = 1; i <= n && f; i ++ ) {
      if(r / i * i >= l) {
        a[i] = r / i * i;
      } else {
        f = false;
      }
    }
    if(f) {
      cout << "YES\n";
      for(int i = 1; i <= n; i ++ ) {
        cout << a[i] << " \n"[i == n];
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}