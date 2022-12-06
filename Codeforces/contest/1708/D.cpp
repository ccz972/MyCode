/***************************************************

@File    : D.cpp
@Time    : 2022/07/16 23:30:53
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

int a[N], b[N];
int tmp[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int m = n, q = n;
    while(q -- ) {
      int l = 1, r = 1;
      while(l < m) {
        b[r] = a[l + 1] - a[l];
        if(b[r]) r ++;
        l ++;
      }
      if(l == r) {
        if(l == q + 1) {
          -- m;
        } else if(l < q + 1) {
          b[l] = 0;
        } 
      } else if(r < l) {
        b[r] = 0;
        m = r;
      }

      sort(b + 1, b + 1 + m);
      for(int i = 1; i <= m; i ++ ) {
        a[i] = b[i];
        // cout << a[i] << " \n"[i == m];
      }

      if(m == 1) {
        cout  << a[1] << "\n";
        break;
      }
    }
       
  }
  return 0;
}