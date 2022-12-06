#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;

int a[N], suf[N], ans[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  } suf[n + 1] = 1E9;
  for (int i = n; i >= 1; i -- ) {
    suf[i] = suf[i + 1];
    chkmin(suf[i], a[i]);
  }
  for (int i = n; i >= 1; i -- ) {
    int l = i + 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (suf[mid] < a[i]) l = mid;
      else r = mid - 1;
    }
    // cout << i << " " << l << " " << suf[l] << "\n";
    if (suf[l] >= a[i]) ans[i] = -1;
    else ans[i] = l - i - 1;
  }
  for (int i = 1; i <= n; i ++ ) {
    cout << ans[i] << " \n"[i == n];
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
