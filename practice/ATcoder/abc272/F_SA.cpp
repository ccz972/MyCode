#include <bits/stdc++.h>
#define fi first
#define se second
#define mm(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define ls (u << 1)
#define rs (u << 1 | 1)
#define PI acos(-1)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
const int N = 800005;
int n, m = 128;
char s[N], t[N];
int id[N], rk[N], sa[N], cnt[N], p;
void SA() {
  for (int i = 1; i <= n; i++) rk[i] = s[i], cnt[rk[i]]++;
  for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
  for (int k = 1;; k <<= 1, m = p, p = 0) {
    for (int i = n; i > n - k; i--) id[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > k) id[++p] = sa[i] - k;
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
    p = 0;
    memcpy(id, rk, sizeof(id));
    for (int i = 1; i <= n; i++) {
      if (id[sa[i]] == id[sa[i - 1]] && id[sa[i] + k] == id[sa[i - 1] + k])
        rk[sa[i]] = p;
      else
        rk[sa[i]] = ++p;
    }
    if (p == n) break;
  }
}
int sum[N], tem;
int main() {
  cin >> n;
  scanf("%s%s", s + 1, t + 1);
  tem = n;
  for (int i = 1; i <= n; i++) s[i + n] = s[i];
  n *= 2;
  s[++n] = 'a' - 1;
  for (int i = 1; i <= tem; i++) s[++n] = t[i];
  for (int i = 1; i <= tem; i++) s[++n] = t[i];
  s[++n] = 'z' + 1;
  SA();
  for (int i = 1; i <= tem * 2 + 1; i++) sum[rk[i]]++;
  for (int i = n - tem; i <= n; i++) sum[rk[i]]++;
  for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
  LL res = 0;
  for (int i = 1; i <= tem; i++) res += tem - (rk[i] - 1 - sum[rk[i] - 1]);
  cout << res << endl;
  return 0;
}