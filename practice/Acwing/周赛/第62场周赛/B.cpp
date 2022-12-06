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

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  // sort(a.begin(), a.end());
  map<int, int> mp;
  for(int i = 0; i < n; i ++ ) {
    mp[a[i]] = i + 1;
  }
  if(mp.size() < 3) {
    cout << "-1 -1 -1\n";
  } else {
    int cnt = 0;
    for(auto[x, y]: mp) {
      cout << x << " ";
      ++ cnt;
      if(cnt == 3) {
        return ;
      }
    }
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
