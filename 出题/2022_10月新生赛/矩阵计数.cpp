#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

ll ksm(ll a, ll b, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % P;
    b >>= 1;
    a = a * a % P;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, x; cin >> n >> m >> x;
  
  return 0;
}