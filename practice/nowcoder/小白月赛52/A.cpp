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

void solve() {
  int n; cin >> n;
  int cnt1 = 0, cnt2 = 0;
  while(n -- ) {
    int a, b;
    scanf("%2d:%2d", &a, &b);
    if(a * 60 + b <= 8 * 60 + 5 && a * 60 + b > 8 * 60) {
      cnt1 ++;
    } else if(a * 60 + b > 8 * 60 + 5) {
      cnt2 ++;
    }
  }
  cout << cnt1 << " " << cnt2 << "\n";
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}