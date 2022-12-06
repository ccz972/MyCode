#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
/*
0,1,1,1,1,1,1,1,0

0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0


0 1 2 0 0 2 1 1 0 // !kw
0 1 2 0 0 1 2 1 0 //  k


[20,20,20,20,20,20,20]
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25

2 0 0 2 1 1 
1 1 2 0 0 2
2 0     1  1  

*/


void solve() {
  int n, m; cin >> n >> m;
  vector<vector<ll> > a(n, vector<ll>(m));
  int id = n - 1;
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < m; j ++ ) {
      cin >> a[i][j];
    }
  }

  vector<bool> f(n);
  auto b = a;
  for(int i = 1; i < n; i ++ ) {
    ll now = 0;
    int l = 0, r = m - 1;

    while(l < r) {
      while(l < r && a[0][l] == a[i][l]) ++ l;
      while(l < r && a[0][r] == a[i][r]) -- r;
      if(l == r) {
        if(a[0][l] != a[0][r]) {
          f[i] = true; 
        }
        break;
      }
      if(l + 1 == r - 1) {
        if( (a[0][l] - a[i][l]) + (a[0][l + 1] - a[i][l + 1]) != 0) {
          f[i] = true;
        } 
        if( (a[0][r] - a[i][r]) + (a[0][r - 1] - a[i][r - 1]) != 0) {
          f[i] = true;
        } 
        int cnt = (a[0][l] == a[i][l]) + (a[0][l + 1] == a[i][l + 1]);
        cnt += (a[0][r] == a[i][r]) + (a[0][r - 1] == a[i][r - 1]);
        if(cnt != 0 || cnt != 4) {
          f[i] = true;
        }
        break;
      } else if(l + 1 > r - 1) {
        f[i] = true;
        break;
      }
      a[i][l + 1] += (a[i][l] - a[0][l]);
      a[i][r - 1] += (a[i][r] - a[0][r]);
      l ++, r -- ;
    }
    // while(l < r) {
    //   ll left = a[0][l] - a[i][l], right = a[0][r] - a[i][r];
    //   while(left == 0) {
        
    //   }
    // }
  }
  for(int i = 1; i < n; i ++ ) {
    cout << f[i] << " \n"[i == n - 1];
  }
  // for(int i = 0; i < n - 1; i ++ ) {    
  //   if(a[i].back() < a[id].back()) {
  //     id = i;
  //   }
  // }

  // for(int i = 0; i < n; i ++ ) if(i != id) {
  //   for(int j = 0; j < m; j ++ ) {

  //   }
  // }

  //i = 0;

  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}