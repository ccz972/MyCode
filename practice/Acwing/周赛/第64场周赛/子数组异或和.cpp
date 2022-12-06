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

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), s1(n + 1), s2(n + 2);
  vector<int> cnt1(1 << 21), cnt2(1 << 21);
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    s1[i] = s1[i - 1] ^ a[i];
    cnt1[s1[i]] ++;
  }



  for(int i = n; i >= 1; i -- ) {
    s2[i] = s2[i + 1] ^ a[i];
    cnt2[s2[i]] ++;
  }

  



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}