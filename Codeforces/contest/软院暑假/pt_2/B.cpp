/***************************************************

@File    : B.cpp
@Time    : 2022/07/08 21:42:33
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
  int g = a[0];
  for(int i = 1; i < n;  i ++ ) g = __gcd(g, a[i]);
  for(int i = 0; i < n; i ++ ) if(a[i] == g) {
    cout << g;
    return 0;
  }
  cout << "-1";
  return 0;
}