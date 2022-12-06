#include <bits/stdc++.h>
// #include <debugger>
using namespace std;

const int N = 1e5 + 10;

int a[4] = {2, 3, 17, 19};
int b[4] = {5, 7, 11, 13};

int f[N], g[N];

int get1(int x) {
  if(x < N) return f[x];
  // for(int i = 0; i < )
  if(x % 19 == 0) return x / 19;

  int ans = x;
  int p = x % 19;
  for(int i = 0; i < 100 && p + i * 19 <= x; i ++ ) {
    ans = min(ans, x / 19 - i + f[p + i * 19]);
  }
  p = x % 17;
  for(int i = 0; i < 100 && p + i * 17 <= x; i ++ ) {
    ans = min(ans, x / 17 - i + f[p + i * 17]);
  }
  return ans;
}

int get2(int x) {
  if(x < N) return g[x];
  int ans = x;
  int p = x % 13;
  for(int i = 0; i < 100 && p + i * 13 <= x; i ++ ) {
    ans = min(ans, x / 13 - i + f[p + i * 13]);
  }
  p = x % 11;
  for(int i = 0; i < 100 && p + i * 11 <= x; i ++ ) {
    ans = min(ans, x / 11 - i + f[p + i * 11]);
  }
  p = x % 5;
  for(int i = 0; i < 100 && p + i * 5 <= x; i ++ ) {
    ans = min(ans, x / 5 - i + f[p + i * 5]);
  }
  p = x % 7;
  for(int i = 0; i < 100 && p + i * 7 <= x; i ++ ) {
    ans = min(ans, x / 7 - i + f[p + i * 7]);
  }
  return ans;
}

void solve() {
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for(int i = 0; i < 4; i ++ ) {
    int now = a[i];
    for(int j = now; j < N; j ++ ) {
      f[j] = min(f[j], f[j - now] + 1);
    }
  }  

  memset(g, 0x3f, sizeof g);
  g[0] = 0;
  for(int i = 0; i < 4; i ++ ) {
    int now = b[i];
    for(int j = now; j < N; j ++ ) {
      g[j] = min(g[j], g[j - now] + 1);
    }
  }
  // for(int i = 1; i < N; i ++ ) if(!(i % 5 == 0 || i % 7 == 0 || i % 11 == 0 || i % 13 == 0)) {
  //   cout << i << "\n";
  // }
  // for(int i = 100; i < N; i ++ ) {
  //   // cout << i << ": " << f[i] << " " << g[i] << "\n";
  //   // printf("%2d : %3d\n", i,  g[i]);
  //   int now = g[i];
  //   if(now % 13 == 0 ) continue;
  //   if(now != g[i - 13] + 1 && now != g[i - 11] + 1 && now != g[i - 7] + 1 && now != g[i - 5] + 1) {
  //     cout << i << "\n";
  //   }
  //   // cout << f[i] << "\n";
  // }
  // cout << "\n";
  // for(int i = 0; i <= 100; i ++ ) {
  //   cout << g[i] << " ";
  // }
  // cout << "\n";
  int q; scanf("%d", &q);
  while(q -- ) {
    int x; scanf("%d", &x);
    if(x == 1) {
      cout << "-1\n";
      continue;
    }
    int l = get1(x);
    int r = get2(x);
    if(l == r) {
      cout << "both\n";
    } else if(l < r) {
      cout << "A\n";
    } else {
      cout << "B\n";
    }
  }
  
}

int main() {
  // freopen("data.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  solve();
  return 0;
}