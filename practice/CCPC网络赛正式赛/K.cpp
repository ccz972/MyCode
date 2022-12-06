#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int q;
ll y, seed;




void solve() {
  cin >> y >> q >> seed;
  int T = 5000;
  int error = 0;
  if (q > 50) {
    while (T -- ) {
      if (error != 0)
        cout << endl << endl;
      cout << y; 
      int x; cin >> x;
      if (x == 2) {
        break;
      }
      ++ error;
    }
  } else {
    vector<ll> a{y, y * 2, y * 100000};
    while (T -- ) {
      int Rand = rnd() % 3;
      if (error != 0)
        cout << endl << endl;
      cout << a[Rand];
      int x; cin >> x;
      if (x == 2) {
        break;
      }
      ++ error;
    }
  }
  // 至少要赢回 y 元，赢的概率是 q， seed 是种子
  // 返回 0 代表 这一轮输了，返回 1 代表这一轮赢了，但是没赢够 y 元
  // 返回 2 赢够了 y 元


  // 输出一个数字 [1, 10^{700}] ，表示买多少钱的彩票
  // 最多参与5000轮彩票



}

int main() {
  solve();
}