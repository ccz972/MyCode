#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for (int i = (b); i <= (s); ++i)
#define dec(i, b, s) for (int i = (b); i >= (s); --i)

using ll = long long;

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
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(random_device{}()); 
// mt19937 rnd(random_device{}()); 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2E6 + 10;

// int a[N], b[N];

inline bool check(int x, int y) { return ((x + 1) % 3 == y); }
basic_string<int> a[1000];
void Main() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i ++ ) {
    int x; cin >> x;
    // a[i].insert(x);
    a[i] += x;
    // a[i].append(x);
  }

  for(int i = 0; i < n; i ++ ) {
    for(auto x: a[i]) {
      cout << x << " ";
    }
    cout << "\n";
  }
  for(int i = 0; i < n; i ++ ) {
    a[i].clear();
  }
  for(int i = 0; i < n; i ++ ) {
    for(auto x: a[i]) {
      cout << x << " ";
    }
    cout << "111\n";
  }
  // a.resize(n);
  // cin >> a;
  // for (int i = 0; i < n; i++) {
  //   cin >> a[i];
  // }
  // shuffle(a.begin(), a.end(), rng);
  // for(int i = 0; i < n; i ++ ) {
  //   cout << a[i] << " \n"[i + 1 == n];
  // }
  // shuffle(a, a + n, rng);
  // for(int i = 0; i < n; i ++ ) {
  //   cout << a[i] << " \n"[i + 1 == n];
  // }
  // shuffle(a, a + n, rng);
  // for(int i = 0; i < n; i ++ ) {
  //   cout << a[i] << " \n"[i + 1 == n];
  // }
  // int sum = 0;

  // for (int i = 0; i < n; i++) {
  //   int now = (a[i] - a[(i + n - 1) % n]);
  //   if (now == 2) {
  //     now = -1;
  //   }
  //   sum += now;
  // }

  // if (sum >= 0)
  //   cout << "Yes\n";
  // else
  //   cout << "No\n";



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) Main();
  return 0;
}