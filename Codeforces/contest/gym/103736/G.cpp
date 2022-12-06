#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

constexpr double pi = acos(-1);

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}

void solve() {
  int x; cin >> x ;
  cout << x;

}