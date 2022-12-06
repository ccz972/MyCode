#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;

ll a[N];

struct node {
  int l, r, id;
  bool operator <(const node &T) const {
    if(max(l, r) != max(T.l, T.r))
      return max(l, r) > max(T.l, T.r);
    return id < T.id;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<array<int, 3> > a(n);
  set<node> s; int CNT = 0;
  for(auto &[x, y, z]: a) {
    cin >> x >> y;
    s.insert({x, y, CNT ++});
    z = x + y;
  }
  ll ans = 0;
  int cnt = 0;
  for(int i = 0; i < n; i ++ ) {
    int mx = max(s.begin()->l, s.begin()->r);
    
    while(i < s.begin()->id) {
      ans -= min(a[i][0], a[i][1]);
      cnt ++;
      s.erase({a[i][0], a[i][1], i});
      i ++;
    }
    ans += 1ll * cnt * mx;
    
    if(s.begin()->r == mx) {
      if(s.begin()->l < mx) {
        ans -= s.begin()->l;
        ans += s.begin()->r;
      }
      cnt = 0;
    } else if(s.begin()->r != mx && (int)s.size() != 1 && s.begin()->r < max(next(s.begin())->l, next(s.begin())->r)) {
      cnt = 1;  
      ans -= s.begin()->r;
    } else {
      cnt = 0;
    } 
    i = s.begin()->id;
    s.erase(s.begin());
  }
  cout << ans << "\n";
  

  return 0; 
}
