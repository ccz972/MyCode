/***************************************************

@File    : C.cpp
@Time    : 2022/07/16 22:49:31
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

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.ansize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

constexpr int N = 1E5 + 10;

int a[N], p[N];
int ans[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    auto solve = [&] () {
      int n, q; cin >> n >> q;
      for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans[i] = 0;
      }
      if(q >= n) {
        string s(n, '1');
        cout << s << "\n";
        return;
      }
      int now = 0;
      int i = n;
      
      for( now = 0; i >= 1; i -- ) {
        if(now >= q) break;
        if(now >= a[i]) ans[i] = 1;
        else ans[i] = 1, now ++;
      }

      for(; i >= 1; i -- ) {
        if(now >= a[i]) ans[i] = 1;
        else ans[i] = 0;
      }    
      
      for(int i = 1; i <= n; i ++ ) {
        cout << ans[i];
      }
      cout << "\n";
    };
    solve();
  }
  return 0;
}