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
  int n, h, m, q; cin >> n >> h >> m >> q;
  map<ll, int> mp;
  for(int i = 0; i < n; i ++ ) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    ll l = (ll)a * m + b, r = (ll)c * m + d;
    mp[l] ++, mp[r + 1] --;
  }



  // vector<ll> query(q); 
  // for(int i = 0; i < q; i ++ ) {
  //   int x, y; cin >> x >> y;
  //   ll now = (ll)x * m + y;
  //   query[i] = now;
  // }

  ll now = 0;
  for(auto& [k, v]: mp) {
    now += v;
    v = now;
  }

  while(q -- ) {
    int x, y; cin >> x >> y;
    ll now = (ll)x * m + y;
    auto idx = mp.lower_bound(now);
    int val;
    if(idx->first == now) {
      val = idx->second;
    } else {
      if(idx == mp.begin()) val = 0;
      else val = prev(idx)->second;
    }
    // cout << val << " ";
    if(val > 0) cout << "No\n";
    else cout << "Yes\n";
  }

  // vector<int> id(q); 
  // iota(id.begin(), id.end(), 0);

  // sort(id.begin(), id.end(), [&](int x, int y) {
  //   return query[id[x]] < query[id[y]];
  // });
    
  // vector<int> ans(q);
    
  // int i = 0;
  // ll now = 0;
  // for(auto [k, v]: mp) {
  //   now += v;
  //   // debug(k, query[id[i]]);
  //   if(i < q && k == query[id[i]]) {
  //     ans[id[i]] = (now == 0);
  //     // debug(id[i], k);
  //     ++ i;
  //   }
  // }

  // for(int i = 0; i < q; i ++ ) if(ans[i]) {
  //   cout << "Yes\n";
  // } else {
  //   cout << "No\n";
  // }
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}