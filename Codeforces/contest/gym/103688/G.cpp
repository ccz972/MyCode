#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i(a); i <= b; ++ i)

using ll = long long;

constexpr int N = 2010;
constexpr int mod = 998244353;

ll f[N];
int a[N];

void solve() {
  int n; cin >> n;
  f[0] = 1;
  for(int i = 1; i <= n; i ++ ) {
    int v; cin >> v;
    if(!v) continue;
    for(int j = n; j >= v; j -- ) if(f[j - v]) {
      f[j] = (f[j] + f[j - v]) % mod;
    } 
  }
  for(int i = n; i >= 1; i -- ) {
    if(f[i]) {
      cout << i << " " << f[i] << "\n";
      return;
    }
  }

  cout << "0 0\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}