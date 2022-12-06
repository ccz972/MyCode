#include <bits/stdc++.h>
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
constexpr int p = 998244353;
ll n, m, q;
ll a, b, c, d, h, w; 

void solve1() {
  ll result1 = (b + d) * w / 2 % p * (h / 2) % p;
  ll result2 = (a - 1 + c - 1) * h / 2 % p;
  ll temp = w * m / 2 % p; result2 = result2 * temp % p;
  cout << (result1 + result2) % p << "\n";
}

void solve2() {
  //h偶数 ， w奇数
  ll result1 = (b + d) * w / 2 % p * (h / 2) % p;
  ll result2;
  if ((a + b) & 1) {
    ll res1 = (a - 1 + c - 2) * (h / 2) / 2 % p; res1 = res1 * m % p;
    res1 = res1 * (w / 2) % p;
    ll res2 = (a + c - 1) * (h / 2) / 2 % p; res2 = res2 * m % p;
    res2 = res2 * ((w + 1) / 2) % p;
    result2 = res1 + res2; result2 %= p;
  } else {
    ll res1 = (a - 1 + c - 2) * (h / 2) / 2 % p; res1 = res1 * m % p;
    res1 = res1 * ((w + 1) / 2) % p;
    ll res2 = (a + c - 1) * (h / 2) / 2 % p; res2 = res2 * m % p;
    res2 = res2 * (w / 2) % p;
    result2 = res1 + res2; result2 %= p;
  }
  cout << (result1 + result2) % p << "\n";
}

void solve3() {
  ll result1, result2;
  if ((a + b) & 1) {
    ll res1 = (b + d) * w / 2 % p * (h / 2) % p;
    ll res2 = (b + 1 + d) * (w / 2) / 2 % p;
    result1 = res1 + res2; result1 %= p;
  } else {
    ll res1 = (b + d) * w / 2 % p * (h / 2) % p;
    ll res2 = (b + d - 1) * (w / 2) / 2 % p;
    result1 = res1 + res2; result1 %= p;
  }

  if (true) {
    ll res1 = (a - 1 + c - 1) * ((h + 1) / 2) / 2 % p; res1 = res1 * m % p;
    res1 = res1 * (w / 2) % p;
    ll res2 = (a + c - 2) * (h / 2) / 2 % p; res2 = res2 * m % p;
    res2 = res2 * (w / 2) % p;
    result2 = res1 + res2; result2 %= p;
  }
  cout << (result1 + result2) % p << "\n";
}

void solve4() {
  ll result1, result2;
  if ((a + b) & 1) {
    ll res1 = (b + d) * w / 2 % p; res1 = res1 * (h / 2) % p;
    ll res2 = (b + 1 + d - 1) * (w / 2) / 2;
    result1 = res1 + res2; result1 %= p;
  } else {
    ll res1 = (b + d) * w / 2 % p; res1 = res1 * (h / 2) % p;
    ll res2 = (b + d) * ((w + 1) / 2) / 2;
    result1 = res1 + res2; result1 %= p;
  }
  if ((a + b) & 1) {
    ll res1 = (a - 1 + c - 1) * ((h + 1) / 2) / 2 % p;
    res1 = res1 * m % p;
    res1 = res1 * (w / 2) % p;
    ll res2 = (a + c - 2) * (h / 2) / 2 % p;
    res2 = res2 * m % p;
    res2 = res2 * ((w + 1) / 2) % p;
    result2 = res1 + res2; result2 %= p;
  } else {
    ll res1 = (a - 1 + c - 1) * ((h + 1) / 2) / 2 % p;
    res1 = res1 * m % p;
    res1 = res1 * ((w + 1) / 2) % p;
    ll res2 = (a + c - 2) * (h / 2) / 2 % p;
    res2 = res2 * m % p;
    res2 = res2 * (w / 2) % p;
    result2 = res1 + res2; result2 %= p;
  }
  cout << (result1 + result2) % p << "\n";
}

void solve() {
  cin >> n >> m >> q;
  while (q -- ) {
    cin >> a >> c >> b >> d;
    h = (c - a + 1), w = (d - b + 1);
    if (~h & 1) {
      if (~w & 1) {
        solve1();
      } else {
        solve2();
      } 
    } else {
      if (~w & 1) {
        solve3();
      } else {
        solve4();
      } 
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
