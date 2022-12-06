#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 8010;
constexpr int P = 998244353;

int ksm(int a, int b, int ret = 1) {
  while(b) {
    if(b & 1) ret = 1ll * ret * a % P;
    b >>= 1;
    a = 1ll * a * a % P;
  }
  return ret;
}

int a[N], s[N], inv[N];

void add(int &x, int y) {
  x += y;
  if(x >= P) x -= P;
  if(x < 0) x += P;
}

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      // fenw[x] += v;
      add(fenw[x], v);
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      // v += fenw[x];
      add(v, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

void solve() {
  int n; cin >> n;

  for(int i = 1; i < n; i ++ ) {
    cin >> a[i]; s[i] = s[i - 1] + a[i];
    inv[i] = ksm(a[i], P - 2);
  }

  vector<fenwick<int>> f(n + 10, fenwick<int>(n + 10));
  f[0].modify(1, 1);  f[0].modify(2, -1);
  for(int i = 0; i < n; i ++ ) {
    for(int j = i + 1; j <= s[i] + 1 && j < n; j ++ ) {
      int now = 1ll * f[i].get(j) * inv[j] % P; 
      f[i + 1].modify(j + 1, now);
      f[i + 1].modify(min(n + 1, j + a[j] + 1), -now);
    }
  }
  int ans = 0;
  for(int i = 1; i < n; i ++ ) {
    // cout << f[i].get(n) << "\n";
    int now = 1ll * f[i].get(n) * f[i].get(n) % P;
    add(ans, now);
  }
  cout << ans << "\n";

}

int main() {
  freopen("data.txt", "r", stdin);
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
