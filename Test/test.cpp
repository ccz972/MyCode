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
constexpr int N = 5E5 + 10;
int n, q, sz, num, res, a[N], cnt[N];
bool vis[N];
vector<int> primes[N];
long long ans;

void init() {
  for (int i = 2; i < N; i ++ ) if (!vis[i]) {
    for (int j = i; j < N; j += i) {
      vis[j] = true;
      primes[j].emplace_back(i);
    }
  }
}

void dfs(int pos, int mul, int len, int flag) {
  if (pos == (int)primes[num].size()) {
    if (len) {
      if (flag == -1) cnt[mul] --;
      if (len & 1) res += cnt[mul];
      else res -= cnt[mul];
      if (flag == 1) cnt[mul] ++;
    }
  } else {
    dfs(pos + 1, mul, len, flag);
    dfs(pos + 1, mul * primes[num][pos], len + 1, flag);
  }
}

int add(int k) {
  num = k, res = 0;
  dfs(0, 1, 0, 1);
  int ret = sz - res;
  sz ++;
  return ret;
}

int del(int k) {
  num = k, res = 0;
  dfs(0, 1, 0, -1);
  sz --;
  int ret = sz - res;
  return ret;
}

void solve() {
  init();
  cin >> n >> q;
  rep (i, 1, n) cin >> a[i], vis[i] = false;
  while (q -- ) {
    int x; cin >> x;
    if (vis[x]) {
      // del
      ans -= del(a[x]);
    } else {
      // add
      ans += add(a[x]);
    }

    vis[x] = !vis[x];
    cout << ans << "\n";
  }

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
