#include <bits/stdc++.h>
using namespace std;

template < typename T > inline void chkmax(T &x, T y) {x = x >= y ? x : y;}
template < typename T > inline void chkmin(T &x, T y) {x = x <= y ? x : y;}

constexpr int N = 1E5 + 10;

int a[N], id[N], ans[N], now[N];
int l[N], r[N];

void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  deque<int> dq;
  for (int i = 1; i <= n; i ++ ) {
    scanf("%d", a + i); 
    ans[i] = now[i] = 0; id[a[i]] = i; 
    l[i] = 2E9; r[i] = 0;
    dq.push_back(a[i]);
  }
  int cnt = 0;
  while (dq.front() != n) {
    auto t1 = dq.front(); dq.pop_front();
    auto t2 = dq.front(); dq.pop_front();
    ans[max(t1, t2)] ++; 
    ++ cnt; 
    chkmin(l[id[max(t1, t2)]], cnt);
    chkmax(r[id[max(t1, t2)]], cnt);
    now[cnt] = now[cnt - 1] + ans[n];
    dq.push_back(min(t1, t2));
    dq.push_front(max(t1, t2));
  }
  while (q -- ) {
    int x, k; scanf("%d%d", &x, &k);
    if (a[x] == n) {
      printf("%d\n", (x <= 2 ? k : max(0, k - (x - 2))));
    } else {
      printf("%d\n", (k < l[x] ? 0 : min(r[x], k) - l[x] + 1));
    }
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T -- ) solve();
  return 0;
}