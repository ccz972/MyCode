#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
#define YES cout << "YES\n"
#define NO cout << "NO\n"

constexpr int MAX_N = 1E5 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  vector<int> min_primes(MAX_N), primes;
  primes.reserve(MAX_N);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }

  auto solve = [&] () {
    int a, b, k; cin >> a >> b >> k;
    if (a == b && k == 1) {
      return cout << "NO\n", void();
    }
    if (k == 1) {
      if (a % b == 0 || b % a == 0) {
        return YES, void();
      } else {
        return NO, void();
      }
    }
    int g = gcd(a, b);
    auto get = [&] (int x, int ret = 0) -> int {
      // for (int i = 2; i <= x / i; i ++ ) if (x % i == 0) {
      //   while (x % i == 0) {
      //     ++ ret;
      //     x /= i;
      //   }
      // }
      // if (x != 1) ++ ret;
      // return ret;
      for (auto p : primes) {
        if (p * p > x) break;
        while (x % p == 0) {
          ++ ret;
          x /= p;
        }
      }
      if (x != 1) ++ ret;
      return ret;
    };

    int l = 0, r = 0;
    if (a != g) l ++;
    if (b != g) l ++;
    r += get(a / g);
    r += get(b / g);
    r += get(g) * 2;
    if (k <= r) YES;
    else NO;
    // if (l <= k && k <= r) YES;
    // else if (k < l) NO;
    // else {
    //   // if ((k & 1) != (r & 1) ) {
    //   //   r --;
    //   // }
    //   // if (r < 0) return cout << "NO\n", void();
    //   l += 2; 
    //   r += get(g) * 2;
    //   if (l <= k && k <= r) YES;
    //   else NO;
    // }

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}