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

constexpr int N = 1E6 + 10;
constexpr int M = 1E7 + 10;

int n, m;
int a[N], b[N];
int A[N], B[N];
int N1, M1;
// int cnt1[M], cnt2[M];
int pos1[M], pos2[M];
// bool vis1[N], vis2[N];
pair<int, int> ret[M << 1];
// vector<pair<int, int> > ret[M << 1];
void solve() {
  cin >> n >> m;
  bool flag1 = false, flag2 = false;
  array<int, 2> ans1, ans2;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    if (pos1[a[i]]) {
      flag1 = true;
      ans1 = {pos1[a[i]], i};
    } else {
      A[++ N1] = i;
      // vis1[i] = true;
      pos1[a[i]] = i;
    }
  }
  for (int i = 1; i <= m; i ++ ) {
    cin >> b[i];
    if (pos2[b[i]]) {
      flag2 = true;
      ans2 = {pos2[b[i]], i};
    } else {
      // vis2[i] = true;
      B[++ M1] = i;
      pos2[b[i]] = i;
    }
  }

  if (flag1 && flag2) {
    assert(a[ans1[0]] - a[ans1[1]] == b[ans2[0]] - b[ans2[1]]);
    cout << ans1[0] << " " << ans1[1] << " " << ans2[0] << " " << ans2[1];
    return ;
  }

  for (int i = 1; i <= N1; i ++ )  {
    for (int j = 1; j <= M1; j ++ )  {
      int t = a[A[i]] + b[B[j]];
      if (ret[t].first) {
        assert(a[ret[t].first] - a[A[i]] == b[B[j]] - b[ret[t].second]);
        cout << ret[t].first << " " << A[i] << " ";
        cout << B[j] << " " << ret[t].second << " ";
        return ;
      }
      ret[t] = make_pair(A[i], B[j]);
      // ret[t].emplace_back(A[i], B[j]);
    }
  }
  cout << "-1";
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
