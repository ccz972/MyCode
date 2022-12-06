//lqmm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

void solve() {
  int n, m; cin >> n >> m;
  
  set<pair<int, int> > s;
  s.insert({-100, -100});
  s.insert({n + 100, n + 100});
  vector<bool> vis(n + 1);
  while (m -- ) {
    int op, x; cin >> op >> x;
    if (op == 1) {
      if (vis[x]) continue;
      vis[x] = true;
      auto idx = s.lower_bound({x + 1, -1});
      auto idxx = prev(idx);
      if (idx->first == x + 1) {
        if (idxx->second == x - 1) {
          auto [l1, r1] = *idx;
          auto [l2, r2] = *idxx;
          s.erase(idxx);
          s.erase(idx);
          s.insert({l2, r1});
        } else {
          auto [l, r] = *idx;
          s.erase(idx);
          s.insert({x, r});
        }
      } else {

        if (idxx->second == x - 1) {
          auto [l2, r2] = *idxx;
          s.erase(idxx);
          s.insert({l2, r2 + 1});
        } else {
          s.insert({x, x});
        }
      }
     } else if (op == 2) {
      if (!vis[x]) continue;
      auto idx = s.lower_bound({x, x});
      if (idx->first == x) {
        auto [l, r] = *idx;
        s.erase(idx);
        if (l != r) {
          s.insert({l + 1, r});
        }
      } else {
        idx = prev(idx);
        if (idx->first <= x && idx->second >= x) {
          auto [l, r] = *idx;
          s.erase(idx);
          if (l <= x - 1) {
            s.insert({l, x - 1});
          }
          if (r >= x + 1) {
            s.insert({x + 1, r});
          }
        }
      }
      vis[x] = false;
    } else {
      if (!vis[x]) {
        cout << "0\n";
      } else {
        auto idx = s.lower_bound({x, x});
        if (idx->first == x) {
          auto [l, r] = *idx;
          cout << r - l + 1 << "\n";
        } else {
          idx = prev(idx);
          if (idx->first <= x && idx->second >= x) {
            cout << idx->second - x + 1 << "\n";
          } else {
            cout << "0\n";
          }
        }
      }
    }
  }

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}