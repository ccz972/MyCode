#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    map<ll, int> mp;
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    ll sum = 0;
    for (auto& x : a) {
      cin >> x;
      mp[x] = 1;
      if(x != 0) cnt ++;
      sum += x;
    }
    if(n > 20) {
      if(cnt == 1) cout << "YES" << endl;
      else if(cnt > 2 && sum != 0) cout << "NO\n";
      else cout << "YES\n";
    } else {
      cout << "FUCK\n";
    }
    
  }
  return 0;
}