// https://codeforces.com/contest/1144/submission/58659647
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;

int a[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];

  int A = -1, B = 1E9 + 1;

  for (int i = 1; i <= n; i ++ ) {
    if (a[i] < A && a[i] > B) {
      cout << "no\n";
      return ;
    }
    if (a[i] >= A && a[i] <= B) {
      if (i != n) {
        if (a[i] <= a[i + 1]) A = a[i];
        else B = a[i];
      } 
    } else if (a[i] >= A) {
      A = a[i];
    } else if (a[i] <= B) {
      B = a[i];
    }
    // cout << A << " " <<  B << "\n";
  }

  cout << "yes\n";
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}