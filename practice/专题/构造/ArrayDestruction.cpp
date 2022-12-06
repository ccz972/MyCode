//https://vjudge.net/contest/520750#problem/E

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

namespace False {

constexpr int N = 1E4 + 10;
int a[N];

void solve() {
  int n; cin >> n;
  multiset<int> s;
  for (int i = 1; i <= n * 2; i ++ ) cin >> a[i], s.insert(a[i]);
  sort(a + 1, a + 1 + 2 * n);
  reverse(a + 1, a + 1 + 2 * n);  

  
  vector<pair<int, int> > ans;

  if (a[1] == a[2]) {
    int now = a[1];
    ans.emplace_back(now, now);
    s.erase(s.find(now));
    s.erase(s.find(now));
    int sum = a[1];
    bool flag = true;
    for (int i = 1; i <= n - 1; i ++ ) {
      now = *s.rbegin(); s.erase(s.find(now)); 
      if (!s.contains(sum - now)) { 
        flag = false;
        break;
      } else {
        ans.emplace_back(now, sum - now);
        s.erase(s.find(sum - now));
        sum = now;
      }
    }

    if (!flag) return cout << "NO\n", void();

    cout << "YES\n";
    cout << ans.front().first + ans.front().second << "\n";
    for (auto [k, v]: ans) cout << k << " " << v << "\n";

  } else {



    ans.emplace_back(a[1], -1);
    int sum = a[1]; s.erase(s.find(a[1]));
    bool flag = true;

    for (int i = 1; i <= n - 1; i ++ ) {
      int now = *s.rbegin(); s.erase(s.find(now)); 
      if (!s.contains(sum - now)) {
        if (ans.front().second == -1) {
          ans.front().second = now;
          now = *s.rbegin(); s.erase(s.find(now)); 
          if (!s.contains(sum - now)) {
            flag = false;
            break;
          } else {
            ans.emplace_back(now, sum - now);
            s.erase(s.find(sum - now));
            sum = now;
          }
        } else {
          flag = false;
          break;
        }
        
      } else {
        ans.emplace_back(now, sum - now);
        s.erase(s.find(sum - now));
        sum = now;
      }
    }

    if (!flag) return cout << "NO\n", void();
    if (!s.empty()) {
      ans.front().second = *s.begin();
    }
    cout << "YES\n";
    cout << ans.front().first + ans.front().second << "\n";
    for (auto [k, v]: ans) cout << k << " " << v << "\n";
  }
}

}

namespace Nanfeng {
  constexpr int N = 2E3 + 10;
  int a[N];

  void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n * 2; i ++ ) cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    vector<pair<int, int> > ans(n);
    multiset<int> s;

    auto chk = [&] (int x) -> bool {
      int now = a[n * 2];
      for (int i = 1; i < n; i ++ ) {
        // debug(ans);
        auto p = *s.rbegin();  s.erase(s.find(p));
        if (s.contains(now - p)) {
          
          s.erase(s.find(now - p));
          ans[i] = make_pair(p, now - p);
          now = p;
        } else {
          return false;
        }
      }
      return true;
    };

    for (int i = 2 * n - 1; i >= 1; i -- ) {
      ans[0] = make_pair(a[n * 2], a[i]);
      
      for (int j = 1; j <= 2 * n - 1; j ++ ) if (i != j) {
        s.insert(a[j]);
      }

      if (chk(a[i])) {
        cout << "YES\n";
        cout << a[n * 2] + a[i] << "\n";
        for (int i = 0; i < n; i ++ ) {
          cout << ans[i].first << " " << ans[i].second << "\n";
        }
        return ;
      }

      s.clear();
    }
    cout << "NO\n";
  }
}

namespace Nanfeng2 {
  constexpr int N = 2E3 + 10;
  constexpr int M = 1E6 + 10;
  int a[N], cnt[M];
  pair<int, int> ans[N];
  void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n * 2; i ++ ) cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    reverse(a + 1, a + 1 + 2 * n);

    auto chk = [&] () -> bool {
      int now = a[1];
      for (int i = 2, j = 1; i <= n * 2; i ++, ++ j) {
        while (i <= n * 2 && !cnt[a[i]]) ++ i;
        if (i > n * 2) return true;
        cnt[a[i]] --;
        if (!cnt[now - a[i]]) {
          // cout << now << " " << now - a[i] << " " << a[i] << endl;
          return false;
        }
        cnt[now - a[i]] --;
        ans[j] = make_pair(a[i], now - a[i]);
        now = a[i];
      }
      return true;
    };
    for (int i = 0; i < M; i ++ ) cnt[i] = 0;
    for (int i = 2; i <= n * 2; i ++ ) {
      ans[0] = make_pair(a[1], a[i]);

      for (int j = 1; j <= n * 2; j ++ ) cnt[a[j]] = 0;

      for (int j = 2; j <= 2 * n; j ++ ) if (i != j) {
        cnt[a[j]] ++;
      }

      if (chk()) {
        cout << "YES\n";
        cout << a[1] + a[i] << "\n";
        for (int j = 0; j < n; j ++ ) {
          cout << ans[j].first << " " << ans[j].second << "\n";
        }
        return ;
      }

      

    }
    cout << "NO\n";
  }
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  Nanfeng2::solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
