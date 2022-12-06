#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int sh, sm, eh, em;
  scanf("%d:%02d %d:%02d", &sh, &sm, &eh, &em);

  int m = eh * 60 + em - (sh * 60 + sm);
  int n; scanf("%d", &n);

  vector<ll> f(m + 1);
  for(int i = 0; i < n; i ++ ) {
    int v, w, p; cin >> v >> w >> p;

    if(p == 0) {
      for(int j = v; j <= m; j ++ ) {
        f[j] = max(f[j], f[j - v] + w);
      }
    } else {
      int s = 1;
      while(s <= p) {
        for(int j = m; j >= v * s; j -- ) {
          f[j] = max(f[j], f[j - v * s] + w * s);
        }
        p -= s;
        s <<= 1;
      }

      if(p) {
        for(int j = m; j >= v * p; j -- ) {
          f[j] = max(f[j], f[j - v * p] + w * p);
        }
      }
    }
  }

  printf("%lld\n", f[m]);
  // cout << f[m] << "\n";
  return 0 ^ 0;
}