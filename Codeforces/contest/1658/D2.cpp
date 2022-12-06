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
constexpr int N = 1 << 18;
struct Trie {
  int nxt[N][2], tot, v[N];
  void init() {
    while (tot >= 0) {
      nxt[tot][0] = nxt[tot][1] = 0;
      -- tot;
    }
    tot = 0;
  }
  void insert(int x) {
    int p = 0;
    for (int i = 17; i >= 0; i -- ) {
      int &s = nxt[p][x >> i & 1];
      if (!s) s = ++ tot;
      p = s;
    }
  }
  int getmax(int sum) {
    int p = 0, res = 0;
    for (int i = 17; i >= 0; i -- ) {
      int s = sum >> i & 1;
      if (!nxt[p][s ^ 1]) p = nxt[p][s];
      else p = nxt[p][s ^ 1], res += (1 << i);
    }
    return res;
  }
  int getmin(int sum) {
    int p = 0, res = 0;
    for (int i = 17; i >= 0; i -- ) {
      int s = sum >> i & 1;
      if (!nxt[p][s]) p = nxt[p][s ^ 1], res += (1 << i);
      else p = nxt[p][s];
    }
    return res;
  }
} Tr;

int a[N], b[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto solve = [&] () {
    int l, r; cin >> l >> r;
    // cout << l << " " << r << "\n";
    Tr.init();
    for (int i = l; i <= r; i ++ ) {
      cin >> a[i]; 
      b[i] = (a[i] ^ l);
      Tr.insert(a[i]);
    }

    for (int i = l; i <= r; i ++ ) {
      // cout << Tr.getmin(b[i]) << " " << Tr.getmax(b[i]) << "\n";
      if (Tr.getmax(b[i]) == r && Tr.getmin(b[i]) == l) {
        cout << b[i] << "\n";
        return ;
      }
    }
  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}