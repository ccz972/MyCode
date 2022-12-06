#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());


constexpr int P1 = 131, P2 = 13331;

constexpr int N = 8E5 + 10;

ull h1[N], h2[N];
ull p1[N], p2[N];

ull get1(int l, int r) {
  return h1[r] - h1[l - 1] * p1[r - l + 1];
}

ull get2(int l, int r) {
  return h2[r] - h2[l - 1] * p2[r - l + 1];
}



void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  s = " " + s + s + t + t;
  p1[0] = p2[0] = h1[0] = h2[0] = 1;
  for (int i = 1; i < N; i ++ ) {
    p1[i] = p1[i - 1] * P1;
    p2[i] = p2[i - 1] * P2;
  }

  for (int i = 1; i <= n * 4; i ++ ) {
    h1[i] = h1[i - 1] * P1 + s[i];
    h2[i] = h2[i - 1] * P2 + s[i];
  }
  
  // exit(0);

  // s = " " + s + s + t + t;
  vector<int> p(2 * n);
  for (int i = 0; i < n; i ++ ) p[i] = i + 1;
  for (int i = 0; i < n; i ++ ) p[i + n] = n * 2 + i + 1;

  sort(p.begin(), p.end(), [&] (int x, int y) {
    if (s[x] != s[y]) return s[x] < s[y];
    if (n == 1) return x < y;
    int l = 1, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (get1(x, x + mid) == get1(y, y + mid) && get2(x, x + mid) == get2(y, y + mid)) l = mid + 1;
      else r = mid;
    }
    if (s[x + l] == s[y + l]) return x < y;
    return s[x + l] < s[y + l];
  });
  

  // for (int i = 0; i < n * 2; i ++ ) {
  //   cout << p[i]; 
  //   if (p[i] < 10) cout << " ";
  //   cout << " : ";
  //   cout << s.substr(p[i], n) << "\n";
  // }

  ll ans = 0, now = n;
  for (int i = 0; i < 2 * n; i ++ ) if (p[i] <= n) {
    ans += now;
  } else {
    -- now;
  }

  cout << ans << "\n";




}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}