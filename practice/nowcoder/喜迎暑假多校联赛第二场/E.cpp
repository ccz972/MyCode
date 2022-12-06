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

void solve() {
  int n; scanf("%d", &n);
  int m = 60 * 60 * 24;
  vector<int> s(m + 100);
  for(int i = 0; i < n; i ++ ) {
    int hh1, mm1, ss1, hh2, mm2, ss2; scanf("%d:%d:%d - %d:%d:%d", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
    int st = hh1 * 60 * 60 + mm1 * 60 + ss1;
    int ed = hh2 * 60 * 60 + mm2 * 60 + ss2;
    s[st] ++, s[ed + 1] --;
  }
  int mx = s[0];

  for(int i = 1; i < m + 100; i ++ ) {
    s[i] += s[i - 1];
    chkmax(mx, s[i]);
  }
  
  printf("%d\n", mx);
}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
