// https://codeforces.com/gym/103960/problem/B

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

constexpr int P = 1E9 + 7;

int dp[32][32][32][32];
int x, y, z;

void add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

void del(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}

int dfs (int pos, bool limit1, bool limit2, bool limit3) {
  if (pos == -1) return 1;
  if (~dp[pos][limit1][limit2][limit3]) return dp[pos][limit1][limit2][limit3];
  int &ret = dp[pos][limit1][limit2][limit3]; ret = 0;

  for (int i = 0; i < 2; i ++ ) if (!limit1 || i <= (x >> pos & 1)) {
    for (int j = 0; j < 2; j ++ ) if (!limit2 || j <= (y >> pos & 1)) {
      for (int k = 0; k < 2; k ++ ) if (!limit3 || k <= (z >> pos & 1)) if ((i ^ j ^ k) == 0) {
        add(ret, dfs (pos - 1, limit1 && (i == (x >> pos & 1)), limit2 && (j == (y >> pos & 1)), limit3 && (k == (z >> pos & 1))));
      }
    }
  }

  return ret;
}

int get(int l1, int l2, int l3) {
  memset(dp, -1, sizeof dp);
  x = l1, y = l2, z = l3;
  return dfs (30, true, true, true);
}

int ksm(int a, int b, int ret = 1) {
  while (b) {
    if (b & 1) ret = 1ll * ret * a % P;
    b >>= 1;
    a = 1ll * a * a % P;
  }
  return ret;
}

void solve() {
  int l1, r1, l2, r2, l3, r3;
  cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;

  int sum = ((1ll * (r1 - l1 + 1) * (r2 - l2 + 1) % P) * (r3 - l3 + 1)) % P;

  int ans = 0;
  add(ans, get(r1, l2 - 1, l3 - 1)); //100
  add(ans, get(l1 - 1, r2, l3 - 1)); //010
  add(ans, get(l1 - 1, l2 - 1, r3)); //001
  add(ans, get(r1, r2, r3)); //111

  del(ans, get(r1, r2, l3 - 1));
  del(ans, get(r1, l2 - 1, r3));
  del(ans, get(l1 - 1, r2, r3));
  del(ans, get(l1 - 1, l2 - 1, l3 - 1));
  //111
  //101
  //010

  //2 5 7

  //1 

  // int p = sum;
  // del(p, ans);

  // ans = 1ll * p * ksm(sum, P - 2) % P;
  ans = 1ll * ans * ksm(sum, P - 2) % P;
  cout << ans << "\n";

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
