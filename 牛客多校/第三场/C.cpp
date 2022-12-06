/***************************************************

@File    : C.cpp
@Time    : 2022/07/25 12:05:44
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
  vector<string> s(n);
  for(auto &x: s) cin >> x;
  sort(s.begin(), s.end(), [&](string &x, string &y) {
    return x + y < y + x;
  });
  for(auto &x : s) cout << x;

  return 0;
}