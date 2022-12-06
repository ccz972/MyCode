/***************************************************

@File    : G.cpp
@Time    : 2022/07/27 10:29:18
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

const int N = 1E5 + 10;
int n;
pair<int, int> a[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i ++ ) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  for(int i = 1; i < n; i ++ ) {
    if(a[i].first <= a[i - 1].second) {
      printf("%d\n", i - 1);
      return ;
    }
  }
  printf("%d\n", n);
}

int main() {
  int T; scanf("%d", &T);
  while(T -- ) solve();  

  return 0;
}
