#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define PII pair<int, int>
#define debug(x) cout << #x << " > " << x << "\n"
#define all(a) a.begin(), a.end()
mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}
#define int ll
constexpr int N = 1E5 + 10;
bool vis[N];
int m;

int get() {
  int ret = 0;
  int sumji = 0, sumou = 1, sum = 0;
  for (int i = 0; i < m; i ++ ) {
    sum += vis[i];
    if (sum & 1) {
      ret += sumou;
      sumji ++;
    } else {
      ret += sumji;
      sumou ++;
    }
  }
  
  return ret;
}

void solve() {
  int n; cin >> n;
  m = n;
  for (int i = 0; i < n; i ++ ) vis[i] = 1;
  int cnt = get();
  cout << cnt << "\n";
  int now = 0;
  if (n <= 60) {
    // cout << "fuck1" << endl;
    for (int i = 0; i < (1ll << n); i ++ ) {
      for (int j = 0; j < n; j ++ ) vis[n - j - 1] = (i >> j & 1);
      if (get() == cnt) {
        now ++;
        for (int j = 0; j < n; j ++ ) cout << (vis[j] ? 'r' : 'b');
        cout << "\n";
        if (now == 100) break; //{cout << i << endl; break; }
      }
    }
  } else {
    int i = 0;
    while (true) {
      ++ i;
      for (int j = 0; j < n; j ++ ) vis[n - j - 1] = (i >> j & 1);
      if (get() == cnt) {
        now ++;
        for (int j = 0; j < n; j ++ ) cout << (vis[j] ? 'r' : 'b');
        cout << "\n";
        if (now == 100) break; 
      }
    }
  }
}

void baoli(int x) {
  ; //cin >> n;
  int n = x;
  m = n;
  for (int i = 0; i < n; i ++ ) vis[i] = 1;
  int ncnt = get();
  // cout << cnt << "\n";
  int now = 0;
  for (int i = 0; i < (1 << n) - 1; i ++ ) {
    for (int j = 0; j < n; j ++ ) vis[n - j - 1] = i >> j & 1;
    if (get() > ncnt) {
      cout << "FUCK\n";
      cout << n << "\n";
      for (int j = 0; j < n; j ++ ) cout << (vis[j] ? 'r' : 'b');
      exit(0);
    }
    // if (get() == cnt) {
    //   now ++;
    //   for (int j = 0; j < n; j ++ ) cout << (vis[j] ? 'r' : 'b');
    //   cout << "\n";
    //   if (now == 100) break; 
    // }
  }
  
}



signed main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // freopen("1.txt", "w", stdout);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}