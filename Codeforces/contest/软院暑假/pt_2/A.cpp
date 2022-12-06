/***************************************************

@File    : A.cpp
@Time    : 2022/07/08 21:39:30
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
  vector<int> a(3);
  for(int i = 0; i < 3; i ++ ) cin >> a[i];
  int ans1 = a[0] * a[1] * a[2];
  chkmax(ans1, a[0] + a[1] + a[2]);
  chkmax(ans1, (a[0] + a[1]) * a[2]);
  chkmax(ans1, a[0] * (a[1] + a[2]));
  cout << ans1 << "\n";
  

  return 0;
}