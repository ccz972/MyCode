#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }

  if (a[n - 1] <= a[n]) {
    cout << "Python will never be faster than C++\n";
    return ;
  }

  ll i = 1;

  while (i * (a[n - 1] - a[n]) <= a[n] - k) {
    i ++;
  }


  cout << "Python 3." << i + n << " will be faster than C++";
  

  // long long ret = (a[n] - k + a[n - 1] - a[n] - 1) / (a[n - 1] - a[n]);

  // cout << "Python 3." << ret + n << " will be faster than C++";

  // // if (ret >= (ll)) {
  // //   cout << "Python 3." << i << " will be faster than C++";
  // // }  
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
