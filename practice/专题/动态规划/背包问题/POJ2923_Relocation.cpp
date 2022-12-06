#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
// #include <functional>
// #include <unordered_set>
// #include <unordered_map>

using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)

//#define int long long 
#define ios ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define all(v) (v).begin(),(v).end()

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

namespace TLE {
  const int N = 11;

  int w[N], w1[N], w2[N];
  int f1[1 << N], f2[1 << N];

  void solve(int test) {
    int n, c1, c2; cin >> n >> c1 >> c2;
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    
    int ans = 1E9;

    for (int i = 0; i < 1 << n; i ++ ) {
      int m1 = 0, m2 = 0;
      for (int j = 0; j < n; j ++ ) if(i >> j & 1) {
        w1[m1 ++ ] = w[j];
      } else {
        w2[m2 ++ ] = w[j];
      }
      memset(f1, 0x3f, sizeof f1);
      memset(f2, 0x3f, sizeof f2);
      f1[0] = 0;
      for (int j = 1; j < 1 << m1; j ++ ) {
        int sum = 0;
        for (int k = 0; k < m1; k ++ ) if (j >> k & 1) {
          sum += w1[k];
        }
        if (sum <= c1) f1[j] = 1;
        for (int k = j; k; k = ((k - 1) & j)) {
          chkmin(f1[j], f1[k] + f1[j ^ k]);
        }
      } 
      f2[0] = 0;
      for (int j = 1; j < 1 << m2; j ++ ) {
        int sum = 0;
        for (int k = 0; k < m2; k ++ ) if (j >> k & 1) {
          sum += w2[k];
        }
        if (sum <= c2) f2[j] = 1;
        for (int k = j; k; k = ((k - 1) & j)) {
          chkmin(f2[j], f2[k] + f2[j ^ k]);
        }
      }
      chkmin(ans, max(f1[(1 << m1) - 1], f2[(1 << m2) - 1]));
    }

    cout << "Scenario #" << test << ":\n";
    cout << ans << "\n\n";

  }

}

namespace Nanfeng {
  const int N = 11;

  int w[N];
  int f1[1 << N], f2[1 << N];
  int sum[1 << N];

  void solve(int test) {

    int n, c1, c2; cin >> n >> c1 >> c2;
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < 1 << n; i ++ ) {
      for (int j = 0; j < n; j ++ ) if (i >> j & 1) {
        sum[i] += w[j];
      }
    }

    memset(f1, 0x3f, sizeof f1);
    memset(f2, 0x3f, sizeof f2);
    
    f1[0] = f2[0] = 0;

    for (int i = 1; i < 1 << n; i ++ ) {
      if (sum[i] <= c1) f1[i] = 1;
      if (sum[i] <= c2) f2[i] = 1;
      for (int j = i; j; j = (j - 1) & i) {
        chkmin(f1[i], f1[j] + f1[i ^ j]);
        chkmin(f2[i], f2[j] + f2[i ^ j]);
      }
    }  

    int ans = 1E9;
    int p = (1 << n) - 1;

    for (int i = 0; i < 1 << n; i ++ ) {
      // debug(f1[i], f2[p ^ i]);
      chkmin(ans, max(f1[i], f2[p ^ i]));
    }

    cout << "Scenario #" << test << ":\n";
    cout << ans << "\n\n";

  }
}


int main() {
  ios;
  int T; cin >> T;
  for (int test = 1; test <= T; test ++ ) Nanfeng::solve(test);
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
