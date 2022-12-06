#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  map<string, vector<string> > mp;
  
  while(n -- ) {
    string a, b; cin >> a >> b;
    mp[a].push_back(b);
  }

  for(auto [k, v] : mp) {
    map<string, int> s, hash;
    
    int idx = 0;
    vector<int> a;
    for(string p: v) {
      if(!s.count(p)) {
        hash[p] = ++ idx;
      }
      s[p] ++;
      a.push_back(hash[p]);
    }
    n = a.size();
    map<int, int> pp;
    for(int i = 0, j = -1; i < n; ) {
      while(j + 1 < n && !pp[a[j + 1]]) {
        ++ j;
        pp[a[j]] ++;
      }
      if(j - i + 1 >= 5) {
        cout << "PENTA KILL!\n";
        return 0;
      }
      if(j == n - 1) {
        break;
      }
      while(pp[a[j + 1]]) {
        pp[a[i]] --;
        i ++;
      }
    }
  
    // cout << k << "\n";
    

  }

  // for(auto [k, s] : mp) {
  //   if((int) s.size() >= 5) {
  //     cout << "PENTA KILL!\n";
  //     return 0;
  //   }
  // }
  cout << "SAD:(\n";
  return 0;
}