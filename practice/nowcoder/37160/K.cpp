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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  vector<int> mx(n);
  mx.back() = a.back();
  for(int i = n - 2; i >= 0; i -- ) {
    mx[i] = a[i];
    chkmax(mx[i], mx[i + 1]);
  }
  int ans = 0;
  for(int i = 0; i < n - 1; i ++ ) {
    if(a[i] < mx[i + 1]) {
      ans ++;
    }
  } 
  cout << ans << "\n";

  return 0;
}