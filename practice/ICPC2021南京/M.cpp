#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

constexpr int N = 1E6 + 10;

ll n, a[N];

void solve() {
  cin >> n;
  bool f1 = false, f2 = false;
  ll sum = 0;
  rep(i, 1, n) {
    cin >> a[i];
    if (a[i] > 0) f1 = true;
    else f2 = true;
    sum += abs(a[i]);
  }

  if (f1 && f2) {
    cout << sum << "\n";
  } else if (n == 1) {
    cout << a[1] << "\n";
  } else if (f1) {  
    ll mi = *min_element(a + 1, a + 1 + n);
    cout << sum - mi * 2 << "\n";
  } else if (f2) {
    ll mx = *max_element(a + 1, a + 1 + n);
    cout << sum - abs(mx) * 2 << "\n";
  } else {
    assert(false);
  }
    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- )
  solve();
  return 0;
}