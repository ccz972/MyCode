/***************************************************

@File    : C.cpp
@Time    : 2022/07/26 08:15:00
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
  sort(a.begin(), a.end());
  if(n == 1) {
    cout << a[0] << "\n";
    return 0;
  }
  if(a.back() == 2) {
    if(a[0] == 1) {
      cout << "2 1 ";
      for(int i = n - 2; i > 0; i -- ) {
        cout << a[i] << " ";
      }
      cout << "\n";
    } else {
      for(int& x: a) cout << x << " ";
      cout << "\n";
    }
  } else {
    for(int& x: a) cout << x << " ";
    cout << "\n";
  }


  return 0;
}