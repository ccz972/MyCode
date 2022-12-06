#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace io {
  constexpr int SIZE = 1 << 16;
  char buf[SIZE], *head, *tail;
  char get_char() {
    if(head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
    return *head ++;
  }
  int read() {
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

constexpr int N = 1e6 + 1; // M = 2e6 + 10;
int n, u, v;
// int h[N], e[M], ne[M], idx;
vector<int> son[N];
int cnt[2];
ll ans = 0;

void dfs(int u, int fa, int dep) {
  cnt[dep] ++;
  for(int &v: son[u]) if(v != fa) {
    ans += cnt[dep];
    dfs(v, u, dep ^ 1);
  }
}

int main() {
  n = read();
  for(int i = 1; i < n; i ++ ) {
    u = read(), v = read();
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs(1, 0, 0);
  ans -= n - 1;
  print(ans);
  return 0;
}