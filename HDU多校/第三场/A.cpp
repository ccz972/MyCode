#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;

struct seg {
  int l, r; 
  bool operator < (const seg &T) const {
    if(r != T.r) return r < T.r;
    return l > T.l;
  }
} a[N];
int n, k; 
void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i].l >> a[i].r;
  }  
  sort(a + 1, a + 1 + n);
  priority_queue<int> q;
  // q.push(1); q.push(2); cout << q.top();
  int ans = 1, now = k - 1;
  int r = a[1].r;
  int i = 2;
  while(true) {
    while(i <= n && a[i].l > r) {
      q.push(a[i].l);
      ++ i;
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
