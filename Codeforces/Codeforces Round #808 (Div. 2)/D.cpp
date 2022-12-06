/***************************************************

@File    : D.cpp
@Time    : 2022/07/26 14:56:01
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

  auto solve = [&] () {
    int n; cin >> n;
    vector<int> a; int cnt = 0 ;
    for(int i = 0; i < n; i ++ ) {
      int x; cin >> x;
      if(!x) ++ cnt;
      else a.emplace_back(x);
    }
    while(a.size() > 1) {
      vector<int> b;
      if(cnt) b.emplace_back(a[0]), -- cnt;
      for(int i = 1; i < a.size(); i ++ ) {
        if(a[i] - a[i - 1] != 0) b.emplace_back(a[i] - a[i - 1]);
        else ++ cnt;
      }       
      sort(b.begin(), b.end());
      a.swap(b);
    }    
    if(a.empty()) a.emplace_back(0);
    cout << a[0] << "\n";

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}