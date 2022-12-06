#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1; cin >> T; 
  while(T -- ) solve();
  return 0;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  if(n == 1) {
    cout << "-1\n";
    return ;
  }
  if(*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()) ) {
    for(int i = 1; i <= n; i ++ ) cout << ((i + 1) % n ? (i + 1) % n : n) << " ";
    cout << "\n";
    return ;
  }

  map<int, vector<int> > mp;
  map<int, int> cnt;
  for(int i = 0; i < n; i ++ ) {
    mp[a[i]].push_back(i + 1);
    cnt[i] = mp[a[i]].size(); 
  }
  for(auto [k, v] : mp) {
    if((int)(v.size()) == 1) {
      cout << "-1\n";
      return ;
    }
  }
  //1 1 1 2  
  for(int i = 0; i < n; i ++ ) {
    cout << mp[a[i]][cnt[i] % (mp[a[i]].size())] << " ";
  }
  cout << "\n";
  return ;

}