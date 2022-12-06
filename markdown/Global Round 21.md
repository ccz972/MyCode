#! https://zhuanlan.zhihu.com/p/534555357

### [A. NIT orz!](https://codeforces.com/contest/1696/problem/A)

$Tag$ : 贪心

注意到操作只会用一次，遍历整个数组即可

### CODE

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for(int &x: a) {
      cin >> x;
      ans = max(ans, x | k);
    }
    cout << ans << "\n";
  }
}
```


## [B. NIT Destroys the Universe](https://codeforces.com/contest/1696/problem/B)

$Tag$ : Two points, 贪心

注意到，最多选两次全部的就可以把全部的都变为0，因此答案最多是 $2$ ，然后考虑不选全部的，我们对于每一个非零段，都可以通过一次操作来把这一段变为 $0$ ，因此双指针枚举即可。

### CODE

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int cnt = 0;
    for(int i = 0; i < n; i ++ ) if(a[i] != 0) {
      int j = i;
      while(j + 1 < n && a[j + 1] != 0) {
        ++ j;
      }
      cnt ++;
      i = j;
    }
    cout << min(cnt, 2) << "\n";  
  }
}
```


## [C. Fishingprince Plays With Array](https://codeforces.com/contest/1696/problem/C)

$Tag$ : 贪心

对于一个数组，他的最小分解是确定的，因此我们可以通过把两个数组都分解为不可分解的数组，然后判断两个数组是否相同就可以判断两个数组是否可以相互转化。

### CODE

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<array<int, 2> > A;

    for(int &x: a) {
      cin >> x;
      int cnt = 1;
      while(x % m == 0) {
        x /= m;
        cnt *= m;
      }
      if(A.empty()) {
        A.push_back({x, cnt});
      } else {
        if(x == A.back()[0]) {
          A.back()[1] += cnt;
        } else {
          A.push_back({x, cnt});
        }
      }
    }
    int k; cin >> k;
    vector<int> b(k);
    vector<array<int, 2> > B;
    for(int &x: b) {
      cin >> x;
      int cnt = 1;

      while(x % m == 0) {
        x /= m;
        cnt *= m;
      }

      if(B.empty()) {
        B.push_back({x, cnt});
      } else {
        if(x == B.back()[0]) {
          B.back()[1] += cnt;
        } else {
          B.push_back({x, cnt});
        }
      }
    }

    if(A == B) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

```

## [D. Permutation Graph](https://codeforces.com/contest/1696/problem/D)

$Tag$ : 贪心，二分，$ST$ 表，单调栈

### SOLUTION

每次贪心的走最远的一定是对的。

我们考虑 $[1,n]$ 的最大值以及最小值，一定是要经过的，假设最大值、最小值的下标分别为 $idx_{max}, idx_{min}（idx_{max} < idx_{min}）$ ，那么我们的路径一定是 $[1,idx_{max}], [idx_{max}, idx_{min}], [idx_{min},n]$ 然后问题转化为 $[1, idx_{max}]$ 以及 $[idx_{min}, n]$  ，因此我们每次跳最远的一定更优。

#### 实现一：单调栈、二分

考虑计算出到达每个位置的最小次数$dist_i$ ， $dist_1=0$，然后枚举 $[2,n]$ 
- 如果 $a_i > a_{i-1}$ , 那么我们跳到 $i$ 的位置一定是比 $a_i$ 小的位置，并且我们需要找到 $[1,i-1]$ 中距离 $i$ 最远的 。并且这个位置要比大于 $a_i$ 的位置 大(下标大)，因此我们可以考虑单调栈上二分找到这个位置
- 如果$a_i < a_{i-1}$, 那么我们跳到 $i$ 的位置一定是比 $a_i$ 大的位置，并且我们需要找到 $[1,i-1]$ 中距离 $i$ 最远的 。并且这个位置要比小于 $a_i$ 的位置 (下标大)，因此我们可以考虑单调栈上二分找到这个位置

### CODE
```cpp
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 10;

