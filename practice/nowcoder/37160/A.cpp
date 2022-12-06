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


// bool dfs(vector<int> &a) {
//   bool f = true;
//   for(int i = 0; i < n; i ++ ) {

//   }
// }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n; cin >> n;
  // vector<pair<ll, int> > a;
  if(n == 1) {
    cout << "Bob win";
    return 0;
  }
  vector<int> a;
  int res = 0;
  for(ll i = 2; i <= n / i; i ++ ) if(n % i == 0) {
    int cnt = 0;
    while(n % i == 0) {
      ++ cnt;
      n /= i;
    }
    a.push_back(cnt);
    res ^= cnt;
    // a.push_back(make_pair(i, cnt));
  }
  // if(n != 1) a.push_back(make_pair(n, 1));
  if(n != 1) a.push_back(1), res ^= 1;

  

  sort(a.begin(), a.end());

  bool f = false;
  if(a[0] == a.back() && a[0] == 1 && (~(int)a.size() & 1)) {
    f = true;
  }

  if(res && a.back() > 1) {
    f = true;
  }

  
  if(f) cout << "Alice win";
  else cout << "Bob win";


  return 0;
}