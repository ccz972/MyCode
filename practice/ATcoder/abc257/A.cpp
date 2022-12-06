#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;
  k --;
  k /= n;
  // k %= 26;
  cout << (char)('A' + k);
  return 0;
}