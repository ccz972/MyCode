#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e3 + 10;

void solve() {
  int n = 100000;
  cout << n << "\n";
  for(int i = 1; i <= n; i ++ ) {
    cout << (1 << 30) - 1 - (1 << 20) - (1 << 10) - (1 << 5) << " ";
  }
  
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  freopen("in.txt", "w", stdout);
  int T = 1; //cin >> T;
  cout << T << "\n";
  while(T -- ) solve();

  return 0;
}