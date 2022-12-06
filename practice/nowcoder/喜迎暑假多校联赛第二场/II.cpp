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

template<typename T> 
inline void Discrete (vector<T> &all) {
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
}

void solve() {
  int n; cin >> n;
  vector<int> a(n), all; 
  for(int &x: a) {
    cin >> x;
    all.push_back(x);
  }

  Discrete(all);
  auto find = [&] (int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
  };
  vector<vector<int> > id(n);
  for(int i = 0; i < n; i ++ ) {
    a[i] = find(a[i]);
    id[a[i]].push_back(i);
  }

  int l = 0, r = n / 3;

  auto chk = [&] (int x) -> bool {
    vector<int> l(n, -1), r(n, -1), cnt(n);
    for(int i = 0; i < n; i ++ ) {
      cnt[a[i]] ++;
      if(cnt[a[i]] == x) {
        l[a[i]] = i;
      }
    }
    for(int i = 0; i < n; i ++ ) cnt[i] = 0;

    for(int i = n - 1; i >= 0; i -- ) {
      cnt[a[i]] ++;
      if(cnt[a[i]] == x) {
        r[a[i]] = i;
      }
    } 

    vector<vector<pair<int, int> > > ne(n, vector<pair<int, int> >(2));

    for(int i = 0; i < n; i ++ ) if(l[i] < r[i]) {
      if(r[i] > ne[l[i]][0].first) {
        ne[l[i]][0] = {r[i], i}; 
        // l[i] 这个位置符合左边有 x 个，并且有一个右边的位置r[i] > l[i] 也符合右边有 x 个
      }
      //保证 ne[i][0] 的 右边界是小于 ne[i][1] 的
      if(ne[l[i]][0].first > ne[l[i]][1].first) {
        swap(ne[l[i]][0], ne[l[i]][1]);
      }

    }

    for(int i = 0; i < n; i ++ ) if(id[i].size() >= x) {
      for(int j = 0; j + x - 1 < id[i].size(); j ++ ) {
        int l = id[i][j], r = id[i][j + x - 1];
        if(!l) continue;
        if(ne[l - 1][0].first > r && ne[l - 1][0].second != i) return true;
        if(ne[l - 1][1].first > r && ne[l - 1][1].second != i) return true;
      }
    }

    return false;

  };

  while(l < r) {
    int mid = (l + r + 1) / 2;
    if(chk(mid)) l = mid;
    else r = mid - 1;
    // debug(mid);
    // cout << mid << "\n";
    // exit(0);
  }
  int ans = n - 3 * l;
  if(l == 0) ans = -1;
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
