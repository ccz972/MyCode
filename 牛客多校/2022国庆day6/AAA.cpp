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


constexpr int N = 3010;

int n, m; 
int a[N][N];
int L[N][N], R[N][N];
int h[N][N], s[N][N];
int up[N];

void solve() {
  cin >> n >> m;
  rep (i, 1, n) {
    string t; cin >> t;
    rep (j, 1, m) {
      a[i][j] = (t[j - 1] - '0');
      if (a[i][j]) {
        L[i][j] = R[i][j] = j;
        h[i][j] = 1;
      }
      s[i][j] = s[i][j - 1] + a[i][j];
    }
  }
  rep (i, 1, n) {
    rep  (j, 1, m) {
      if (a[i][j] & a[i][j - 1]) {
        L[i][j] = L[i][j - 1];
      }
      // cout << L[i][j] << " \n"[j == m];
    }
    dec(j, 1, m) {
      if (a[i][j] & a[i][j + 1]) {
        R[i][j] = R[i][j + 1];
      }
      // cout << R[i][j] << " \n"[j == m];
    }
  }
  // vector<array<int, 4> > ans;
  vector<pair<int, int> > p;
  int ret = 0;
  rep (i, 1, n) {
    rep (j, 1, m) if (a[i][j]) {
      if (a[i - 1][j]) {
        chkmax(L[i][j], L[i - 1][j]);
        chkmin(R[i][j], R[i - 1][j]);
        h[i][j] = h[i - 1][j] + 1;
      }
      if (a[i + 1][j] && L[i + 1][j] <= L[i][j] && R[i + 1][j] >= R[i][j]) continue;
      // ret ++;
      p.emplace_back(L[i][j], R[i][j]);
      // ans.push_back({i - h[i][j], L[i][j], i, R[i][j]});
    }
    // sort(ans.begin(), ans.end());
    // ret += unique(ans.begin(), ans.end()) - ans.begin();
    sort(p.begin(), p.end());
    ret += unique(p.begin(), p.end()) - p.begin();
    p.clear();
  }
  
  cout << ret;
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
