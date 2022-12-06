#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }
#define int __int128
namespace io {
  constexpr int BUFFER_SIZE = 1 << 16;
  char buffer[BUFFER_SIZE], *head, *tail;

  char get_char() {
    if (head == tail) {
      int l = (int) fread(buffer, 1, BUFFER_SIZE, stdin);
      tail = (head = buffer) + l;
    }
    return *head++;
  }

  int read() {
    int x = 0, f = 1;
    char c = get_char();
    for (; !isdigit(c); c = get_char())
      if (c == '-') f = -1;
    for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
    return x * f;
  }

  void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 | '0');
  }

  void println(int x) { print(x), putchar('\n'); }
}  // namespace io
using namespace io;

void solve() {
  //lcm(a, b) = a * b / gcd(a, b)
  //lcm(a, b) * gcd(a, b) = a * b
  //
  int n = read(), m = read();
  int ans = m * (m + 1) / 2;
  ans %= 1000000007;
  int res = n * (n + 1) / 2;
  res %= 1000000007;
  ans *= res;
  ans %= 1000000007;
  print(ans);
	//1 * 1 + 1 * 2 + 2 * 1 + 2 * 2
	//
}

signed main() {
  solve();

  return 0;
}
/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
