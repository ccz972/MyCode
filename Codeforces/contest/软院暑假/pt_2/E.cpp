/***************************************************

@File    : E.cpp
@Time    : 2022/07/08 22:11:24
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
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int q; cin >> q;
  // vector<array<int, 2> > p;
  struct node { int op, x, y; };
  vector<node> p;
  int mx = -1;
  for(int i = 0; i < q; i ++ )  {
    int op, x, y = -1; cin >> op >> x;
    if(op == 2) {
      chkmax()
    }
    // if(op & 1) {
    //   cin >> y;
    //   a[x] = y;
    // } else {
    //   chkmax(mx, x);
    // }
  }
  // for(int i = 0; i < n; i )
  for(int &x: a) chkmax(x, mx);
  for(int x: a) cout << x << " ";

  return 0;
}