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

ll f[50][50][50];
ll pw[50];

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
  for (int i = 0; i <= 40; i ++ ) {
    for (int j = 0; i + j <= 40; j ++ ) {
      for (int k = 0; i + j + k <= 40; k ++ ) {
        f[i][j][k] = calc(j, k);
      }
    }
  }
  pw[0] = 1;
  for (int i = 1; i <= 40; i ++ ) {
    pw[i] = pw[i - 1] * 3;
  }
}

ll solve(ll L, ll R) {
  auto x = get(L);
  auto y = get(R);
  int n = SZ(x);
  ll ret = fact(L); chkmax(ret, fact(R));
  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; i + j <= n; j ++ ) {
      int k = n - i - j;
      vector<int> cnt{i, j, k};
      ll val = n + j + k * 2, now = 0;
      bool flag = false;
      for (int l = 0; l < n && !flag; l ++ ) {
        int bit = x[l] - '0';
        if (bit == 0) {
          if (cnt[1]) {
            ll pnow = now + pw[n - l - 1];
            if (pnow + f[cnt[0]][cnt[1] - 1][cnt[2]] <= R) flag = true;
          } 
          if (cnt[2]) {
            ll pnow = now + pw[n - l - 1] * 2;
            if (pnow + f[cnt[0]][cnt[1]][cnt[2] - 1] <= R) flag = true;
          }
        } else if (bit == 1) {
          if (cnt[2]) {
            ll pnow = now + pw[n - l - 1] * 2;
            if (pnow + f[cnt[0]][cnt[1]][cnt[2] - 1] <= R) flag = true;
          }
        }

        if (!cnt[bit]) break;
        cnt[bit] --;
        now += pw[n - l - 1] * bit; 
      }
      if (flag) chkmax(ret, val);
    }
  }
  return ret;
}

void solve3() {
  ll L, R; cin >> L >> R;
  
  if (L == R) {
    cout << fact(L) << "\n";
    return ;
  }

  auto x = get(L);
  auto y = get(R);

  if (SZ(x) == SZ(y)) {
    cout << solve(L, R) << "\n";
  } else {
    ll ret = 3 * (SZ(y) - 1);
    assert(pw[SZ(y) - 1] > L);
    L = pw[SZ(y) - 1];
    chkmax(ret, solve(L, R));
    cout << ret << "\n";
  } 

}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  init();
  int T = 1; cin >> T;
  while (T --) solve3();
  return 0;
}