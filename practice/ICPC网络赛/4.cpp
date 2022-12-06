#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
  //{1, 1}
  // cout << "{";
  int last = 2;
  int ans = 0;
  array<int, 2> now;
  map<int, int> mp;
  int noWw = 0;
  cout << "{";
  for (int i = 3; i <= 1000000000; i ++ ) {
    if (__builtin_popcount(i) == __builtin_ctz(i)) {
      // cout << i << "\n";
      // cout << i << ",";
      if (i - last >= 25000) {
        cout << i << ",";
      }  
      ++ noWw;
      if (i - last > ans) {
        ans = i - last;
        now = {last, i };
        // cout << now[0] << " " << now[1] << "\n";
      } 
      mp[i - last] ++;
      ans = max(ans, i - last);
      last = i;

    


      // if (i % 8) cout << i << "\n";
      // bitset<10> b(i);
      // for (int j = 9; j >= 0; j -- ) cout << b[j];
      // cout << "\n";
    }
  }  
  cout << "}\n";
  cout << noWw << "\n";
  cout << ans << "\n";
  cout << now[0] << " " << now[1] << "\n";
  for (auto [k, v]: mp) {
    cout << k << " " << v << "\n";
  }
  // cout << "}";
  // cout << cnt << "\n";
}

void solve2() {
  int l, r; cin >> l >> r;
  for (int i = 1; i <= 15; i ++ ) {
    int now = 1;
    for (int j = 0; j < i; j ++ ) now <<= 1;
    
  }
}

void solve3() {

}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // freopen("1.txt", "w", stdout);
  int T = 1; //cin >> T;
  while (T -- ) solve();
  return 0;
}