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
constexpr int INF = 1E9 + 7;

vector<pair<int, int> > add[N];
// vector<int> del[N];
int n, m, t, a[N];

void solve() {
  cin >> n;
  map<int, pair<int, int> > mp;
  for (int i = 1; i <= n; i ++ ) {
    string s; cin >> s;
    if (s[0] == 'A') {
      int x; cin >> x;
      a[++ m] = x;
      t = i;
      add[m].push_back({i, x});
    } else if (s[0] == 'D') {
      if (m) {
        // del[m].push_back(i);
        // add[m].pop_back();
        -- m;
      }
      t = i;
    } else if (s[0] == 'S') {
      int x; cin >> x;
      mp[x] = make_pair(m, i);
      // t = i;
    } else {
      int x; cin >> x;
      if (mp.count(x)) {
        m = mp[x].first;
        t = mp[x].second;
      } else {
        m = 0;
      }
    }
    if (!m) {
      cout << "-1 ";
    } else {
      auto idx = upper_bound(add[m].begin(), add[m].end(), make_pair(t, INF));
      cout << prev(idx)->second << " ";
    }
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
