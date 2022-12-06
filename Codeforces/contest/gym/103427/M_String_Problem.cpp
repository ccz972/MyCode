// https://ac.nowcoder.com/acm/contest/41745/C

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

const int N = 1e6 + 10, L = 20;

int n, m, p, rk[N], oldrk[N << 1], cnt[N], id[N], sa[N], f[N][L];
int Log[N], height[N];
char s[N];
int ans[N];

bool inline cmp(int i, int j, int k) {
  return oldrk[i] == oldrk[j] && oldrk[i + k] == oldrk[j + k];
}

void inline SA() {
  m = 300 + 5; // 字符集大小
  for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
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

void solve() {
  scanf("%s", s + 1); n = strlen(s + 1);
  s[++ n] = '#';
  SA();
  
  //最大的后缀
  int r = n;
  
  for (int i = n; i >= 1; i -- ) {
    if (sa[i] < r) {
      ans[sa[i]] = 1;
      r = sa[i];
      // debug(sa[i]);
    }
  }


  r = 1;
  cout << "1 1\n";
  for (int i = 2; i <= n - 1; i ++ ) {
    if (ans[i]) {
      r = i;
    }
    cout << r << " " << i << "\n";
  }

}
int main() {
  solve();
  return 0;
}



