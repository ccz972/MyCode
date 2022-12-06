#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n); for(int &x: a) cin >> x;
  sort(a.begin(), a.end());
  // a.erase(unique(a.begin(), a.end()), a.end());
  // n = a.size();
  bool flag = false, add = false; //green
  int l = 0, r = 0;
  for(int i = 0; i < n; i ++ ) {
    if(!flag) {
      l = a[i] + 15; r = l + 30; flag = true;
      if(i == n - 1) {
        cout << l << " " << r - 1 << "\n";
      }
    } else {
      if(a[i] < r) {
        
        if(!add && a[i] >= l) {
          r += 15;
          add = true;
        } 
        if(i == n - 1) {
          cout << l << " " << r - 1 << "\n";  
        }
      } else {
        cout << l << " " << r - 1 << "\n";
        add = false;
        l = a[i] + 15, r = l + 30;
      }
    }
  }
  // cout << l << " " << r - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  solve();
  return 0;
}