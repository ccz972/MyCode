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

struct node {
  int l, r, s;
  bool operator < (const node &T) const {
    if(l != T.l) return l < T.l;
    return r < T.r;
  }
};

void solve() {
  int n, m; cin >> n >> m; 
  assert(n >= 1); assert(n <= 1000000);
  assert(m >= 1); assert(m <= 1000000);
  
  vector<node> a(n);
  vector<int> cnt(m + 2);
  vector<int> vis(m + 2);
  vector<vector<int> > L(m + 2), R(m + 2);
  ll sum = 0;
  for(int i = 0; i < n; i ++ ) {
    int l, r, s; cin >> l >> r >> s;
    cnt[l] ++, cnt[r + 1] --;
    L[l].push_back(i);
    R[r + 1].push_back(i);    
    assert(l >= 1); assert(r <= m); assert(l <= r);
    assert(s <= 1000000000); assert(s >= 1);
    a[i] = {l, r, s};
    sum += s;
  }

  ll now = 0, ans = 0;
  for(int i = 1; i <= m; i ++ ) {
    for(auto id: R[i]) {
      now -= a[id].s;
    }
    for(auto id: L[i]) {
      now += a[id].s;
    }
    chkmax(ans, sum - now);
  }

  cout << ans << "\n";




}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}