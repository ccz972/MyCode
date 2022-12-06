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
  vector<int> a(n + 1);
  // ll sum = 0;
  // for(int &x: a) cin >> x, sum += x;
  
  rep(i, 1, n) cin >> a[i];
  if(n & 1) {
    cout << "Mike\n";
    return ;
  }
  array<int, 2> mi = {2, 1};
  rep(i, 1, n) {
    if(a[i] < a[mi[i % 2]]) {
      mi[i % 2] = i;
    }
  }
  if(a[mi[1]] < a[mi[0]]) {
    cout << "Joe\n";
  } else if(a[mi[0]] < a[mi[1]]) {
    cout << "Mike\n";
  } else {
    if(mi[1] < mi[0]) cout << "Joe\n";
    else cout << "Mike\n";
  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}