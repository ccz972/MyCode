#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

constexpr ll inf = 1e18;

void solve() {
  int n = 2021;
  vector<ll> f(n + 1, inf);
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i <= n; i ++ ) {
    for(int j = 0; j < i; j ++ ) {
      f[i] = min(f[i], 2 * f[j] + 3 * f[i - j - 1] + 1 + j * j * (i - j - 1));
    }
  }
  cout << f[n] << "\n";
  cout << f.back();
}

int main() {
  solve();
  return 0;
}

