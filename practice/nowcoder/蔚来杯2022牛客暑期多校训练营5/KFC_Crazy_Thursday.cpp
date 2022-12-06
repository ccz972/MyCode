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

constexpr int N = 2E6 + 10;

int n, m, Case;
char s[N], str[N];
int p[N];
ll ans[N];
//p[i]表示以i为中间点的回文串个数
void manacher() {
  int rt = 0, mid = 0;
  int res = 0;
  for(int i = 1; i <= m; i ++ ) {
    p[i] = i < rt ? min(p[2 * mid - i], rt - i) : 1;
    while(str[i + p[i]] == str[i - p[i]]) ++ p[i];
    if(i + p[i] > rt) {
      rt = i + p[i];
      mid = i;
    }
    ans[i] ++;
    ans[i + p[i]] --;
    // printf("%d %d\n", i - p[i] + 1, i + p[i]);
    //res = max(res, p[i] - 1);
  }
  // printf("%s\n", str + 1);
  // for(int i = 1; i <= m; i ++ ) {
  //   printf("%d%c", ans[i], " \n"[i == m]);
  // }
  ll ans1 = 0, ans2 = 0, ans3 = 0;
  for(int i = 1; i <= m; i ++ ) {
    ans[i] += ans[i - 1];
    if(str[i] == 'k') ans1 += ans[i];
    if(str[i] == 'f') ans2 += ans[i];
    if(str[i] == 'c') ans3 += ans[i];
  }
  printf("%lld %lld %lld\n", ans1, ans2, ans3);
}
void solve() {
  int n; scanf("%d", &n);
  str[0] = '!', str[1] = '#';
  scanf("%s", s);
  for(int i = 0; i < n; i ++ ) {
    str[i * 2 + 2] = s[i];
    str[i * 2 + 3] = '#'; 
  } 
  m = n * 2 + 1;
  str[m + 1] = '@';
  str[m + 2] = '\0';
  manacher();
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}