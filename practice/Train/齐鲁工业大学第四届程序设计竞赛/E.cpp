#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
clock_t start = clock();
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution<ll> dis(0);

ll qPow(ll b, ll p, ll mod) {
  ll ret = 1;
  while (p) {
    if (p & 1) ret = (__int128)ret * b % mod;
    b = (__int128)b * b % mod;
    p >>= 1;
  }
  return ret;
}

bool MillerRabin(ll p) {
  if (p < 2) return false;
  if (p < 4) return true;
  ll d = p - 1;
  int r = 0;
  while ((d & 1) == 0) ++r, d >>= 1;
  for (ll k = 0; k < 10; ++k) {
    ll rv = dis(gen) % (p - 2) + 2;
    ll x = qPow(rv, d, p);
    if (x == 1 or x == p - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = (__int128)x * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return false;
  }

  return true;
}

ll PollardRho(ll n) {
  ll c = rand() % (n - 1) + 1;
  ll s = 0, t = 0;
  for (ll goal = 1, val = 1;; goal *= 2, s = t, val = 1) {
    for (ll step = 1; step <= goal; ++step) {
      t = ((__int128)t * t + c) % n;
      val = (__int128)val * abs(t - s) % n;
      if (step % 127 == 0) {
        ll d = gcd(val, n);
        if (d > 1) return d;
      }
    }
    ll d = gcd(val, n);
    if (d > 1) return d;
  }
}

bool check(ll x) {
  // PollardRho
  if (x == 1ll || MillerRabin(x)) return true;

  auto p = PollardRho(x);
  // while (p == x) p = PollardRho(x);
  auto q = x / p;
  debug(x, p, q);
  if (gcd(p, q) != 1) return false;
  if (!check(p) || !check(q)) return false;
  return true;
}

void solve() {
  ll x;
  cin >> x;
  
  if (check(x)) {
    cout << x << "\n";
    return;
  }
  int t = 1;
  while (true) {
    bool flag1 = check(x - t);
    bool flag2 = check(x + t);
    if (flag1) cout << x - t << "\n";
    if (flag2) cout << x + t << "\n";
    if (flag1 || flag2) break;
    ++ t;
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC *
  // 1000 << "ms" << endl;
#endif
  return 0;
}
