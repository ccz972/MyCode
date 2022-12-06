// Little Tiger vs. Deep Monkey 
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
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

//#define int long long 
#define all(v) (v).begin(),(v).end()
 
void solve() {
  int n; cin >> n;
  double p; cin >> p;
  int m = n * 1000 + 1;
  int sum = 0;
  vector<double> f(m);
  f[0] = 1;
  for (int i = 0; i < n; i ++ ) {
    int x; cin >> x; sum += x;
    auto g = f; for (int j = 0; j < m; j ++ ) g[j] /= 2;
    for (int j = 0; j + x < m; j ++ ) {
      g[j + x] += f[j] * 0.5; 
    }
    f = g;
  }
  //有p的概率使得A的分数不低于B
  //那么至少有p * sum{} 中方案是小于等于 A 的分数的
  //f[j] 表示
  double ans = 0;
  // for (int i = 0; i < 10; i ++ ) {
  //   cout << f[i] << " \n"[i == 9];
  // }
  for (int i = 0; i < m; i ++ ) {
    ans += f[i]; 
    if (ans >= p) {
      cout << i << "\n";
      return ;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
  int T; cin >> T;
  while (T -- ) solve(); 
  return 0;
}
 