## 题意

给定一个排列 $a$ ， $q$ 次操作，求出每次操作后的冒泡排序的次数，对 $10$ 取模。

操作有两种：

1. 将整个数组翻转
2. 将第一个数字放到最后一个位置

## SOLUTION

首先考虑如果每次询问独立，应该怎么算？ 假设操作前的答案为 `ans`

1. 将整个序列翻转，原来的正序对变为逆序对，逆序对变为正序对，那么操作后的逆序对数是 $n \times (n - 1) / 2 - ans$ 。
2. 由于序列是一个排列，那么把一个数字 $x$ 从开头移除，减少的逆序对数就是 $x - 1$，然后放到末尾，增加的逆序对数就是 $n - x$。

发现两种操作都是可以 $O(1)$ 计算的，并且只需要知道开头和末尾的数字，以及序列的方向。因此我们可以用数组模拟一个双端队列，模拟操作即可。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define ay3 array<int, 3>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 


constexpr int N = 5E6 + 10;
constexpr int mid = 1E6 + 10;
int n, m;
int q[N];

class fenwick {
public:
  vector<int> fenw;
  int n;
  fenwick(int _n): n(_n) {
    fenw.resize(n);
  }
  void modify(int x, int v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  int get(int x) {
    int v = 0;
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

void solve() {
  cin >> n >> m;
  
  rep(i, 1, n) cin >> q[i + mid];
  int hh = 1 + mid, tt = n + mid;
  int flag = 1; // left

  string s; cin >> s;

  fenwick fen(n + 20);

  ll ans = 0;

  rep(i, 1, n) {
    ans += fen.get(n + 1) - fen.get(q[i + mid]);
    fen.modify(q[i + mid], 1);
  }

  vector<int> res(m);

  ll sum = 1ll * n * (n - 1) / 2;

  cout << ans << "\n";

  Rep(i, 0, m) {
    if (s[i] == 'S') {
      if (flag) {
        int now = q[hh ++ ];
        q[++ tt] = now;
        ans -= now - 1;
        ans += n - now;
      } else {
        int now = q[tt --];
        q[-- hh] = now;
        ans -= now - 1;
        ans += n - now;
      }
      res[i] = ans % 10;
    } else if (s[i] == 'R') { 
      flag ^= 1;
      ans = sum - ans;
      res[i] = ans % 10;
    } else {
      assert(false);
    }
  }
  Rep(i, 0, m) {
    cout << res[i];
  }


}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}
```

