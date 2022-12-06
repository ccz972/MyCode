#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  // string s;
  vector<int> s;
  vector<int> a(10);
  // int mi = 1e7;
  int idx = 1;
  for(int i = 1; i <= 9; i ++ ) {
    cin >> a[i];
    // mi = min(mi, a[i]);
    if(a[i] <= a[idx]) {
      idx = i;
    }
  }
  // int m = n;
  for(int i = 0; i < n / a[idx]; i ++ ) {
    s.push_back(idx);
  }

  n %= a[idx];

  for(int i = 0; i < s.size(); i ++ ) {
    for(int j = 9; j > idx; j -- ) if(a[j] - a[idx] <= n) {
      s[i] = j;
      n -= a[j] - a[idx];
      break;
    }
  }


  for(int x: s) cout << x;
  

  

}