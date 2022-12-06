#include <bits/stdc++.h>
#include <debugger>

using namespace std;

#define rep(i, a, b) for(int i(a); i <= b; ++ i)
#define ll long long

int n, m;



bool chk(array<int, 4> a, array<int, 4> b) {
  
  if(a[0] >= b[0] && a[0] <= b[2] && a[1] >= b[1] && a[1] <= b[3]) {
    return true;
  }

  if(a[0] >= b[0] && a[0] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
    return true;
  }  

  if(a[2] >= b[0] && a[2] <= b[2] && a[1] >= b[1] && a[1] <= b[3]) {
    return true;
  }  

  // if(a[1] >= b[0] && a[1] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
  //   return true;
  // }  

  if(a[2] >= b[0] && a[2] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
    return true;
  }  
  swap(a, b);
  if(a[0] >= b[0] && a[0] <= b[2] && a[1] >= b[1] && a[1] <= b[3]) {
    return true;
  }

  if(a[0] >= b[0] && a[0] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
    return true;
  }  

  if(a[2] >= b[0] && a[2] <= b[2] && a[1] >= b[1] && a[1] <= b[3]) {
    return true;
  }  

  // if(a[1] >= b[0] && a[1] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
  //   return true;
  // }  

  if(a[2] >= b[0] && a[2] <= b[2] && a[3] >= b[1] && a[3] <= b[3]) {
    return true;
  }  
  return false;

}


ll got() {
  ll ans = 0;

  rep(ltx1, 0, n) {
    rep(lty1, 0, m) {
      rep(rbx1, ltx1 + 1, n) {
        rep(rby1, lty1 + 1, m) {
          rep(ltx2, 0, n) {
            rep(lty2, 0, m) {
              rep(rbx2, ltx2 + 1, n) {
                rep(rby2, lty2 + 1, m) {
                  array<int, 4> x, y;
                  x = {ltx1, lty1, rbx1, rby1};
                  y = {ltx2, lty2, rbx2, rby2};
                  if(!chk({ltx1, lty1, rbx1, rby1}, {ltx2, lty2, rbx2, rby2})) {
                    ans ++;
                    if(n == 1 && m == 4) {
                      debug(x);
                      debug(y);
                    }
                  }
                }
              }
            }
          }
        }
      } 
    }
  }

  return ans / 2;

} 

void solve() {
  
  for(int i = 1; i < 10; i ++ ) {
    for(int j = 1; j < 10; j ++ ) {
      n = i, m = j;
      cout << "> " << n << " " << m << " : ";
      cout << got() << "\n";
    }
  }

}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  freopen("out.txt", "w", stdout);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}