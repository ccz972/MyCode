/***************************************************

@File    : B.cpp
@Time    : 2022/07/08 22:39:27
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

constexpr int N = 2e5 + 10;

int a[N];
bool st[N];
void solve() {
  int n; cin >> n;
  cout << "2\n";
  for(int i = 1; i <= n; i ++ ) if(!st[i]) {
    for(int j = i ; j <= n && !st[j]; j *= 2) {
      cout << j << " ";
      st[j] = true;
    }
  }
  cout << "\n";

  for(int i = 1; i <= n; i ++ ) st[i] = false;
  //1 2 
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