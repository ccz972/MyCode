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
  vector<int> a(n + m);
  for(int &x: a) cin >> x;
  vector<bool> vis(n + m);
  for(int i = 0; i < n + m; i ++ ) {
    int x; cin >> x;
    if(x) vis[i] = true;
  }
  vector<int> l(n + m, 1e9), r(n + m, 1e9);
  int left = -1;
  for(int i = 0; i < n + m; i ++ ) {
    if(vis[i]) {
      left = i;
    } else {
      if(left >= 0) l[i] = a[i] - a[left];
    }
  }

  int right = -1;
  for(int i = n + m -  1; i >= 0; i -- ) {
    if(vis[i]) {
      right = i;
    } else {
      if(right >= 0) r[i] = a[right] - a[i];
    }
  }
  vector<int> ans(n);
  for(int i = 0, cnt = -1; i < n + m; i ++ ) {
    if(vis[i]) {
      cnt ++;
      continue;
    }
    if(cnt == -1) continue;
    if(l[i] <= r[i]) {
      ans[cnt] ++;
    }
  }

  for(int i = n + m - 1, cnt = -1; i >= 0; i -- ) {
    if(vis[i]) {
      cnt ++;
      continue;
    }
    if(cnt == -1) continue;
    if(r[i] < l[i]) {
      ans[m - cnt - 1] ++;
    }
  }
  for(int x: ans) {
    cout << x << " ";
  }

}