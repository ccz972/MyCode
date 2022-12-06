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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q, x; cin >> n >> q >> x;
  vector<ll> w(n * 2 + 1);
  for (int i = 1; i <= n; i ++ ) {
    cin >> w[i]; w[i + n] = w[i];
  }
  for (int i = 1; i <= 2 * n; i ++ ) {
    w[i] += w[i - 1];
  }
  ll base = 0;
  if(x > w[n]) {
    base = x / w[n] * n;
    x %= w[n];
  }
  vector<int> mp(n, -1);
  vector<ll> f;
  int i = 0, cc = 0, t1, t2;
  while (true) {
    int j = lower_bound(w.begin(), w.end(), x + w[i]) - w.begin();
    if (mp[i] >= 0) {
      t1 = mp[i]; 
      t2 = f.size() - t1;
      break;
    } else { 
      mp[i] = cc ++;     
      f.emplace_back(j - i + base);
    }
    i = j % n;
  }
  while (q -- ) {
    ll k; cin >> k;
    if (k > t1) { 
      cout << f[t1 + (k - t1 - 1) % t2] << "\n";
    } else {
      cout << f[k - 1] << "\n";
    }
  }
  return 0;
}