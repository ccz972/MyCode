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

constexpr int N = 2E5 + 10;

int n, m;
ll a[N], b[N];
vector<ll> son[N];
bool vis[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    if (a[i] >= 0) {
      for (int j = a[i] + i, k = 1; j <= n + 1 && k <= m; j += i, k ++) {
        son[k].emplace_back(j);
      }
    } else {
      ll k = (-a[i] + i - 1) / i;
      a[i] += k * i;
      for (ll j = a[i]; j <= n + 1 && k <= m; j += i, k ++ ) {
        son[k].emplace_back(j);
      }
    }
  }

  for (int i = 1; i <= m; i ++ ) {
    for (int x: son[i]) {
      vis[x] = true;
    }
    for (int j = 0; j <= n + 1; j ++ ) if (!vis[j]) {
      cout << j << "\n";
      break;
    }
    for (int x: son[i]) {
      vis[x] = false;
    }
  }
  

  //多少次到达正数


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
