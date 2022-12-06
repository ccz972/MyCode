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

// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(random_device{}()); 

using ull = unsigned long long;
using HH = pair<ull, ull>;

constexpr HH mod = {1000000009, 1000000007};

HH operator*(const HH &a, const HH &b) {
  return {(a.first * b.first) % mod.first, (a.second * b.second) % mod.second};
}
 
HH operator+(const HH &a, const HH &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}
 
HH operator-(const HH &a, const HH &b) {
  return {(a.first - b.first + mod.first) % mod.first, (a.second - b.second + mod.second) % mod.second};
}
 
HH operator*(const HH &a, const ull &b) {
  return {(a.first * b) % mod.first, (a.second * b) % mod.second};
}
 
struct Hash {
  string s;  int n;
  vector<HH> base, hsh1, hsh2; 
  Hash(string p): s(p), n(p.size()), base(n + 1), hsh1(n + 1), hsh2(n + 1) {
    base[0] = hsh1[0] = hsh2[0] = {1, 1};
    base[1] = {rnd() % mod.first, rnd() % mod.second};
    for(int i = 1; i <= n; i ++ ) {
      base[i] = base[i - 1] * base[1];
      hsh1[i] = hsh1[i - 1] * base[1] + base[0] * (s[i - 1] - 'a' + 1);
      hsh2[i] = hsh2[i - 1] * base[1] + base[0] * (s[n - i] - 'a' + 1);
    }
  }

  HH get1(int l, int r) { //返回 l 到 r 的哈希值
    //注意 l > r, 默认 1 <= l <= r <= n
    return hsh1[r] - (hsh1[l - 1] * base[r - l + 1]);
  }
 
  HH get2(int l, int r) { //返回 r 到 l 的哈希值
    //注意 l > r, 默认 1 <= l <= r <= n
    l = n - l + 1, r = n - r + 1;
    swap(l, r);
    return hsh2[r] - (hsh2[l - 1] * base[r - l + 1]);
  }

};

void solve() {
  string t; cin >> t;
  string res, s;
  int n = t.size(), k = -1;
  //01234
  while (k + 1 < (n / 2) && t[k + 1] == t[n - (k + 1) - 1]) {
    ++ k;
    res += t[k];
  }

  for (int i = k + 1; i < n - k - 1; i ++ ) {
    s += t[i];
  }

  if (s.empty()) return cout << t << "\n", void();
  
  n = s.size();
  
  Hash H(s);
  
  s = " " + s;

  int pre = 0;
  for (int i = 1; i <= n; i ++ ) {
    if ((i & 1) && H.get1(1, i / 2) == H.get2(i / 2 + 2, i)) pre = i;
    if ((~i & 1) && H.get1(1, i / 2) == H.get2(i / 2 + 1, i)) pre = i;
  }

  int suf = 0;
  for (int i = 1; i <= n; i ++ ) {
    if ((i & 1) && H.get1(n - i / 2 + 1, n) == H.get2(n - i + 1, n - i + i / 2)) suf = i;
    if ((~i & 1) && H.get1(n - i / 2 + 1, n) == H.get2(n - i + 1, n - i + i / 2)) suf = i;
  }

  string ans = res;
  reverse(res.begin(), res.end());

  if (pre >= suf) {
    for (int i = 1; i <= pre; i ++ ) ans += s[i];
    ans += res;
  } else {
    for (int i = n - suf + 1; i <= n; i ++ ) ans += s[i];
    ans += res;
  }

  cout << ans << "\n";
  
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
