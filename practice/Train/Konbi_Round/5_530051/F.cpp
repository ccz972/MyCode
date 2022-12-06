#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
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
  vector<HH> base, hsh1, hsh2; // 注意空字符串
  Hash(string p): s(p), n(p.size()), base(n + 1), hsh1(n + 1), hsh2(n + 1) {
    base[0] = hsh1[0] = hsh2[0] = {1, 1};
    base[1] = {rnd() % mod.first, rnd() % mod.second};
    for(int i = 1; i <= n; i ++ ) {
      base[i] = base[i - 1] * base[1];
      hsh1[i] = hsh1[i - 1] * base[1] + base[0] * (s[i - 1] - '?' + 1);
      hsh2[i] = hsh2[i - 1] * base[1] + base[0] * (s[n - i] - '?' + 1);
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
constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;



void solve() {
  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;
  Hash h1(s);
  auto chk = [&] (int l, int len) {
    int left = l - len + 1, right = l + len - 1;
    if (h1.get1(left, right) == h1.get2(left, right)) return true;
    return false;
  };
  for (int i = 1; i <= n; i ++ ) {
    int l = 1, r = min(n - i + 1, i);
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (chk(i, mid)) l = mid;
      else r = mid - 1;
    }
    ans += l;
  }
  for (int i = 2; i <= n; i ++ ) if (s[i - 1] == s[i - 2]) {
    int l = 1, r = min(i - 1, n - i + 1);
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (h1.get1(i - mid, r + mid - 1) == h1.get2(i - mid, r + mid - 1)) l = mid;
      else r = mid - 1;
    }
    ans += l;
  }

  


  int q; cin >> q;
  while (q -- ) {
    string t; cin >> t;

  }

}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}