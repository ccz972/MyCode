#include <bits/stdc++.h>
using ll = long long;

constexpr int p = 19980829;
constexpr int INF = 2E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n; std::cin >> n;

  ll ret = 0;
  bool flag = false;

  for (int i = 0; i < n; i ++ ) {
    // x + a_i <= b_i * x
    //(b_i - 1) * x >= a_i
    int a, b; 
    std::cin >> a >> b;

    if (flag && b != 1) {
      ret *= b;
      ret %= p;
    } else {
      if (!ret || b == 1) {
        ret += a;
      } else if (ret * (b - 1) >= (ll)  a) {
        ret *= b;
      } else {
        ret += a;
      }
    }

    if (ret >= INF) {
      flag = true;
      ret %= p;
    }

  }

  std::cout << ret % p;


  return 0;
}