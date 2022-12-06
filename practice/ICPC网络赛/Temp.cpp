#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E6 + 10;

int d[N];

void solve() {
  for (int i = 2; i < 20220911 ; i ++ ) if (20220911 % i == 0) {
    cout << "FUCK\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    if (i != 1) cout << "\n";
    solve();
  }
  return 0;
}