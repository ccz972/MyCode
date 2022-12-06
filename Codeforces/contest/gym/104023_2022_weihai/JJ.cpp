#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;

  for(int& x : a) cin >> x;
  for(int x : a) mp[x] ++;

  sort(a.begin(), a.end());
  
  vector<pair<int, int>> p(k);

  int tt = 2e9;

  for(auto&[x, y] : p){
    cin >> x >> y;
    if(mp[x] > y){
      cout << "FuuFuu";
      return;
    }
    tt = min(tt, x);
  }



  if(tt){
    p.push_back({0, n + 1});
    k ++;
  }
  sort(p.begin(), p.end());


  int tk = k;
  for(int i = 1; i < k; i ++){
    if(p[i].first != p[i - 1].first + 1) {
      p.push_back({p[i - 1].first + 1, n});
      // cout << p[i - 1].first + 1 << ' ' << n << endl;
      tk ++;
    }
  }
  
  p.push_back({p[k - 1].first + 1, n}), tk ++;
  sort(p.begin(), p.end()); k = tk;
  
  vector<int> p0;p0.push_back(-1);
  for(auto[x, y] : p){
    if(y == 0) p0.push_back(x);
  }
  p0.push_back(*max_element(a.begin(), a.end()) + 1);


  int pl = 0, pr = 0, tl = 0, tr = 1, al = 0, ar = 0;
  
  int ans = 0;

  while(tr < p0.size()){
    while(p[pl].first <= p0[tl]) pl ++;
    while(al < n && a[al] <= p0[tl]) al ++;
    ar = al;
    while(ar + 1 < n && a[ar + 1] < p0[tr]) ar ++;
    for(int i = al, pi = pl; i <= ar; i ++){
      if(p[pi].second == 0) pi ++;
      // cout << a[i] << ' ' << pi << ' '<<  p[pi].first << '\n';
      ans += a[i] - p[pi].first;
      p[pi].second --;
    }
    tl = tr, tr ++;
  }

  // cout << ans << "   ";
  if(ans & 1) cout << "Pico";
  else cout << "FuuFuu";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T --){
    solve();
    cout << "\n";
  }
  return 0;
}
