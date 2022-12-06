#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define ay3 array<int, 3>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 


constexpr int N = 5E6 + 10;
constexpr int mid = 1E6 + 10;
int n, m;
int q[N];

class fenwick {
public:
  vector<int> fenw;
  int n;
  fenwick(int _n): n(_n) {
    fenw.resize(n);
  }
  void modify(int x, int v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  int get(int x) {
    int v = 0;
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

void solve() {
  cin >> n >> m;
  
  rep(i, 1, n) cin >> q[i + mid];
  int hh = 1 + mid, tt = n + mid;
  int flag = 1; // left

  string s; cin >> s;

  fenwick fen(n + 20);

  ll ans = 0;

  rep(i, 1, n) {
    ans += fen.get(n + 1) - fen.get(q[i + mid]);
    fen.modify(q[i + mid], 1);
  }

  vector<int> res(m);

  ll sum = 1ll * n * (n - 1) / 2;

  cout << ans << "\n";

  Rep(i, 0, m) {
    if (s[i] == 'S') {
      if (flag) {
        int now = q[hh ++ ];
        q[++ tt] = now;
        ans -= now - 1;
        ans += n - now;
      } else {
        int now = q[tt --];
        q[-- hh] = now;
        ans -= now - 1;
        ans += n - now;
      }
      res[i] = ans % 10;
    } else if (s[i] == 'R') { 
      flag ^= 1;
      ans = sum - ans;
      res[i] = ans % 10;
    } else {
      assert(false);
    }
  }
  Rep(i, 0, m) {
    cout << res[i];
  }


}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}