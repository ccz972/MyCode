constexpr int mod = 998244353;
ll mul(ll a, ll b, ll mod) { return a * b % mod; }
ll power(ll a, ll r, ll mod) {
  ll res = 1;
  for (; r; r >>= 1, a = mul(a, a, mod))
    if (r & 1) res = mul(res, a, mod);
  return res;
}
ll p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
bool miller_rabin(ll n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (not(n & 1)) return false;
  ll d = n - 1, r = 0;
  for (; not(d & 1); d >>= 1) r += 1;
  bool res = true;
  for (int i = 0; i < 9 and p[i] < n and res; i += 1) {
    ll x = power(p[i], d, n);
    if (x == 1 or x == n - 1) continue;
    for (int j = 1; j < r; j += 1) {
      x = mul(x, x, n);
      if (x == n - 1) break;
    }
    if (x != n - 1) res = false;
  }
  return res;
};
