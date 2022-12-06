#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
int nxt[N];
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &y, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);

    if (a[i] < x || a[i] > y) a[i] = 0;
    // printf("%d%c", a[i], " \n"[i == n]);
  }
  int now = n + 1;
  for (int i = n; i >= 1; i--) {
    if (!a[i]) now = i;
    nxt[i] = now;
  }
  ll ans = 0;
  for (int i = 1, j = 0, cx = 0, cy = 0; i <= n; i++) {
    // printf("%d\n", i);

    if (!a[i]) {
      j = max(i, j);
      continue;
    }
    while (j < n && (!cx || !cy)) {
      ++j;
      if (a[j] == 0) {
        cx = 0, cy = 0;
        break;
      }

      cx += (a[j] == x);
      cy += (a[j] == y);
    }
    if (!cx || !cy) {
      i = j;
      continue;
    }
    // cout << i << " " << j << " " << nxt[j] << "\n";
    // i - j
    ans += nxt[j] - j;
    cx -= (a[i] == x);
    cy -= (a[i] == y);
    // return 0;
  }
  printf("%lld\n", ans);

  return 0;
}