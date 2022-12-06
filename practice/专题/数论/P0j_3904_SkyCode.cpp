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

using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

typedef long long ll;
#define ios ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define all(v) (v).begin(),(v).end()

using namespace std;

const int N = 1E4 + 10;

int n, m;
int cnt[N]; // 表示所给数据中包含因子i的个数
int num[N]; // 表示所给数据中，因子 i 有几个不同的素因子
ll C[N];
int prime[N];

void init() {
  for (int i = 4; i < N; i ++ ) {
    C[i] = 1ll * i * (i - 1) * (i - 2) * (i - 3) / 24;
  }
}

void divide(int n) {
  int tot = 0;
  for (int i = 2; i <= n / i; i ++ ) if (n % i == 0) {
    prime[tot ++ ] = i;
    while (n % i == 0) n /= i;
  }
  if (n > 1) prime[tot ++ ] = n;

  for (int i = 1; i < (1 << tot); i ++ ) {
    int tmp = 1;
    int sum = 0;
    for (int j = 0; j < tot; j ++ ) if (i >> j & 1) {
      tmp *= prime[j];
      sum ++;
    }
    cnt[tmp] ++; num[tmp] = sum;
  }
}

/**********************
 * 题目要求最大公因数为 1 的四元组的个数
 * 直接求互质不太好求，我们可以用总数减去不互质的个数
 * 考虑枚举公因数 d
 * 对于某个公因数 d , 如果含有 d 的数字有 cnt 个，那么可以构成的四元组为 C(cnt, 4)个
 * 由于直接算会算重复，比如 d = 6 的四元组一定被 d = 2 和 d = 3 都算过
 * 那么考虑容斥原理
 * 当某个公因数 d 的质因子有奇数个，那么答案就加上这个贡献
 * 当某个公因数 d 的质因子有偶数个，那么答案就减去这个贡献
 * 最终答案即是 C(n, 4) - 答案
**********************/

void solve() {
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i ++ ) {
    scanf("%d", &m);
    divide(m);
  }
  ll ans = 0;
  for (int i = 2; i < N; i ++ ) if (cnt[i] >= 4) {
    if (num[i] & 1) ans += C[cnt[i]];
    else ans -= C[cnt[i]];
    // printf("%d %d %lld\n", i, cnt[i], ans);
  }
  printf("%lld\n", C[n] - ans);
}

int main() {
  init(); 
  while (~scanf("%d", &n)) {
    solve();
  }
  return 0;
}
 