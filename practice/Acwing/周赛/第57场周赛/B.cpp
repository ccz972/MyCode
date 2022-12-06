#include <bits/stdc++.h>
using namespace std;

using ll = __int128;

constexpr ll inf = (ll)1000000000000000000;

// #define int __int128
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
    static int sta[1997];
    int top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
  }

  void println(int x) { print(x), putchar('\n'); }
}  // namespace io
using namespace io;


int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  
  ll n = read();

  if(n == 1) {
    print(1); putchar(' ');
    print(0);
    // cout << "1 0";
    return 0;
  }

  array<ll, 2> ans = {n, 0};

  for(ll i = 2; i <= 1000000; i ++ ) {
    ll x = i * i;
    if(x % n == 0) {
      ans = min(ans, {i, 1ll + (x != n)});
    }
    ll cnt = 1;
    while(x <= inf) {
      x *= x;
      ++ cnt;
      if(x % n == 0) {
        ans = min(ans, {i, cnt + (x != n)});
        break;
      }
    }
  }
  print(ans[0]); putchar(' ');  
  print(ans[1]);

  // cout << ans[0] << " " << ans[1];
}