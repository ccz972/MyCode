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
  int n; cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int &x: a) {
    cin >> x;
    mp[x] ++;
  }
  set<int> s1, s2;
  for (auto &[k, v]: mp) {
    if (v == 1) {
      s1.insert(k);
    } else if (v > 2) {
      s2.insert(k);
    }
  }

  int cnt = (int)s1.size();
  
  if ((cnt & 1) && (s2.empty())) {
    cout << "NO\n";
    return ;
  }

  string ans(n, 'A');

  if (~cnt & 1) {
    cnt /= 2;    
    for (int i = 0; i < n; i ++ ) if (s2.count(a[i]) || cnt) {
      ans[i] = 'B';
      if (s1.count(a[i])) {
        cnt --;
      }
    }
  } else {
    cnt /= 2;
    for (int i = 0; i < n; i ++ ) if (cnt && s1.count(a[i])) {
      ans[i] = 'B';
      -- cnt;
    }
    for (int i = 0; i < n; i ++ ) if (s2.count(a[i])) {
      ans[i] = 'B';
      break;
    }
  } 

  
  
  //1 2 3 5           4
  //4 5 6 6 6 7 9 11
  cout << "YES\n";

  cout << ans << "\n";
  //1 2 3 4 5 5 6 6 6 7 9 11
  //1   3   5     6 6 7   11
  //  2   4   5 6       9
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}