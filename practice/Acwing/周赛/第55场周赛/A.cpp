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
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for(int &x: a) cin >> x;
  map<int, int> mp;
  for(int &x: b) cin >> x, mp[x] ++;
  for(int i = 0; i < n; i ++ ) if(mp[a[i]]) {
    cout << a[i] << " ";
  }
}