#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;

int a[N];

struct node {
  int id, w;
  bool operator < (const node &T) const {
    return w > T.w;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<node> B;
  rep(i, 1, n) {
    cin >> a[i];
    ans = ans - 1ll * i * i * a[i];
    B.push_back({i, a[i]});
  }

  sort(B.begin(), B.end());

  map<int, int> s;

  rep(i, k + 1, k + n) {
    s[i] ++;
  }

  for (auto &[a, b]: B) {
    if (s.count(a)) {
      s.erase(s.find(a));
      ans += 1ll * a * a * b;
    } else {
      auto p = s.lower_bound(a)->first;
      ans += 1ll * p * p * b;
      s.erase(s.find(p));
    }
  }

  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}