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

void solve() {

  /** 居然做到G了，book思意
   * 题意是给了两个数字 N 和 M (1 <= N, M <= 10^7)
   * 求满足条件的，长度为 N 的序列个数(mod 998244353)
   * 满足 1 <= a_1 <= a_2 <= .... <= a_n <= M
   * 并且相邻的两个数字 a_i 和 a_{i+1} 需要满足 mod 3 不相等
   * 不会写qwq 
  */

  /*
  提议转化为构造一个数组b
  b_i >= 0
  且 b2, b3, ... bn mod 3 为 1 或者 2
  \sum_b_i <= m
  */
 

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}