int n;
int a[N], stk[2][N], top[2];
int dis[N];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  top[0] = top[1] = 0;
  for(int i = 1; i <= n; i ++ ) {
    while(top[0] > 0 && a[stk[0][top[0]]] < a[i]) {
      -- top[0];
    }
    stk[0][++ top[0]] = i;
    while(top[1] > 0 && a[stk[1][top[1]]] > a[i]) {
      -- top[1];
    }
    stk[1][++ top[1]] = i;

    if(i == 1)  {
      dis[i] = 0;
    } else {
      int r = (a[i - 1] < a[i]);
      //如果 a_{i-1} < a_i 那么 a_i 肯定是由比 a_i 小的值转移过来，并且下标要大于距离 a_i 最近的大于 a_i 的下标
      dis[i] = dis[*upper_bound(stk[r] + 1, stk[r] + top[r] + 1, stk[r ^ 1][top[r ^ 1] - 1])] + 1;
    }

  }
  cout << dis[n] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();

  return 0;
}
```


#### 实现二：ST表、二分

预处理出一个 $ST$ 表，每次往右一直跳最远的即可

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    maxv.resize(n); minv.resize(n);
    maxvid.resize(n); minvid.resize(n);
    int m = __lg(n) + 1;
    for(int i = 0; i < n; i ++ ) maxv[i].resize(m), minv[i].resize(m),maxvid[i].resize(m), minvid[i].resize(m);
    for(int i = 0; i < n; i ++ ) maxv[i][0] = minv[i][0] = a[i],maxvid[i][0] = minvid[i][0] = i;
    for(int j = 1; j < m; j++) {
      for(int i = 0; i <= n - (1 << j); i++) {
        maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
        minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
        maxvid[i][j] = a[maxvid[i][j - 1]] > a[maxvid[i + (1 << (j - 1))][j - 1]] ? maxvid[i][j - 1] : maxvid[i + (1 << (j - 1))][j - 1];
        minvid[i][j] = a[minvid[i][j - 1]] < a[minvid[i + (1 << (j - 1))][j - 1]] ? minvid[i][j - 1] : minvid[i + (1 << (j - 1))][j - 1];
      }
    }
  }
  T getmax(int l,int r){
    int k = __lg(r - l + 1);
    return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
  }    
  T getmin(int l,int r){
    int k = __lg(r - l + 1);
    return min(minv[l][k], minv[r - (1 << k) + 1][k]);
  }    
  T getmaxid(int l,int r){
    int k = __lg(r - l + 1);
    return a[maxvid[l][k]] > a[maxvid[r - (1 << k) + 1][k]] ? maxvid[l][k] : maxvid[r - (1 << k) + 1][k];
  }    
  T getminid(int l,int r){
    int k = __lg(r - l + 1);
    return a[minvid[l][k]] < a[minvid[r - (1 << k) + 1][k]] ? minvid[l][k] : minvid[r - (1 << k) + 1][k];
  }    
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
  vector<vector<T>> maxvid, minvid;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    ST st(a, n);

    int cnt = 0;
    for(int i = 0; i < n;  ) {
      int l = i, r = n - 1;
      while(l < r) {
        int mid = (l + r + 1) / 2;
        int mx = st.getmax(i, mid); 
        if(a[i] >= mx) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      int rmx1 = st.getminid(i, l);
      l = i, r = n - 1;

      while(l < r) {
        int mid = (l + r + 1) / 2;
        int mi = st.getmin(i, mid); 
        if(a[i] <= mi) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      int rmx2 = st.getmaxid(i, l);

      cnt ++;

      i = max(rmx1, rmx2);
      if(i == n - 1) break;
    }
    cout << cnt << "\n";
    
  }
}
```


## [E. Placing Jinas](https://codeforces.com/contest/1696/problem/E)

由于 $a_0 \ge a_1 \ge a_2 \ge ... \ge a_n$ ，所以每个位置 $(i,j)$ 都可以由 $(i-1,j)$ 和 $(i,j-1)$ 转移过来， 因此到每个白色细胞 $(i, j)$ 的个数为 $C_{i+j}^{i}$ , 所以问题转化为了求所有的细胞的个数和。

