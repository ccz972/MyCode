#include <bits/stdc++.h>
using namespace std;

constexpr int N = 252;

int a[N], s[N], f[N][N][N];
template < typename T > 
inline void chkmax(T &x, T y) {x = x >= y ? x : y;}
template < typename T > 
inline void chkmin(T &x, T y) {x = x <= y ? x : y;}

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  switch (k % 4) {
  case 0:
    puts("NO");
    break;
    
  case 1:
    puts("YES");
    for (int i = 1; i <= n; i += 2) printf("%d %d\n", i, i + 1);
    break;

  case 2:
    puts("YES");
    for (int i = 3; i <= n; i += 4) printf("%d %d\n", i, i + 1);
    for (int i = 1; i <= n; i += 4) printf("%d %d\n", i + 1, i);
    break;

  case 3:
    puts("YES");
    for (int i = 1; i <= n; i += 2) printf("%d %d\n", i, i + 1);
    break;
  
  default:
    break;
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T -- ) solve();
  return 0;
}