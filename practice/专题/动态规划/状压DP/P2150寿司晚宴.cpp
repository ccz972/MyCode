#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int p[8] = {2, 3, 5, 7, 11, 13, 17, 19};
constexpr int N = 510;
constexpr int M = 1 << 9;
struct node {
  int val, big, S;
  void init(int _val) {
    val = _val;
    int res = val; big = -1;
    for (int i = 0; i < 8; i ++ ) if (res % p[i] == 0) {
      S |= 1 << i;
      while (res % p[i] == 0) res /= p[i];
    }
    if(res != 1) big = res;
  }
  bool operator < (const node &T) const {
    return big < T.big;
  }
} a[N];

ll dp[M][M], f1[M][M], f2[M][M];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, p; cin >> n >> p;

  for (int i = 1; i < n; i ++ ) {
    a[i].init(i + 1);
  }

  //由于由于22以上的质数在每个数字中最多出现一次
  //那么我们单独考虑这些质因子
  //因为过了这一段之后讨论的就不是这个大质数了
  //因此可以按照每个数字的大质数排序分开讨论即可

  sort(a + 1, a + n);

  dp[0][0] = 1;

  for (int i = 1; i < n; i ++ ) {
    if(i == 1 || a[i].big == -1 || a[i].big != a[i - 1].big ) {
      memcpy(f1, dp, sizeof f1);
      memcpy(f2, dp, sizeof f2);
    }

    for (int j = 255; j >= 0; j -- ) {
      for (int k = 255; k >= 0; k -- ) {
        if(j & k) continue;
        ll &ret1 = f1[j | a[i].S][k];
        ll &ret2 = f2[j][k | a[i].S];
        if((a[i].S & k) == 0) ret1 += f1[j][k];
        if((a[i].S & j) == 0) ret2 += f2[j][k];
        while(ret1 >= p) ret1 -= p;
        while(ret2 >= p) ret2 -= p;
      }
    }

    if(i == n - 1 || a[i].big == -1 || a[i].big != a[i + 1].big) {
      for (int j = 0; j <= 255; j ++ ) {
        for (int k = 0; k <= 255; k ++ ) {
          if(j & k) continue;
          ll &ret = dp[j][k];
          // - ret 是因为要去重，f1[j][k] 和 f2[j][k] 中都包含a[i]不选的情况
          ret = f1[j][k] + f2[j][k] + p - ret;
          while(ret >= p) ret -= p;
        }
      }
    }

  }

  ll ans = 0;

  for(int i = 0; i <= 255; i ++ ) {
    for(int j = 0; j <= 255; j ++ ) if((j & i) == 0) {
      ans += dp[i][j];
      while(ans >= p) ans -= p;
    }
  }


  cout << ans << "\n";
  

  return 0;
}