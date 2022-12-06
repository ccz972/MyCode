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

  solve();
  return 0;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  string s; cin >> s;
  vector<ll> f(4, 0);
  for(int i = 0; i < n; i ++ ) {
    if(s[i] == 'R') {
      //0 1
      if(a[i] & 1) {
        chkmax(f[3], f[0] + a[i]);
      } else {
        chkmax(f[2], f[1] + a[i]);
      }
    } else {
      //2 3
      if(a[i] & 1) {
        chkmax(f[1], f[2] + a[i]);
      } else {
        chkmax(f[0], f[3] + a[i]);
      }
    }
  }
  cout << *max_element(f.begin(), f.end());
}