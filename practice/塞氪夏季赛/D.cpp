#include <bits/stdc++.h>

using namespace std; 

const int INF=0x3f3f3f3f; 
const int N=10000; 
 
int ans = 0x3f3f3f3f;
int n, pp, cnt, t, w;


template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }


struct node {
  int x, y, l;
}p[N << 1];
int mx, mi;
bool isok( int i, int j ) { 
    if(t * t == w && t <= pp && p[i].l + p[j].l + t == n) 
        if( p[i].x*p[j].y-p[i].y*p[j].x ) return 1; 
    return 0; 
} 

int sqr(int x) {
  int l = 0, r = 10000;
  while(l < r) {
    int mid = (l + r) / 2;
    if(mid * mid < x) l = mid + 1;
    else r = mid;
  }
  return l;
}


int dis( node a, node b ) { 
  w = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); 
  return sqr(w); 
} 

void init() {
  int res = n / 2;
  pp = res;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 0; i * i + j * j <= pp * pp; j ++ ) {
      int res = i * i + j * j;
      int t = sqr(res);
      if(t * t == res) {
        p[++ cnt].l = t;
        p[cnt].x = i;
        p[cnt].y = j;
      }
    }
  }
}


  
int main() {
    cin >> n;
    if(n & 1 || n < 4 ) { 
      cout << "-1\n"; 
      return 0; 
    } 
    init();
    for( int i = 1; i <= cnt; i++ ) {
        for( int j = i + 1; j <= cnt && p[i].l + p[j].l < n; j ++ ) { 
        t = dis(p[i], p[j]);
        if(isok(i, j)) {
          mx = max( t, max( p[i].l, p[j].l ) ); 
          mi = min( t, min( p[i].l, p[j].l ) ); 
          ans = min( ans, mx - mi ); 
        }
      }
    }
    if(ans > 1000000) {
      if(n % 4 == 0) {
        ans = 0;
      } else {
        ans = 1;
      }
    }

  cout << ans << "\n"; 
  return 0; 
}