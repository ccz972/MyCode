#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, a, b) for(int i(a); i <= b; ++ i)
#define dec(i, a, b) for(int i(a); i >= b; -- i)

constexpr int N = 2e6 + 10;

ll a[N];
int q[N];
ll f[N];

void solve() {
  int n, Q, p; cin >> n >> Q >> p;
  rep(i, 1, n) cin >> a[i];
  map<int, ll> ans;

  while(Q -- ) {
    int x; cin >> x;
    if(x > p) {
      cout << "Noob\n";
      continue;
    }

    if(ans.count(x)) {
      cout << ans[x] << "\n";
      continue;
    }

    int hh = 0, tt = 0; q[0] = 0;
    f[0] = 0;
    int last = 0;

    for(int i = 1; ; i ++ ) {
      int j = i * x;
      if(j > n) j = n + 1;
      while(hh <= tt && j - q[hh] > p) hh ++;
      f[j] = f[q[hh]] + a[j];
      // cout << q[hh] << " " << f[q[hh]] << " " << a[j] << " " << f[j] << "\n";
      while(hh <= tt && f[q[tt]] <= f[j]) tt --;
      q[++ tt] = j;
      last = j;
      if(j > n) break;
    }
    // cout << "\n";
    ans[x] = f[last];
    cout << f[last] << "\n";

  }
  

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}


/*
10 1 8
575463634 551586893 853578124 992917539 -802539119 378557972 -560384364 -724373775 -772653611 -309330159
5
*/