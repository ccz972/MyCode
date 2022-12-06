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
  for (int i = 0; i < n; i ++ ) {
    cin >> w[i]; w[i + n] = w[i];
  }
  for(int i = n * 2 - 1; i -- ; ) {
    w[i] += w[i + 1];
  }

  ll r = x % w[n];

  vector<ll> sz(n), jump(n);

  for (int i = n, j = n * 2; i -- ; ) {
    while(i < j && w[i] - w[j - 1] >= r) {
      -- j;
    }
    sz[i] = (x / w[n]) * n + j - i;
    jump[i] = j % n;
  }

  vector<ll> t(n, -1), seq;

  ll offset, cycle;

  for(int i = 0; ; i = jump[i]) {
    if(~t[i]) {
      offset = t[i];
      cycle = seq.size() - offset;
      break;
    }
    t[i] = seq.size();
    seq.emplace_back(sz[i]);
  }
  // cout << 
  // cout << seq[0] << "\n";
  while(q -- ) {
    ll k; cin >> k; 
    -- k;
    cout << seq[k < offset ? k : offset + (k - offset) % cycle] << "\n";
  }


  return 0;
}