对于每一个 $a_i$， 这一列的所有的个数和为 
$$
f_i = C_{i}^{i} + C_{i+}^{i} + C_{i+2}^{i} + ... + C_{i+a[i]-1}^{i} = C_{i}^{0} + C_{i+1}^{1} + C_{i+2}^{2} + ... + C_{i+a[i]-1}^{a[i]-1}
$$
由于  $\sum_{i=0}^{k} \binom{n+i}{i} = \binom{n+k+1}{n+1}$
因此  $f_i = \binom{i+a_i}{i+1}$ 

### CODE

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

inline int mod(int x) {return x >= MOD ? x - MOD : x;}

inline int ksm(int a, int b) {
  int ret = 1; a = mod(a);
  for(; b; b >>= 1, a = 1LL * a * a % MOD) if(b & 1) ret = 1LL * ret * a % MOD;
  return ret;
}

template<int MOD> 
struct modint {
  int x;
  modint() {x = 0; }
  modint(int y) {x = y;}
  inline modint inv() const { return modint{ksm(x, MOD - 2)}; }
  explicit inline operator int() { return x; }
  friend inline modint operator + (const modint &a, const modint& b) { return modint(mod(a.x + b.x)); }
  friend inline modint operator - (const modint &a, const modint& b) { return modint(mod(a.x - b.x + MOD)); }
  friend inline modint operator * (const modint &a, const modint& b) { return modint(1ll * a.x * b.x % MOD); }
  friend inline modint operator / (const modint &a, const modint& b) { return modint(1ll * a.x * b.inv().x % MOD); }
  friend inline modint operator - (const modint &a) { return modint(mod(MOD - a.x)); }
  friend inline modint& operator += (modint &a, const modint& b) { return a = a + b; }
  friend inline modint& operator -= (modint &a, const modint& b) { return a = a - b; }
  friend inline modint& operator *= (modint &a, const modint& b) { return a = a * b; }
  friend inline modint& operator /= (modint &a, const modint& b) { return a = a / b; }
  friend auto &operator >> (istream &i, modint &a) {return i >> a.x; }
  friend auto &operator << (ostream &o, const modint &z) { return o << z.x; }
  inline bool operator == (const modint &b) { return x == b.x; }
  inline bool operator != (const modint &b) { return x != b.x; }
  inline bool operator < (const modint &a) { return x < a.x; }
  inline bool operator <= (const modint &a) { return x <= a.x; }
  inline bool operator > (const modint &a) { return x > a.x; }
  inline bool operator >= (const modint &a) { return x >= a.x; }
  
};

typedef modint<MOD> mint;

inline mint ksm(mint a, int b) {
	mint ret = 1; 
	for(; b; b >>= 1, a = a * a ) if(b & 1) ret = ret * a ;
	return ret;
}

const int N = 4e5 + 10;

mint fact[N + 1], infact[N + 1], inv[N + 1];

mint C(int a, int b) {
  if(b > a) return 0;
  return fact[a] * infact[b] * infact[a - b];
}

void init() {
  fact[0] = 1; for(int i = 1; i <= N; ++ i ) { fact[i] = fact[i - 1] * i; }
  infact[N] = ksm(fact[N], MOD - 2); for(int i = N - 1; i >= 0; -- i ) infact[i] = infact[i + 1] * (i + 1);
  inv[0] = inv[1] = 1; for(int i = 2; i <= N; ++ i) inv[i] = inv[MOD % i] * (MOD - MOD / i);
}

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
ll read() {
  ll x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
string read_s() {
  string str;
  char c = get_char();
  while (c == ' ' || c == '\n' || c == '\r') c = get_char();
  while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
  return str;
}
void print(int x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 | '0');
}
void println(int x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(ll& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // 
using namespace io;
ll a[N];
int main() {
  init();
  ll n = read();
  mint ans = 0;
  for(int i = 0; i <= n; i ++ ) {
    a[i] = read();
  }
  for(int i = 0; i <= n; i ++ ) {
    ans += C(i + a[i], i + 1);
  }
  cout << ans << "\n";
  return 0;
}
```


