#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace io {
  constexpr int SIZE = 1 << 18;
  char buf[SIZE], *head, *tail;
  char get_char() {
    if(head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
    return *head ++;
  }
  ll read() {
    ll x = 0, f = 1;
    char c = get_char();
    for(; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
    for(; isdigit(c); c = get_char()) x = (x << 3) + (x << 1) + (c - 48);
    return x * f;
  }
  void print(ll x) {
    if(x > 9) print(x / 10);
    putchar(x % 10 | '0');
  }
};

using namespace io;

const int N = 1e3 + 10;

ll a[N];
ll last[N];
int main() {
  ll n = read(), m = read();
  for(ll i = 1 ; i <= n; i ++ ) {
    a[i] = read();
    last[i] = -1;
  }
  
  while(m -- ) {
    ll t = read(), k = read();
    for(ll i = 1; i <= k; i ++ ) {
      ll x = read();
      if(last[x] == -1 || a[x] == -1) {
        last[x] = t;
      } else {
        if(t - last[x] < a[x]) {
          printf("Don't take %lld at %lld!\n", x, t);
        } else {
          last[x] = t;
        }
      }
    }
  }

  
  return 0;
}