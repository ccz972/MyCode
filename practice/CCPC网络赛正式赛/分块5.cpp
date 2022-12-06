// 区间开方，区间求和

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

constexpr int N = 5E4 + 10;

int n, block;
int belong[N], v[N], sum[N], tag[N];

void solve_sqrt(int x) {
  if (tag[x]) return ;
  tag[x] = 1;
  sum[x] = 0;
  for (int i = (x - 1) * block + 1; i <= x * block; i ++ ) {
    v[i] = sqrt(v[i]); sum[x] += v[i];
    if (v[i] > 1) tag[x] = 0;
  }
}

void add(int l, int r, int t) {
  for (int i = l; i <= min(belong[l] * block, r); i ++ ) {
    sum[belong[l]] -= v[i];
    v[i] = sqrt(v[i]);
    sum[belong[l]] += v[i];
  }
  if (belong[l] != belong[r]) {
    for (int i = (belong[r] - 1) * block + 1; i <= r; i ++ ) {
      sum[belong[r]] -= v[i];
      v[i] = sqrt(v[i]);
      sum[belong[r]] += v[i];
    }
  }
  for (int i = belong[l] + 1; i < belong[r]; i ++ ) {
    solve_sqrt(i);
  }
}

int query(int l, int r, int ans = 0) {
  for (int i = l; i <= min(belong[l] * block, r); i ++ ) {
    ans += v[i];
  }
  if (belong[l] != belong[r]) {
    for (int i = (belong[r] - 1) * block + 1; i <= r; i ++ ) {
      ans += v[i];
    }
  }
  for (int i = belong[l] + 1; i < belong[r]; i ++ ) {
    ans += sum[i];
  }
  return ans;
}


int main() {
  n = read(), block = sqrt(n);
  for (int i = 1; i <= n; i ++ ) v[i] = read();
  for (int i = 1; i <= n; i ++ ) {
    belong[i] = (i - 1) / block + 1;
    sum[belong[i]] += v[i];
  }
  for (int i = 1; i <= n; i ++ ) {
    int f = read(), l = read(), r = read(), t = read();
    if (f == 0) {
      add(l, r, t);
    } else {
      print(query(l, r));
    }
  }
  

  return 0;
}
