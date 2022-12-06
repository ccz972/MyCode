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

void solve() {
  ll t, w, b;
  cin >> t >> w >> b;
  if (b > t || w > t) {
    ll p = min({t, w - 1, b - 1});
    if (p == 0) {
      return cout << "0\n", void();  
    }
    ll q = t;
    ll g = gcd(p, q);
    p /= g, q /= g;
    return cout << p << "/" << q << "\n", void();
  }

  if (w == b) {
    return cout << "1\n", void();
  }

  if (w == 1 || b == 1) {
    ll p = t / max(w, b), q = t;
    ll g = gcd(p, q);
    p /= g, q /= g;
    return cout << p << "/" << q << "\n", void();
  }

  ll ok = gcd(w, b);


  ll sum = w / ok;
  if (t / b < sum) {
    ll p = min({t, w - 1, b - 1});
    if (p == 0) {
      return cout << "0/1\n", void();  
    }
    ll q = t;
    ll g = gcd(p, q);
    p /= g, q /= g;
    return cout << p << "/" << q << "\n", void();
  }


  ll p = t / lcm(w, b) + t / (lcm(w, b) + 1) + 1, q = t;
  ll g = gcd(p, q);
  p /= g, q /= g;
  cout << p << "/" << q << "\n";
  //

  //1,6,7
  //7 1 2
  //2,3,4,5


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
