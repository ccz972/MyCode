/***************************************************

@File    : H.cpp
@Time    : 2022/07/14 23:22:56
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
  int n, m; cin >> n >> m;

  if(n >= m) {
    cout << "xiao lan\n";
    return 0;
  }

  vector<int> a(n);

  for(int &x: a) {
    cin >> x;
    x %= m;
  }

  vector<int> f(m + 1);
  f[0] = 1;
  for(int i = 0; i < n; i ++ ) {
    auto g = f;
    for(int j = 0; j <= m; j ++ ) if(g[j]) {
      if((j + a[i]) % m == 0) {
        cout << "xiao lan\n";
        return 0;
      } 
      f[(j + a[i]) % m] = 1;
    }
  }

  cout << "xiao hong\n";
  



  return 0;
}