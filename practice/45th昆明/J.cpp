#include <bits/stdc++.h>
using namespace std;
#define SZ(s) ((int)s.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define PII pair<int, int>

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

constexpr int N = 1E5 + 10;

int n, a[N], idx[N];
bool vis[N];

void solve() {
  cin >> n;
  // int n = rnd(100000) + 1;
  rep(i, 1, n) cin >> a[i], idx[a[i]] = i;
  // iota(a + 1, a + 1 + n, 1);
  // for (int i = 0; i < 20; i ++ ) {
  //   shuffle(a + 1, a + 1 + n, rng);
  // }
  // rep(i, 1, n) idx[a[i]] = i;
  // cout << n << "\n";
  // rep(i, 1, n) cout << a[i] << " \n"[i == n];

  if (is_sorted(a + 1, a + 1 + n)) {
    return cout << "0\n", void();
  }
  int cnt_two = 0;
  rep(i, 1, n) if (!vis[i]) {
    if (a[i] == i) {
      vis[i] = true;
    } else {
      int val = a[a[i]];
      if (val == i) {
        ++ cnt_two;
        vis[i] = vis[a[i]] = true;
      }
    }
  }

  bool flag = true;
  
  rep(i, 1, n) flag &= vis[i];

  if (flag) {
    cout << "1\n";
    cout << cnt_two << " ";
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i ++ ) if (!vis[i] && i != a[i]) {
      cout << i << " " << a[i] << " ";
      vis[i] = vis[a[i]] = true;
    }    
  } else {
    cout << "2\n";
    memset(vis, false, sizeof vis);
    vector<int> b;
    vector<vector<pair<int, int> > > ans(2);
    rep(i, 1, n) if (!vis[i] && i != a[i]) {
      int now = i; b.push_back(now); vis[i] = true;  // cout << i << " ";
      while (a[now] != i) {
        now = a[now];
        vis[now] = true;
        b.push_back(now);
      }
      if (SZ(b) == 2) {
        ans[0].push_back({b[0], b[1]});
      } else {
        // if (SZ(b) & 1) {
        int m = SZ(b);
        for (int i = 1, j = m - 1; i < j; i ++, j -- ) {
          ans[0].push_back({b[i], b[j]});
        }
        // }
      } //0 1 2 3 4 5
      b.clear();
    }
    cout << SZ(ans[0]) << " ";
    for (auto [x, y]: ans[0]) {
      cout << idx[x] << " " << idx[y] << " ";
      swap(a[idx[x]], a[idx[y]]);
      swap(idx[x], idx[y]);
    }
    cout << "\n";

    cnt_two = 0;
    rep(i, 1, n) if (a[i] != i) {
      ++ cnt_two;
    }
    assert(cnt_two % 2 == 0);
    cout << cnt_two / 2 << " ";

    memset(vis, false, sizeof vis);
    // cout << "------------\n";
    // rep(i, 1, n) cout << a[i] << " \n"[i == n];
    // cout << "------------\n";
    rep(i, 1, n) if (i != a[i] && !vis[i]) {
      cout << i << " " << a[i] << " ";
      vis[i] = vis[a[i]] = true;
    }


  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while (T -- ) solve();

  return 0;
}