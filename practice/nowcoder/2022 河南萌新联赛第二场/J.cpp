/***************************************************

@File    : D.cpp
@Time    : 2022/07/17 13:01:30
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
int ans;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  // map<int, int> mp1, mp2;
  vector<int> x, y;
  for(int i = 0; i < n; i ++ ) {
    for(int j = i; j < n; j ++ ) {
      x.push_back(a[i] + a[j]);
      y.push_back(a[i] - a[j]);
      y.push_back(a[j] - a[i]);
      // mp1[a[i] + a[j]] ++;
      // mp2[a[i] - a[j]] ++;
      // mp2[a[j] - a[i]] ++;
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  n = x.size(), m = y.size();
  for(int i = 0, j = 0; i < n && j < m ; ) {
    if(x[i] == y[j]) {
      cout << "Yes\n";
      return 0;
    } else if(x[i] < y[j]) {
      ++ i;
    } else {
      ++ j;
    }
  }
  cout << "No\n";
  return 0;
}