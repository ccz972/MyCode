
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
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    //a_1 is max
    auto b = a;
    int ans = 0;
    for(int i = 1; i < n - 1; i ++ ) {
      if(i == n - 2) {
        if(i & 1) {
          if(b[i] <= b[i + 1]) {
            ++ ans;
          }
        } else {
          if(b[i] >= b[i + 1]) {
            ++ ans;
          }
        }
        continue;
      }
      if(i & 1) {
        if(b[i] > b[i - 1]) {
          continue;
        } else {
          //5 MAX
          ++ ans;
          ++ i;
          //a_{i + 1} < a[i] 
        }
      } else {
        if(b[i] < b[i - 1]) {
          continue;
        } else {
          ++ ans;
          ++ i;
        }
      }
      //b_1 > b_0 
      //b_0, b_1, b_2, b 
    }
    b = a;
    int res = 0;
    for(int i = 1; i < n - 1; i ++ ) {
      if(i == n - 2) {
        if(~i & 1) {
          if(b[i] <= b[i + 1] || b[i] <= b[i - 1]) {
            ++ res;
          }
        } else {
          if(b[i] >= b[i + 1] || b[i] >= b[i - 1]) {
            ++ res;
          }
        }
        continue;
      }
      if(~i & 1) {
        if(b[i] > b[i - 1]) {
          continue;
        } else {
          //5 MAX
          ++ res;
          ++ i;
          //a_{i + 1} < a[i] 
        }
      } else {
        if(b[i] < b[i - 1]) {
          continue;
        } else {
          ++ res;
          ++ i;
        }
      }
      //b_1 > b_0 
      //b_0, b_1, b_2, b 
    }
    chkmin(ans, res);
    cout << ans << "\n";
    //a_1 is min
  }
  return 0;
}