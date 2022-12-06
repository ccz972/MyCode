#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; i ++ ) {
    int x; cin >> x;
    for(int j = 0; j < x; j ++ ) {
      cout << i << " " << j << " " << i * j << "\n";
    }
  }
}

int main() {
  int T; cin >> T;
  while(T -- ) {
    solve();
  }
  return 0;
}