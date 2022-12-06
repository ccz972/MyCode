#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

mt19937 rnd(random_device{}());

constexpr int N = 5010;
// constexpr int P = 1E9 + 2;

int n;
int a[N];

bool check(int x) {
  map<int, int> vis;
  for (int i = 0; i < n; i ++ ) {
    vis[a[i] % x] ++;
    if (vis[a[i] % x] > n / 2) return true;
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i ++ ) cin >> a[i];
  int T = 100;
  while (T -- ) {
    int x = a[rnd() % n];
    int y = a[rnd() % n];
    int d = abs(x - y);
    for (int i = 1; i <= d / i; i ++ ) if (d % i == 0) {
      if (i >= 3 && check(i)) {
        return cout << i << "\n", void();
      }
      if (d / i >= 3 && check(d / i)) {
        return cout << d / i << "\n", void();
      }
    }
  }

  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}