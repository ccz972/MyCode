#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()

void solve() {
  int n, p; cin >> n >> p;
  for (int i = n - 1; i > 0; i -- ) {
    cout << n << " " << i % n  << "\n";
  }
  cout << n << " " << n << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}