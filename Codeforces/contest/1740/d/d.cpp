#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, L = 20;

int n, m, p, rk[N], oldrk[N << 1], cnt[N], id[N], sa[N], f[N][L];
int Log[N], height[N];
char s[N];

/** 一些约定
*  下标从 1 开始，长度为 n
*  后缀 i 表示以第 i 个字符 开头的后缀，存储时用 i 表示字符串 s 的后缀 s[i...n]
*  sa[i] 表示将所有后缀排序后第 i 小的后缀的编号，也是所说的后缀数组，后文也称编号数组 sa
*  rk[i] 表示 后缀 i 的排名，也是重要的辅助数组，后文也称排名数组 rk 
*  这两个数组满足性质： sa[rk[i]] = rk[sa[i]] = i
*/

/**
* height[i] = lcp(sa[i], sa[i - 1]) 即第i名的后缀与它前一名的后缀的最长公共前缀 
* height[1] 可视为 0
*/

/**
* 引理: height[rk[i]] >= height[rk[i - 1]] - 1 
* lcp(sa[i], sa[j]) = min{height[i + 1, .. j]}
* 有了这个定理，求两子串最长公共前缀就转化为了 RMQ 问题。 
*/

/**
* 假设需要比较 A = S[a...b],和 B = S[c...d] 的大小关系 
* 若lcp(a,c) >= min(|A|, |B|), A < B  <==> |A| < |B|
* 否则: A < B <==> rk[a] < rk[c]
*/

/** 不同子串的数目
*  子串就是后缀的前缀，所以可以枚举每个后缀，计算前缀总数，再减掉重复。
* “前缀总数” 其实就是子串个数，为 n * (n + 1) / 2 。
* 如果按后缀排序的顺序枚举后缀，每次新增的子串就是除了与上一个后缀的 LCP 剩下的前缀。
* 这些前缀一定是新增的，否则会破坏 lcp(sa[i], sa[j]) = min{height[i + 1, .. j]} 的性质
* 只有这些前缀是新增的，因为 LCP 部分在枚举上一个前缀时计算过了。
* 因此答案为： n * (n + 1) / 2 - \sum_{i=2}^{n} height[i]
*/

/** 出现至少 k 次的子串的最大长度
*  出现至少 k 次意味着后缀排序后有至少连续  个后缀以这个子串作为公共前缀。
*  所以，求出每相邻 k-1 个 height 的最小值，再求这些最小值的最大值就是答案。
*  可以使用单调队列 O(n)  解决，但使用其它方式 (multiset<int> ) 也足以 AC。 
* 
*/

/** 是否有某字符串在文本串中至少不重叠地出现了两次
*  可以二分目标串的长度 |s| ，将 h 数组划分成若干个连续 LCP 大于等于 |s|  的段
*  利用 RMQ 对每个段求其中出现的数中最大和最小的下标，若这两个下标的距离满足条件
*  则一定有长度为 |s| 的字符串不重叠地出现了两次。
*/

bool inline cmp(int i, int j, int k) {
  return oldrk[i] == oldrk[j] && oldrk[i + k] == oldrk[j + k];
}

void inline SA() {
  m = 1e3; // 字符集大小
  for (int i = 1; i <= n; i++) cnt[rk[i] = 300 - s[i]]++;
  for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; i++) sa[cnt[rk[i]]--] = i;
  for (int w = 1; w < n; w <<= 1, m = p) {
  p = 0;
  for (int i = 1; i <= n; i++)
    if (sa[i] > w) id[++p] = sa[i] - w;
  for (int i = n; i > n - w; i--) id[++p] = i;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) cnt[rk[i]]++, oldrk[i] = rk[i];
  for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i; i--) sa[cnt[rk[id[i]]]--] = id[i];
  p = 0;
  for (int i = 1; i <= n; i++)
    rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  if (p == n) break;
  }
  for (int i = 1; i <= n; i++) {
    int j = sa[rk[i] - 1], k = max(0, height[rk[i - 1]] - 1);
    while (s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}

void ST_prework() {
  for (int i = 1; i <= n; i++) {
    f[i][0] = height[i], Log[i] = log2(i);
  }
  for (int j = 1; j <= Log[n]; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int inline query(int l, int r) {
  l = rk[l], r = rk[r];
  if (l > r) swap(l, r);
  l++;
  int k = Log[r - l + 1];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int q[N];
int hh = 1, tt;

int main() {
  scanf("%s", s + 1); n = strlen(s + 1);
  SA(); ST_prework();
  for (int i = 1; i <= n; i++) {
    if (i == 1 || rk[i] < rk[q[tt]]) q[++tt] = i;
    while (hh < tt && q[hh + 1] + query(q[hh], q[hh + 1]) <= i) hh++;
    printf("%d %d\n", q[hh], i);
  }
  return 0;
}

