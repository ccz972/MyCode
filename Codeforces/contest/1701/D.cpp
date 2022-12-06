/***************************************************

@File    : D.cpp
@Time    : 2022/07/08 23:08:20
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

constexpr int N = 5e5 + 10;

int a[N], b[N];
int l[N], r[N];

struct node {
  int l, r, id; 
  bool operator < (const node &T) const {
    // if(l != T.l) return l < T.l;
    // return r < T.r;
    if(r != T.r) return r < T.r;
    return l < T.l;
  }
};

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> b[i];

  vector<node> p;
 
  for(int i = 1; i <= n; i ++ ) {
    if(b[i] == 0) {
      l[i] = i + 1, r[i] = n;
    } else {
      l[i] = max(1, i / (b[i] + 1) + 1);
      r[i] = min(i / b[i], n);
      // r[i] = max(l[i], i / b[i]);
      chkmin(l[i], r[i]);
    }
    // debug(l[i], r[i], i);
    p.push_back({l[i], r[i], i});
  }

  sort(p.begin(), p.end());
  // int L = 1, R = p[0].r;
  // int now = 1;
  // int idx = 0;
  // while(true) {
    
  //   while(idx < n - 1 && p[idx + 1].r == R) {
  //     if(now )
  //   }
  // }

  // cout << "------------- \n";
  // for(auto [l, r, id]: p) {
  //   cout << l << " " << r << " " << id << "\n";
  // }
  // cout << "------------- \n";
  for(int i = 0; i < n; i ++ ) {
    a[p[i].id] = i + 1;
  }
  for(int i = 1; i <= n; i ++ ) {
    cout << a[i] << " \n"[i == n];
  }

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