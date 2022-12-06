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
    vector<int> a(n);
    int ans = 0;
    // for(int i = 0)
    for (auto& x : a) cin >> x, ans ^= x;
    cout << a[0] << "\n";
    // for(int i = 0; i < n; i ++ ) {
    //   if(a[i] ^ ans = )
    // }
    //x ^ all = ans
    //ans ^ all = x
    //
    // cout << ans << "\n";
    
  }
  return 0;
}