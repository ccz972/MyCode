// 单点插入，单点询问

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

int n, m, block;

int v[N];
vector<int> ve[N];
int st[M], top;

pair<int, int> query(int b) {
  int x = 1;
  while (b > (int)ve[x].size()) {
    b -= (int)ve[x].size();
    ++ x;
  }
  return make_pair(x, b - 1);
}

void rebuild() {
  top = 0;
  for (int i = 1; i <= m; i ++ ) {
    for (auto j: ve[i]) {
      st[++ top] = j;
    }
    ve[i].clear();
  }
  int new_block = sqrt(top);
  for (int i = 1; i <= top; i ++ ) {
    ve[(i - 1) / new_block + 1].emplace_back(st[i]);
    m = (top - 1) / new_block + 1;
  }
}

void insert(int a, int b) {
  auto [x, y] = query(a);
  ve[x].insert(ve[x].begin() + y, b);
  if ((int)ve[x].size() > 20 * block) {
    rebuild();
  }
}

int main() {
  n = read(); block = sqrt(n);
  for (int i = 1; i <= n; i ++ ) v[i] = read();
  for (int i = 1; i <= n; i ++ ) {
    ve[(i - 1) / block + 1].emplace_back(v[i]);
  }
  m = (n - 1) / block + 1;
  for (int i = 1; i <= n; i ++ ) {
    int f = read(), l = read(), r = read(), t = read();
    if (f == 0) {
      insert(l, r);
    } else {
      auto [x, y] = query(r);
      cout << ve[x][y];
    }
  }
  return 0;
}
