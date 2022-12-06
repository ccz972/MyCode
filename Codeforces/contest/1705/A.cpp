/***************************************************

@File    : A.cpp
@Time    : 2022/07/15 21:35:10
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
  int T;
  cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    vector<int> a(n << 1);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    int l = INT_MIN, r = INT_MIN;
    bool f1 = true;
    for(int i = n; i < n << 1; i ++ ) {
      if(a[i] - a[i - n] < m) {
        f1 = false;
      }
    }
    if(f1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    //1  3 4

  }
  return 0;
}