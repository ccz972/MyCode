// https://www.luogu.com.cn/problem/P5410

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

constexpr int N = 2E7 + 10;

int n, m;
char s[N], p[N];
int z[N], ext[N];
// LCP 是最长公共前缀
// z[i]    表示 模板串 p[i, strlen(p) - 1] 与 p 的 LCP
// ext[i]  表示 匹配串 s[i, strlen(s) - 1] 与 p 的 LCP

void getZ() {
  z[0] = m; int now = 0; 
  while (now + 1 < m && p[now] == p[now + 1]) now ++;
  z[1] = now;
  for (int i = 2, j = 1; i < m; i ++ ) {
    if (i + z[i - j] < j + z[j]) {
      z[i] = z[i - j];
    } else {
      now = max(j + z[j] - i, 0);
      while (now + i < m && p[now] == p[now + i]) ++ now;
      z[i] = now;
      j = i;
    }
  }
}

void getexkmp() {
  int now = 0;
  while (now < m && now < n && p[now] == s[now]) ++ now;
  ext[0] = now;
  for (int i = 1, j = 0; i < n; i ++ ) {
    if (i + z[i - j] < j + ext[j]) {
      ext[i] = z[i - j];
    } else {
      now = max(j + ext[j] - i, 0); // pretect i too large
      while (now < m && now + i < n && p[now] == s[now + i]) ++ now;
      ext[i] = now;
      j = i;
    }
  }
}



void solve() {
  scanf("%s%s", s, p);
  n = strlen(s), m = strlen(p);
  getZ(); getexkmp();
  long long ans0 = 0, ans1 = 0;
  for (int i = 0; i < m; i ++ ) {
    ans0 ^= 1ll * (i + 1) * (z[i] + 1);
  }
  for (int i = 0; i < n; i ++ ) {
    ans1 ^= 1ll * (i + 1) * (ext[i] + 1);
  }
  printf("%lld\n%lld\n", ans0, ans1);
}
int main() {
  // freopen("1.in", "r", stdin);
  solve();
  return 0;
}

