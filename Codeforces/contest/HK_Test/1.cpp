#include <iostream>
using namespace std;

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; i ++ ) {
    cout << "YES\n";
  }
  for(int i = 0; i < n; i ++ ) {
    cout << "NO\n";
  }
}

int main() {
  int n; cin >> n;
  int T; cin >> T;
  while(T -- ) {
    solve();
  }
  return 0;
}