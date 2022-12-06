/***************************************************

@File    : A.cpp
@Time    : 2022/07/08 22:34:49
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
int a[2][2];
void solve() {
  int cnt = 0;
  for(int i = 0; i < 2; i ++ ) {
    for(int j = 0; j < 2; j ++ ) {
      cin >> a[i][j];
      cnt += a[i][j];
    }
  }
  if(cnt == 2 || cnt == 3) cnt = 1;
  else if(cnt == 4) cnt = 2;
  cout << cnt << "\n";



}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();    
  }
  return 0;
}