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
#define Rep(i, a, b) for (int i(a); i < b; ++i)
#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
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

// mt19937 rnd(random_device{}());
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

void solve2() {
  ll x, t, k, n, d;
  cin >> x >> t >> k >> n >> d;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  auto b = a;
  for (auto &x : b) a.push_back(x);
  auto now = x;
  // x == k
  ll inc = 0;
  assert(SZ(a) == 2 * SZ(b));
  // debug(a, b);
  if (inc == t) return cout << "YES\n", void();
  for (int i = 0; i < SZ(a); i++) {
    if (a[i] <= d) {
      now--;
    } else {
      now++;
    }
    if (now <= k) {
      inc++;
    } else {
      inc = 0;
    }
    if (inc == t) {
      return cout << "YES\n", void();
    }
  }

  if (now < x) {
    cout << "YES\n";
  } else if (now > x) {
    cout << "NO\n";
  } else {
    if (inc == 2 * n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve2();
  return 0;
}