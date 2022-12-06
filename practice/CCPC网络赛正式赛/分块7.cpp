// 区间加，区间乘，单点查询

#include <bits/stdc++.h>
using namespace std;

namespace io {
  constexpr int SIZE = 1 << 19;
  char buf[SIZE], *head, *tail;
  char get_char() {
    tail = (head = buf) + fread(buf, 1, SIZE, stdin);
    return *head ++;
  }
  int read() {
    int x = 0, f = 1;
    char c = get_char();
    for (; !isdigit(c); c = get_char()) if (c == '-') f = -1;
    for (; isdigit(c); c = get_char()) if (c == '-') x = (x << 1) + (x << 3) + (c - '0');
    return x * f;
  }
  void print(int x) {
    static int stk[1997];
    int top = 0;
    do {
      stk[top ++ ] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(stk[-- top] + 48);
    putchar('\n');
  }
}

using namespace io;

constexpr int N = 1E5 + 10;
constexpr int M = 2E5 + 10;
constexpr int MOD = 1E9 + 7;

int n, m, block;

int v[N], belong[N], addtag[1000], multag[1000];

void reset(int x) {
  for (int i = (x - 1) * block + 1; i <= min(n, x * block); i ++ ) {
    v[i] = (v[i] * multag[x] + addtag[x]) % MOD;
  }
  addtag[x] = 0, multag[x] = 1;
}
// void add(int l, int r, int t) {
//   for (int i = l; i <= min(belong[l] * block, r); i ++ ) {
//     sum[belong[l]] -= v[i];
//     v[i] = sqrt(v[i]);
//     sum[belong[l]] += v[i];
//   }
//   if (belong[l] != belong[r]) {
//     for (int i = (belong[r] - 1) * block + 1; i <= r; i ++ ) {
//       sum[belong[r]] -= v[i];
//       v[i] = sqrt(v[i]);
//       sum[belong[r]] += v[i];
//     }
//   }
//   for (int i = belong[l] + 1; i < belong[r]; i ++ ) {
//     solve_sqrt(i);
//   }
// }
void modify(int f, int l, int r, int k) {
  reset(belong[l]);
  for (int i = l; i <= min(belong[l] * block, r); i ++ ) {
    if (f == 0) {
      v[i] += k;
    } else {
      v[i] *= k;
    }
    v[i] %= MOD;
  }
  if (belong[l] != belong[r]) {
    reset(belong[r]);
    for (int i = (belong[r] - 1) * block + 1; i <= r; i ++ ) {
      if (f == 0) {
        v[i] += k;
      } else {
        v[i] *= k;
      }
      v[i] %= MOD;
    }
  }
  for (int i = belong[l] + 1; i < belong[r]; i ++ ) {
    if (f == 0) {
      addtag[i] = (addtag[i] + k) % MOD;
    } else {
      addtag[i] = (addtag[i] * k) % MOD;
      multag[i] = (multag[i] * k) % MOD;
    }
  }
}

int main() {
  n = read(); block = sqrt(n);
  for (int i = 1; i <= n; i ++ ) {
    v[i] = read(); belong[i] = (i - 1) / block + 1;
  }
  for (int i = 1; i <= belong[n]; i ++ ) {
    multag[i] = 1;
  }

  m = (n - 1) / block + 1;
  for (int i = 1; i <= n; i ++ ) {
    int f = read(), l = read(), r = read(), t = read();
    if (f == 2) {
      cout << (v[r] * multag[belong[r]] + addtag[belong[r]]) % MOD;
    } else {
      modify(f, l, r, t);
    }
  }
  return 0;
}
