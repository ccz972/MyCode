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
constexpr int M = 5E6 + 10;

int a[N];
int b[N];
vector<int> cnt[M];
vector<pair<int, int> > Pos[M];

int x[M], y[M];

void solve1() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  for (int i = 1; i <= n; i ++ ) {
    for (int j = i + 1; j <= n; j ++ ) {
      int now = a[i] + a[j];
      if (x[now] != y[now] && x[now] != i && x[now] != j && y[now] != i && y[now] != j) {
        cout << "YES\n";
        cout << i << " " << j << " " << x[now] << " " << y[now] << "\n";
        return ;
      }
      x[now] = i, y[now] = j;
    }
  }
  cout << "NO\n";
}

void solve2() {
  int n; cin >> n;
  vector<int> pos;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    cnt[a[i]].emplace_back(i);
    if ((int)cnt[a[i]].size() == 2) {
      pos.emplace_back(a[i]);
    }
    if ((int)cnt[a[i]].size() >= 4) {
      cout << "YES\n";
      for (int j = 0; j < 4; j ++ ) {
        cout << cnt[a[i]][j] << " ";
      }
      return ;
    }
  }
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  if (pos.size() >= 2) {
    cout << "YES\n";
    auto t1 = pos[0], t2 = pos[1];
    cout << cnt[t1][0] << " " << cnt[t2][0] << " ";
    cout << cnt[t1][1] << " " << cnt[t2][1] << "\n";
    return ;
  }
  int m = 0;
  for (int i = 1; i < M; i ++ ) if (!cnt[i].empty()) {
    b[++ m] = i;
  }

  for (int i = m; i >= 1; i -- ) {
    for (int j = i - 1; j >= 1; j -- ) {
      if (Pos[b[i] - b[j]].empty()) {
        Pos[b[i] - b[j]].emplace_back(cnt[b[i]][0], cnt[b[j]][0]);
      } else {
        auto [t1, t2] = Pos[b[i] - b[j]].front();
        if (b[i] != a[t2]) {
          cout << "YES\n";
          cout << t1 << " " << cnt[b[j]][0] << " ";
          cout << t2 << " " << cnt[b[i]][0] << "\n";
          return ;
        } else if ((int)cnt[b[i]].size() >= 2) {
          cout << "YES\n";
          cout << t1 << " " << cnt[b[j]][0] << " ";
          cout << t2 << " " << cnt[b[i]][1] << "\n";
          return ;
        } 
      }
    }
  }

  cout << "NO\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve1();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
