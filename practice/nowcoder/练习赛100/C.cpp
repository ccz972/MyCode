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
#define rep(i, a, b) for(int i(a); i <= b; ++ i)
// constexpr double pi = acos(-1);

bool solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1; // cin >> T; 
  while(T -- ) cout << (solve() ? "kou" : "yukari");
  return 0;
}

bool solve() {
  string s; cin >> s;
  vector<int> cnt(3);
  int sum = 0;
  for(char c: s) {
    if(c != '0') {
      cnt[(c - '0') % 3] ++;
      sum = sum + (c - '0') ;
      sum %= 3;
    }
  }

  
  if(!cnt[sum]) return false;
  cnt[sum] --;

  int mi = min(cnt[1], cnt[2]), mx = max(cnt[1], cnt[2]);
  if(mx > mi) {
    return false;
  } else if(mi == mx) {
    return cnt[0];
  } else {   
    return true;
  }
  

}