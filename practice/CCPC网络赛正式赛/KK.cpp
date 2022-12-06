/*每次不论结果，都投入1元的C++程序示例*/
#include <bits/stdc++.h>
using namespace std;

void print(__int128 x) {
  static int stk[1997];
  int top = 0;
  do {
    stk[top ++ ] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(stk[-- top] + 48);
  putchar('\n');
}

int main() {
  long long y, p, seed;
  int result = -1;
  cin >> y >> p >> seed;
  seed = 0;
  // long long now = y, sum = y;
  __int128 now = y, sum = y;
  __int128 mx = now * INT64_MAX;
  while (result != 2) {
    // printf("%lld\n", now);
    print(now);
    fflush(stdout);
    int sjakdljaskjk = scanf("%d", &result);
    if (result == 0) {
      sum += now;
      now = y;
    } else {
      if (sum + now + 1 <= mx) {
        sum += now + 1;
      } else {
        sum += 1;
      }
      now = sum;
    }
    
  }
  return 0;
}