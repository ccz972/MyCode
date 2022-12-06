#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  cout << "1\n";
  int n = 6;
  cout << n << "\n";
  for(int i = 0; i < n; i ++ ) {
    int now = rng() % 3;
    cout << now << " ";
  }
  cout << "\n";



}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
