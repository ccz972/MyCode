/***************************************************

@File    : A.cpp
@Time    : 2022/07/16 22:35:56
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
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    // int res = a[1] - a[0];
    // int res = a[1] % a[0];
    
    bool f = true;
    for(int i = 1; i < n; i ++ ) {
      if(a[i] % a[0] != 0) {
        f = false;
      }
    }
    if(f) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}