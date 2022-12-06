#include <bits/stdc++.h>
using namespace std;
// using ll = long long;

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

constexpr int N = 1010;

int n;
int a[N];

struct splitmix64 {
  size_t operator()(size_t x) const {
    static const size_t fixed =
        chrono::steady_clock::now().time_since_epoch().count();
    x += 0x9e3779b97f4a7c15 + fixed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};

unordered_map<int, int, splitmix64> mp;

// map<ll, int> mp;
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i], ++mp[a[i]];
  int ans = count(a + 1, a + 1 + n, 0ll);
  chkmax(ans, 2);
  rep(i, 1, n) {
    rep(j, 1, n) if (i != j && (a[i] || a[j])) {
      // map<ll, int> nmp;
      unordered_map<int, int, splitmix64> nmp;
      ++nmp[a[i]];
      ++nmp[a[j]];
      // ll l = a[i], r = a[j];
      int l = a[i], r = a[j];
      int len = 2;
      while (true) {
        if (abs(l + r) > 1E9 || !mp.count(l + r) || nmp[l + r] == mp[l + r]) {
          break;
        }
        ++len;
        ++nmp[l + r];
        l += r;
        swap(l, r);
      }
      chkmax(ans, len);
    }
  }

  cout << ans << "\n";
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
