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

const int N = 2e5 + 10;

int a[N], id[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) {
    a[i] = i, id[i] = i;
  }
  int now = n;
  while(m -- ) {
    int x; cin >> x;
    a[id[x]] = 0;
    id[x] = ++ n;
    a[id[x]] = x;    
  }
  vector<int> ans;
  for(int i = 1; ; i ++ ) {
    if(a[i]) {
      ans.push_back(a[i]);
    }
    if(ans.size() == 5) break;
  }
  sort(ans.begin(), ans.end());
  for(int x: ans) cout << x << " ";



  return 0;
}