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

constexpr int N = 2E5 + 100;
constexpr int INF = 1E9;

int n;
int a[N], b[N];

void solve() {
  cin >> n;
  map<int, int> mp;
  for(int i = 1; i <= n; i ++ ) cin >> a[i]; // mp[a[i]] ++;
  
  for(int i = 1; i <= n; i ++ ) cin >> b[i]; 
  // sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
  // reverse(a + 1, a + 1 + n); reverse(b + 1, b + 1 + n); 
  for(int i = 1; i <= n; i ++ ) {
    while((~a[i] & 1) && a[i] != 1) {
      a[i] >>= 1;
    }
    mp[a[i]] ++;
  }

  for(int i = 1; i <= n; i ++ )  {
    while(b[i] && !mp[b[i]]) {
      b[i] /= 2;
    }
    if(!b[i]) {
      cout << "NO\n";
      return;
    } else {
      mp[b[i]] --;
    }
  }
  cout << "YES\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}