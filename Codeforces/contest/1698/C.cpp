#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll,int> mp;
    for (auto& x : a) cin >> x, mp[x] ++;
    bool flag = true;
    if(mp[0]) {
      // for(int i = )
      vector<ll> now;
      
      for (auto i = 0; i < n && flag; i ++ ) {
        if(a[i] != 0) {
          now.push_back(a[i]);
        }
        if((int)now.size() > 2) flag = false;
      }
      
      if((int)now.size() == 2) {
        if(now[0] + now[1] != 0) {
          flag = false;
        }
      }

    } else {
      vector<ll> now;
      for (auto i = 0; i < n && flag; i ++ ) {
        if(a[i] != 0) {
          now.push_back(a[i]);
        }
        if((int)now.size() > 4) flag = false;
      } 
      int sz = (int)now.size();
      if(sz == 3) {
        ll sum = now[0] + now[1] + now[2];
        if(sum != now[0] && sum != now[1] && sum != now[2]) {
          flag  =false;
        }
      } else if(sz == 4) {
        for(int i = 0; i < 4; i ++ ) {
          for(int j = i + 1; j < 4; j ++ ) {
            for(int k = j + 1; k < 4; k ++ ) {
              ll sum = now[i] + now[j] + now[k];
              bool f = false;
              for(int p = 0; p < 4; p ++ ) {
                if(sum == now[p]) {
                  f = true;
                }
              }
              if(!f) flag = false;
            }
          }
        }
      } else {
        flag = false;
      }
    }
    if(flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    
  }
  return 0;
}