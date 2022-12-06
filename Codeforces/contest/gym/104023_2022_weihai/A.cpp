#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  // vector<string> s(5);
  // map<int, vector<string> > mp;
  map<string, int> mp;
  for (int i = 0; i < n; i ++ ) {
    for (int i = 0; i < 5; i ++ ) {
      string t; cin >> t;
      // mp[i].push_back(t);
      mp[t] ++;
    }  
  }

  int m; cin >> m;
  
  // vector<vector<string> > a(5);
  // vector<vector<string> > b(5);
  vector<int> cnta(5), cntb(5);
  for (int i = 0; i < m; i ++ ) {
    string t; cin >> t;
    int op; cin >> op; op --;
    if (mp[t]) {
      cnta[op] ++;
    } else {
      cntb[op] ++;
    }
  }

  // for (int i = 0; i < 5; i ++ ) {
  //   cout << cnta[i] << " \n"[i == 4];
  // }
  // for (int i = 0; i < 5; i ++ ) {
  //   cout << cntb[i] << " \n"[i == 4];
  // }

  // select a
  
  int ans = 0;

  auto get = [&] (int x) {
    int cnt = cnta[x];
    for (int i = 0; i < 5; i ++ ) if (i != x) {
      cnt = min(cnt, cnta[i] + cntb[i]);
    }
    ans += cnt;
    cnta[x] -= cnt;
    for (int i = 0; i < 5; i ++ ) if (i != x) {
      cntb[i] -= cnt;
      if (cntb[i] < 0) {
        cnta[i] += cntb[i];
        cntb[i] = 0;
      }
    }
  };

  for (int i = 0; i < 5; i ++ ) get(i);



  // int cnt = 100000;
  // for (int i = 0; i < 5; i ++ ) cnt = min(cnt, cnta[i]);

  // ans += cnt;

  cout << ans << "\n";


  
  

  
  

  
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}