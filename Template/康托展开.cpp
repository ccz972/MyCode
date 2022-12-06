#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
康托展开用于求一个排列在所有 1 ~ n的排列间的字典序排名。
其实康托展开的原理很简单。设有排列p= a102 ...an，那么对任意字典序比p小的排列，一
定存在i，使得其前i-1(1<i<n)位与p对应位相同，第i位比p;小，后续位随意。于
是对于任意i，满足条件的排列数就是从后n- i + 1位中选一个比ai小的数、并将剩下
n-i个数任意排列的方案数,即为A_i * (n-i)!(Ai表示ai后面比a;小的数的个数)。
遍历i即得总方案数>: \sum_{i=1}^{n-1}  Ai * (n- i)!,再加1即为排名。

*/
constexpr int MAXN = 1E5 + 10;

namespace Nanfeng_Ktzk_brute {
  ll fact[MAXN] = {1}, P[MAXN], A[MAXN];  // fact需要在外部初始化
  ll cantor(int P[], int n)               // 这里传入的P是1-index数组
  {
    ll ans = 1;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (P[j] < P[i]) A[i]++;

    for (int i = 1; i < n; i++) ans += A[i] * fact[n - i];
    return ans;
  }
}

namespace Nanfeng_Ktzk_bit {
  #define MOD 1000000007
  ll fact[MAXN] = {1}, P[MAXN], A[MAXN], tree[MAXN];
  ll lowbit(ll x) { return x & -x; }
  ll query(ll x)
  {
      ll ans = 0;
      for (int i = x; i >= 1; i -= lowbit(i))
          ans += tree[i];
      return ans;
  }
  void update(ll x, ll d)
  {
      for (int i = x; i < MAXN; i += lowbit(i))
          tree[i] += d;
  }
  ll cantor(int P[], int n)
  {
      ll ans = 1;
      for (int i = n; i >= 1; i--)
      {
          A[i] = query(P[i]);
          update(P[i], 1);
      }
      for (int i = 1; i < n; i++)
          ans = (ans + A[i] * fact[n - i]) % MOD;
      return ans;
  }
}



