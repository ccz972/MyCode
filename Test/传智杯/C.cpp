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

ll fact(ll x) {
  if (!x) return 1;
  if (x % 3 == 0) return fact(x / 3) + 1;
  return fact(x - 1) + 1;
}

string get(ll x) {
  string ans;
  while (x) {
    ans += ('0' + x % 3);
    x /= 3;
  }
  reverse(all(ans));
  return ans;
}

ll f[36][36][36];
ll pw[37];
ll calc(int y, int z) {
  ll x = 0;
  while (z) {
    x = x * 3 + 2;
    -- z;
  }
  swap(y, z);
  while (z) {
    x = x * 3 + 1;
    -- z;
  }
  return x;
}

void init() {
  for (int i = 0; i <= 36; i ++ ) {
    for (int j = 0; i + j <= 36; j ++ ) {
      for (int k = 0; i + j + k <= 36; k ++ ) {
        f[i][j][k] = calc(j, k);
      }
    }
  }
  pw[0] = 1;
  for (int i = 1; i <= 36; i ++ ) {
    pw[i] = pw[i - 1] * 3;
  }
}

void solve2() {
  ll L, R; cin >> L >> R;
  auto x = get(L);
  auto y = get(R);
  if (L == R) {
    cout << fact(L) << "\n";
    return ;
  }
  if (SZ(x) != SZ(y)) {
    cout << max(fact(R), 3ll * (SZ(y) - 1)) << "\n";
  } else {
    int m = SZ(x);
    ll mx = fact(L);
    for (int i = 0; i < m; i ++ ) {
      for (int j = 0; i + j <= m; j ++ ) {
        int k = m - i - j;
        auto p = i, q = j, r = k;
        vector<int> cnt{p, q, r};
        ll now = 0; // pw[m - i - 1]
        ll val = j + k * 2 + m;
        bool flag = false;
        for (int l = 0; l < m && !flag; l ++ ) {
          if (x[l] == '0') {
            if (cnt[1]) {
              auto pnow = now + pw[m - l - 1];
              if (pnow + f[cnt[0]][cnt[1] - 1][cnt[2]] <= R) {
                flag = true;
              }
            } else if (cnt[2]) {
              auto pnow = now + pw[m - l - 1] * 2;
              if (pnow + f[cnt[0]][cnt[1]][cnt[2] - 1] <= R) {
                flag = true;
              }
            } 
          } else if (x[l] == '1') {
            if (cnt[2]) {
              auto pnow = now + pw[m - l - 1] * 2;
              auto res = f[cnt[0]][cnt[1]][cnt[2] - 1];
              if (pnow + f[cnt[0]][cnt[1]][cnt[2] - 1] <= R) {
                flag = true;
              }
            }
          }
          if (!cnt[x[l] - '0']) break;
          cnt[x[l] - '0'] --;
          now += pw[m - l - 1] * (x[l] - '0');
        }
        if (flag) chkmax(mx, val);
      }
    }
    cout << mx << "\n";
  }

}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  init();
  int T = 1; cin >> T;
  while (T --) solve2();
  return 0;
}