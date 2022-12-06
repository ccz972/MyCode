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

void solve() {
  int n, m; cin >> n >> m;
  int xs, ys; cin >> xs >> ys;
  int N; cin >> N;
  vector<pair<int, int> > a(N);
  map<int, vector<int> > x;
  map<int, vector<int> > y;
  for (int i = 0; i < N; i ++ ) {
    cin >> a[i].first >> a[i].second;
    x[a[i].first].emplace_back(a[i].second);
    y[a[i].second].emplace_back(a[i].first);
  }

  for (auto &[k, v]: x) {
    v.push_back(0);
    v.push_back(m + 1);
    sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
  }

  for (auto &[k, v]: y) {
    v.push_back(0);
    v.push_back(n + 1);
    sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
  }

  int Q; cin >> Q;
  while (Q -- ) {
    char op; int d;
    cin >> op >> d;
    if (op == 'U') {
      //往上走，要找到 y 里面的上面那个
      if (!y.count(ys)) {
        xs -= d;
        chkmax(xs, 1);
      } else {
        int idx = lower_bound(y[ys].begin(), y[ys].end(), xs) - y[ys].begin();
        -- idx;
        int nowx = y[ys][idx] + 1;
        int cha = xs - nowx;
        if (cha > d) {
          xs -= d;
        } else {
          xs = nowx;
        }
      }
      
    } else if (op == 'D') {
      if (!y.count(ys)) {
        xs += d;
        chkmin(xs, n);
      } else {
        int idx = lower_bound(y[ys].begin(), y[ys].end(), xs) - y[ys].begin();
        int nowx = y[ys][idx] - 1;
        int cha = nowx - xs;
        if (cha > d) {
          xs += d;
        } else {
          xs = nowx;
        }
      }
      
    } else if (op == 'R') {
      if (!x.count(xs)) {
        ys += d;
        chkmin(ys, m);
      } else {
        int idx = lower_bound(x[xs].begin(), x[xs].end(), ys) - x[xs].begin();
        int nowy = x[xs][idx] - 1;
        int cha = nowy - ys;
        if (cha > d) {
          ys += d;
        } else {
          ys = nowy;
        }
      }
      
    } else {
      if (!x.count(xs)) {
        ys -= d;
        chkmax(ys, 1);
      } else {
        int idx = lower_bound(x[xs].begin(), x[xs].end(), ys) - x[xs].begin();
        -- idx;
        int nowy = x[xs][idx] + 1;
        int cha = ys - nowy;
        if (cha > d) {
          ys -= d;
        } else {
          ys = nowy;
        }
      }
      
    }
    cout << xs << " " << ys << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}