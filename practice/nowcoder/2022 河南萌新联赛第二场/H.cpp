/***************************************************

@File    : H.cpp
@Time    : 2022/07/17 15:33:11
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
  string s; cin >> s;
  auto t = s;
  for(char &c: t) c = (c == '1' ? '0' : '1');
  int n = s.size();
  //s -> 0000000
  for(int i = 0; i < n; i ++ ) if(s[i] == '1') {
    
  }


  return 0;
}