#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

const int N = 2010;
bool f[N];

ll a[1000];

void solve() {
  ll h; cin >> h;
  ll res = h;
  ll sum = 0;
  for (int i = 1; i <= 10; i ++ ) {
    cin >> a[i];
    sum += a[i] * i;
  }

  if (sum <= h) {
    cout << sum << "\n";
    return ;
  }

  
  for (int i = 10; i >= 1; i -- ) {
    if (h - a[i] * i >= 200) {
      h -= a[i] * i;
    } else {
      ll res = (h - 200) / i;
      a[i] -= res;
      h -= res * i;
    }
  }
  assert(h <= 1000ll);
  for (int i = 1; i <= 10; i ++ ) {
    a[i] = min(a[i], h / i + 1);
  }  
  f[0] = 1;
  for (int i = 10; i >= 1; i -- ) {
    for (int j = 1; j <= a[i]; j ++ ) {
      for (int k = h; k >= i; k -- ) {
        f[k] |= f[k - i];
      }
    }
  }

  for (int k = h; k >= 0; k -- ) if(f[k]) {
    cout << res - h + k << "\n";
    return ;
  }

  

  // int n, m; cin >> n >> m;
  // for(int i = 0; i < n; i ++ ) {
  //   int v, w, s;
  //   cin >> v >> w >> s;
  //   int k = 1;
  //   while(k <= s) {
  //     V[ct] = k * v;
  //     W[ct ++ ] = k * w;
  //     s -= k;
  //     k *= 2;
  //   }
  //   if(s) {
  //     V[ct] = s * v;
  //     W[ct ++ ] = s * w;
  //   }
  // }
  // for(int i = 0; i < ct; i ++ ) {
  //   int v = V[i], w = W[i];
  //   for(int j = m; j >= v; j -- ) {
  //     f[j] = max(f[j], f[j - v] + w);
  //   }
  // }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}