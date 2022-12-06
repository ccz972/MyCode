#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100000 + 41;

int a[N], stk[N];
int tt;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  tt = 0;
  // memset(stk, 0, sizeof stk);
  int ans = -1e9 - 10;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(stk + 1, stk + 1 + tt, a[i]) - stk;
    ans = max(ans, p);
    stk[p] = a[i];
    tt = max(tt, p);
  }

  printf("%d\n", ans);
}