#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
typedef double db;
#define re _read
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) (int)v.size()
#define fi first
#define se second
#define pb push_back
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}
template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}
template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}
template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}
template <class T>
vector<vector<T>> Vector(int n, int m) {
  return vector<vector<T>>(n, vector<T>(m, 0));
}
template <class T>
vector<vector<vector<T>>> Vector(int i, int j, int k) {
  return vector<vector<vector<T>>>(i, vector<vector<T>>(j, vector<T>(k, 0)));
}
template <typename T>
void OUT(T *a, int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " ";
  puts("");
}
template <class T>
inline void _read(T &x) {
  static T ans;
  static unsigned int c;
  static bool p;
  for (c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar())
    ;
  if (c == '-')
    p = false, c = getchar();
  else
    p = true;
  for (ans = 0; c <= '9' && c >= '0'; c = getchar()) ans = ans * 10 + c - '0';
  x = p ? ans : -ans;
}
/*----------------------------------------------------------------------------------------------------*/
const int N = 5010;

/*-------------------------------------------------------------------------------------------------------------------*/
#define RMQ
const int maxn = N + 10;
struct SA {
#ifndef RMQ
  struct Segment_Tree {
#define ls u << 1
#define rs u << 1 | 1
    int min_val[maxn << 2];
    void pushup(int u) { min_val[u] = min(min_val[ls], min_val[rs]); }
    void build(int u, int l, int r, int *h) {
      if (l == r) {
        min_val[u] = h[l];
        return;
      }
      int mid = (l + r) >> 1;
      build(ls, l, mid, h), build(rs, mid + 1, r, h);
      pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (l > qr || ql > r) return 0x3f3f3f3f;
      if (ql <= l && r <= qr) return min_val[u];
      int mid = (l + r) >> 1;
      return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
    }
  } segtree;
#else
  int st[maxn][18], lg[maxn];
  void init_st() {
    for (int i = 2; i < maxn; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; ++i) st[i][0] = height[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 1; i <= (n - (1 << j) + 1); ++i) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
#endif
  /*height[i] = lcp(S[sa[i]],S[sa[i-1]]), h[i]=height[rk[i]], h[i]>=h[i-1]-1,
   * lcp(s[i],s[j])=min(height[rk[i]+1],...,height[rk[j]])*/
  int n, sa[maxn], rk[maxn], id[maxn], cnt[maxn], height[maxn], px[maxn];
  void clear() {
    for (int i = 1; i <= n; i++) sa[i] = rk[i] = id[i] = height[i] = px[i] = 0;
  }
  void get_sa(const char *s, int _n) {  // get sa and height
    n = _n;
    int m = 300, p = 0;  // m 是值域, 初始化为字符集大小
    for (int i = 0; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= n; ++i)
      cnt[rk[i] = (int)s[i]]++;  // 先对1个字符大小的子串进行计数排序
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
    for (int w = 1; w <= n;
         w <<= 1, m = p, p = 0) {  // m=p 就是优化计数排序值域
      for (int i = n - w + 1; i <= n; ++i)  // 第二关键字无穷小先放进去
        id[++p] = i;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > w)
          id[++p] = sa[i] - w;  // 顺次放入 s[sa[i]-w] 的第二关键字排名
      for (int i = 0; i <= m; ++i) cnt[i] = 0;
      for (int i = 1; i <= n; ++i) ++cnt[rk[i]], px[i] = rk[id[i]];
      for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
      for (int i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];
      for (int i = 1; i <= n; ++i) swap(rk[i], id[i]);
      rk[sa[1]] = p = 1;
      for (int i = 2; i <= n; ++i) {
        rk[sa[i]] =
            (id[sa[i]] == id[sa[i - 1]] && id[sa[i] + w] == id[sa[i - 1] + w]
                 ? p
                 : ++p);
      }
      if (p >= n) {  // 排名已经更新出来了
        break;
      }
    }
  }
  void get_height(const char *s) {
    for (int i = 1, k = 0; i <= n; ++i) {  // 获取 height数组
      if (k) --k;
      int j = sa[rk[i] - 1];
      while (s[i + k] == s[j + k]) ++k;
      height[rk[i]] = k;
    }
#ifdef _DEBUG
    for (int i = 1; i <= n; ++i)
      cout << "height[" << i << "] = " << height[i] << endl;
#endif
  }

  void init() {
#ifndef RMQ
    segtree.build(1, 1, n, height);
#else
    init_st();
#endif
  }
  int get_lcp(int x, int y) {
    int rkx = rk[x], rky = rk[y];
    if (rkx > rky) swap(rkx, rky);
    rkx++;
#ifndef RMQ
    int lcp = segtree.query(1, 1, n, rkx, rky);
#else
    int k = lg[(rky - rkx + 1)];
    int lcp = min(st[rkx][k], st[rky - (1 << k) + 1][k]);
#endif

#ifdef _DEBUG
    cout << "[getlcp] x=" << x << " y=" << y << " rkx=" << rkx << " rky=" << rky
         << " lcp=" << lcp << endl;
#endif
    return lcp;
  }
} sa;
/*-------------------------------------------------------------------------------------------------------------------*/

const int mod = 1e9 + 7;
ll dp[N][N], pre[N][N];

string s;
bool check(int l, int r) {
  int len = r - l;
  int LCP = sa.get_lcp(l, r);
  if (LCP >= len) return 0;
  return s[r + LCP] > s[l + LCP];
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  IOS;
  int n;
  cin >> n >> s;
  s = " " + s;
  sa.get_sa(s.c_str(), n);
  sa.get_height(s.c_str());
  sa.init();
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) pre[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (s[i - j + 1] != '0') {
        dp[i][j] = pre[i - j][j - 1];
        if (i - 2 * j + 1 >= 1 && check(i - 2 * j + 1, i - j + 1)) {
          dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
        }
      }
      // printf("dp[%d][%d]=%lld\n", i,j,dp[i][j]);
    }
    for (int j = 1; j <= n; j++) {
      pre[i][j] = (pre[i][j - 1] + dp[i][j]) % mod;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  printf("%lld\n", ans);

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}