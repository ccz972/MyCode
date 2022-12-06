#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 4E5 + 10;

int n, a[N];

//两种统计方式
ll calc1(int L, int R, ll ret = 0) {
  if (L > R) return 0;

  for (int i = 1, j = n; i < j; i ++ ) {
    while (i < j && a[i] + a[j] >= L) -- j;
    if (i < j) ret += j - i;
  }

  for (int i = n, j = 1; i > j; i -- ) {
    while (i > j && a[i] + a[j] <= R) ++ j;
    if(i > j) ret += i - j;
  }

  ll all = 1ll * n * (n - 1) / 2;
  return (all - ret) & 1;
 
}

bool calc2(int L, int R, ll ret = 0) {
  if (L > R) return 0;
  for (int i = n, l = 1, r = 1; i; i -- ) {
    while (l <= n && a[i] + a[l] < L) ++ l; // >=L
    while (r <= n && a[i] + a[r] <= R) ++ r;
    ret += r - l - (l <= i && i < r);
  }
  return ret >> 1 & 1;
}


void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  int ans = 0;
  for (int j = 26; j >= 0; j -- ) { //从大到小枚举，不用另开一个数组
    for (int i = 1; i <= n; i ++ ) {
      a[i] &= ((1 << j + 1) - 1);
    }
    sort(a + 1, a + 1 + n);
    auto now1 = calc2(1 << j, (1 << (j + 1)) - 1);
    auto now2 = calc2(3 << j, (1 << (j + 2)) - 2);
    if(now1 ^ now2) ans |= 1 << j;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}