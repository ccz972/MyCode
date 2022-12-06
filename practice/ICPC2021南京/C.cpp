#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

constexpr int N = 4E6 + 10;
constexpr int M = 2E6;
constexpr int ST = 1E6;
int n, k; 
int a[N];
int b[M], w[M], suf[M];
vector<int> idx[N];

int getans1() {
  map<int, int> mp;
  int ans = 0;
  rep(i, 1, n) {
    mp[a[i]] ++;
    chkmax(ans, mp[a[i]]);
  }
  return ans;
}


void solve() {
  cin >> n >> k;
  rep(i, 1, n) {cin >> a[i]; a[i] += M; }
  int ret = getans1();
  if (k == 0) { 
    cout << ret << "\n"; 
  } else if (k > 0) {
    rep(i, 1, n) idx[a[i]].emplace_back(i);
    for (int i = 0; i < N; i ++ ) if (!idx[i].empty() && i - k >= 0 && i - k < N && !idx[i - k].empty()) {
      int m = 0;
      if (true) {
        int p = 0, q = 0;
        while (p < SZ(idx[i]) && q < SZ(idx[i - k])) {
          if (idx[i][p] < idx[i - k][q]) {
            b[m] = idx[i][p ++ ]; w[m ++ ] = -1;
          } else {
            b[m] = idx[i - k][q ++ ]; w[m ++ ] = 1;
          }
        }
        while (p < SZ(idx[i])) b[m] = idx[i][p ++ ], w[m ++ ] = -1;
        while (q < SZ(idx[i - k])) b[m] = idx[i - k][q ++ ], w[m ++ ] = 1;
      }
      int all = SZ(idx[i]);
      int now = 0; int mmx = 0;
      for (int j = 0; j < m; j ++ ) {
        if (now < 0) now = 0;
        now += w[j];
        chkmax(mmx, now);
      }
      chkmax(ret, all + mmx);
    }
    cout << ret << "\n";
  } else {
    rep(i, 1, n) idx[a[i]].emplace_back(i);

    for (int i = 0; i < N; i ++ ) if (!idx[i].empty() && i - k >= 0 && i - k < N && !idx[i - k].empty()) {
      int m = 0;
      if (true) {
        int p = 0, q = 0;
        while (p < SZ(idx[i]) && q < SZ(idx[i - k])) {
          if (idx[i][p] < idx[i - k][q]) {
            b[m] = idx[i][p ++ ]; w[m ++ ] = -1;
          } else {
            b[m] = idx[i - k][q ++ ]; w[m ++ ] = 1;
          }
        }
        while (p < SZ(idx[i])) b[m] = idx[i][p ++ ], w[m ++ ] = -1;
        while (q < SZ(idx[i - k])) b[m] = idx[i - k][q ++ ], w[m ++ ] = 1;
      }
      int all = SZ(idx[i]);
      int now = 0; int mmx = 0;
      for (int j = 0; j < m; j ++ ) {
        if (now < 0) now = 0;
        now += w[j];
        chkmax(mmx, now);
      }
      chkmax(ret, all + mmx);
    }
    cout << ret << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}