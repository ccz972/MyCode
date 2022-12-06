#include <bits/stdc++.h>
using namespace std;

template < typename T > inline void chkmax(T &x, T y) {x = x >= y ? x : y;}
template < typename T > inline void chkmin(T &x, T y) {x = x <= y ? x : y;}

constexpr int N = 1E5 + 10;

int n, a[N], b[N];
int f[N];

void solve() {
  
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++ ) {
    scanf("%d", a + i);
    b[i] = b[i - 1] ^ a[i];
  }
  map<int, int> mp;
  mp[0] = 0;
  for (int i = 1; i <= n; i ++ ) {
    f[i] = f[i - 1] + (a[i] != 0);
    if (mp.count(b[i])) {
      chkmin(f[i], f[mp[b[i]]] + i - mp[b[i]] - 1);
    }
    mp[b[i]] = i;
  }
  printf("%d\n", f[n]);
}

int main() {
  int T; scanf("%d", &T);
  while (T -- ) solve();
  return 0;
}