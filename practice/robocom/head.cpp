#include <bits/stdc++.h>
using namespace std;
//https://pta-oms.pintia.cn/problem-sets/1543852304448090112/rankings
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

int main() {
  
  return 0;
}