#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
/*
题意：有个人想抢银行。有 n 个银行，抢劫银行 i 可以得到银行的储蓄金额 c [i]，并且有 w [i] 的概率被捕。给
出概率 p，要求出在被抓概率小于 p 的情况下，能够得到的最大金额数。  
*/

/*
考虑01背包，将金额数视为体积
求出体积为 j 的时候的不被抓的最大概率

f[j] >= 1 - p 则 j 符合答案

*/
void solve() {
  double p; int n;
  cin >> p >> n; // 被抓概率小于 p，即不被抓概率大于 1 - p
  vector<double> f(10010);
  f[0] = 1;
  for (int i = 1; i <= n; i ++ ) {
    int v; double w; cin >> v >> w;
    for (int j = 10000; j - v >= 0; j -- ) {
      chkmax(f[j], f[j - v] * (1.0 - w));
    }
  }
  for (int j = 10000; j >= 0; j -- ) if(f[j] >= 1.0 - p) {
    cout << j << "\n";
    return ;
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
