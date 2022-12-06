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

constexpr int N = 1E4 + 10;

int f[N + 1];
int v[110];
int last[N];
bool vis[110];
void solve() {
  int n, m; cin >> n >> m;
  int sum = 0;
  for (int i = 1; i <= n; i ++ ) {
    int x, y; cin >> x >> y;
    sum += x;
    v[i] = y - x;
  }
  if (sum == m) {
    cout << "Yes\n";
    cout << string(n, 'H');
    return ;
  }
  f[sum] = 1;
  for (int i = 1; i <= n; i ++ ) if (v[i] != 0) {
    if (v[i] > 0) {
      for (int j = N; j >= v[i]; j -- ) {
        if (f[j - v[i]] && !f[j]) {
          f[j] = 1;
          last[j] = j - v[i];
        }
      }
    } else {
      for (int j = -v[i]; j <= N + v[i]; j ++ ) {
        if (f[j - v[i]] && !f[j]) {
          f[j] = 1;
          last[j] = j - v[i];
        }
      }
    }
  }

  if (!f[m]) {
    cout << "No\n";
    return ;
  }

  
  
  map<int, int> mp;
  int s = m, t = sum;
  while (s != t) {
    auto p = last[s];
    mp[s - p] ++;
    s = p;
  }

  cout << "Yes\n";

  for (int i = 1; i <= n; i ++ ) {
    if (mp[v[i]]) {
      -- mp[v[i]];
      cout << "T";
    } else {
      cout << "H";
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}