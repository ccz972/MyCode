#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int x, n; cin >> x >> n;
  if ((~x & 1) || (x == 1)) {
    while (n -- ) {
      int p, q; cin >> p >> q;
      cout << "0\n";
    }
  } else {

    

    while (n -- ) {
      int l, r; cin >> l >> r;
      ll ans = 0;
      if (l == 1) {
        if (r == 1) {
          cout << "0\n"; continue;
        } else {
          l ++; ans ++;
        }
      } 

      // [l, r]

      

    }
  }

}

void solve2() {
  int x = 99;
  // vector<int> a;
  // for (int i = 1; i <= 1000; i ++ ) {
  //   // cout << (gcd((i * x) ^ x, x) == 1) << " ";
  //   a.push_back(gcd((i * x) ^ x, x));
  // }
  // for (int i = 0; i < 1000; i ++ ) {
  //   int j = i; 
  //   while (j + 1 < 1000 && a[j + 1] == a[i]) ++ j;
  //   cout << a[i] << " " << j - i + 1 << "\n";
  //   i = j;
  // }
  auto get = [&] (int i) {
    return gcd((i * x) ^ x, x) == 1;
  };
  vector<int> a;
  for (int i = 1; i <= 1000; i ++ ) {
    a.push_back(get(i));
  }

  for (int len = 1; len <= 100; len ++ ) {
    bool flag = true;
    for (int i = 0; i < len && flag; i ++ ) {
      int j = i; 
      while (j < 1000) {
        if (a[j] != a[i]) {flag = false; break; }
        j += len;
      }
    }
    if (flag) return cout << "FUCK\n", void();
  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  //偶数都不可以

  //15: 2 3 5 8 9 12 14 15 18 19
  //5: 4 5 6 7 12 13 14 15 20
  //3: 2 3 6 7 10 11 14 15 18 19
  solve2();
  return 0;
}
