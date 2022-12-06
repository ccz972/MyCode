#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

inline void out(bool flag) {
  cout << (flag ? "Yes" : "No" ) << "\n";
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &x: a) cin >> x;
  a.erase(unique(a.begin(), a.end()), a.end());
  int ans = 0;
  n = a.size();
  for (int i = 0; i < n; i ++ ) {
    int j = i + 1; 
    while(j < n - 1 && (a[j + 1] > a[j]) == (a[j] > a[j - 1])) ++ j;
    // cout << i << " " << j << "\n";
    i = j;
    ans ++;
    
  }
  cout << ans;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // freopen("in1.txt", "r", stdin);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}