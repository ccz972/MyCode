#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif
#define rep(i, a, b) for(int i(a); i <= b; ++ i)
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 11;

ll tr[N][N][N][N][N][N];

void add(int a[], ll v) {
  for(int i1 = a[0]; i1 <= 10; i1 += (i1 & -i1)) {
    for(int i2 = a[1]; i2 <= 10; i2 += (i2 & -i2)) {
      for(int i3 = a[2]; i3 <= 10; i3 += (i3 & -i3)) {
        for(int i4 = a[3]; i4 <= 10; i4 += (i4 & -i4)) {
          for(int i5 = a[4]; i5 <= 10; i5 += (i5 & -i5)) {
            for(int i6 = a[5]; i6 <= 10; i6 += (i6 & -i6)) {
              tr[i1][i2][i3][i4][i5][i6] += v;
            }
          }
        }
      }
    }
  }
}

ll sum(int a[], ll ret = 0) {
  for(int i1 = a[0]; i1 > 0; i1 -= (i1 & -i1)) {
    for(int i2 = a[1]; i2 > 0; i2 -= (i2 & -i2)) {
      for(int i3 = a[2]; i3 > 0; i3 -= (i3 & -i3)) {
        for(int i4 = a[3]; i4 > 0; i4 -= (i4 & -i4)) {
          for(int i5 = a[4]; i5 > 0; i5 -= (i5 & -i5)) {
            for(int i6 = a[5]; i6 > 0; i6 -= (i6 & -i6)) {
              ret += tr[i1][i2][i3][i4][i5][i6];
            }
          }
        }
      }
    }
  } 
  return ret;
}

constexpr int M = 1000010;

void solve() {
  int n; cin >> n;
  // vector<string> a(n);
  vector<int> cnt(M);

  for(int i = 0; i < n; i ++ ) {
    int x; cin >> x; cnt[x] ++;
  } 
  for(int i = 0; i < M; i ++ ) if(cnt[i]) {
    int b[6]; int x = i;
    for(int j = 5; j >= 0; j -- ) {
      b[j] = x % 10 + 1;
      x /= 10;
    }
    add(b, cnt[i]);
  }
  
  ll ans = 0;
  for(int i = 0; i < M; i ++ ) if(cnt[i]) {
    int b[6]; int x = i;
    for(int j = 5; j >= 0; j -- ) {
      b[j] = x % 10 + 1;
      x /= 10;
    }
    bool flag = true;
    for(int j = 5; j >= 0; j -- ) {
      if(b[j] + b[j] - 2 > 9) {
        flag = false;
      }
    }
    if(flag) ans += 1ll * cnt[i] * (cnt[i] - 1) / 2; //
    add(b, -cnt[i]);
    for(int j = 5; j >= 0; j -- ) {
      b[j] = 11 - b[j];
    }
    ans += sum(b) * cnt[i];
  }

  cout << ans << "\n";


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
