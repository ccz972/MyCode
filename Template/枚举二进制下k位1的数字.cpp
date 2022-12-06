#include <bits/stdc++.h>
using namespace std;

void show_bit(int x) {
  for (int i = 8; i >= 0; i--) putchar('0' + (x >> i & 1));
  puts("");
}

int main() {
  int n = 10, k = 4;
  for (int cur = ((1 << n - k) - 1) ^ ((1 << n) - 1); ~cur;) {
    show_bit(cur);
    if (int a = __builtin_ctz(~cur); a < k) {
      int b = __builtin_ctz(cur ^= (1 << a) - 1);
      cur ^= ((1 << b - a - 1) - 1) ^ ((1 << b + 1) - 1);
    } else
      cur = -1;
  }
}
