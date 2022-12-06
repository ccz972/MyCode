#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int cnt = 0;
    for(int i = 0; i < n; i ++ ) if(a[i] != 0) {
      int j = i;
      while(j + 1 < n && a[j + 1] != 0) {
        ++ j;
      }
      cnt ++;
      i = j;
    }
    cout << min(cnt, 2) << "\n";  
  }
}