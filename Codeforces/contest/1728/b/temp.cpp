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

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  auto b = a;
  int mx = 0;
  do {
    int now = 0;
    for (int i = 0; i < n; i ++ ) {
      if (now < a[i]) now += a[i];
      else now = 0;
    }
    
    if (now > mx) {
      b = a;
      mx = now;
    }
    if (now > 21) {
      break;
    }
  } while (next_permutation(a.begin(), a.end())) ;
  cout << mx << "\n";
  for (int x: b) cout << x << " ";
  cout << "\n";
  int now = 0;
  for (int i = 0; i < n; i ++ ) {
    if (now < b[i]) now += b[i];
    else now = 0;
    cout << now << " ";
  }

  cout << "\n\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
