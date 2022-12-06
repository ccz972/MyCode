/*

gcd(a, b) = a + b - 2 * (a & b) = a ^ b = x
k_1 x + k_2 x - 2 * (a & b) = x



a + b - gcd(a, b) = 2 * (a & b)


每个圆的圆心都在 x 轴上
x 轴上所有圆上的点的范围是 [0, n]
每个圆的半径不超过5，并且是正整数
每两个圆至多有 1 个交点

给定 n(n >= 2),   k (maybe 0) 个点(保证此时满足条件) ，你可以再添加一些点(maybe 0)，求不同的合法情况的方案数



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt = 0;
  for (int i = 1; i <= 20000; i ++ ) {
    for (int j = 1; j <= 20000; j ++ ) {
      cnt += (__gcd(i, j) == (i ^ j));
    }
  }
  cout << cnt << "\n";
  return 0;
}