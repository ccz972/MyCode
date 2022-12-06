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

constexpr int N = 1e6 + 10; // M = 2e6 + 10;
int n, u, v;
// int h[N], e[M], ne[M], idx;
// void add(int a, int b) {
//   e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
// }

vector<int> son[N];
int cnt[2];
ll ans = 0;

void dfs(int u, int fa, int dep) {
  cnt[dep] ++;
  for(int &v: son[u]) if(v != fa) {
    ans += cnt[dep ^ 1];
    dfs(v, u, dep ^ 1);
  }
  // for(int i = h[u]; ~i; i = ne[i]) {
  //   int j = e[i]; 
  //   if(j == fa) continue;
  //   ans += cnt[dep ^ 1];
  //   // printf(">> %d %d %lld\n", j, cnt[(dep[j] & 1) ^ 1], ans);
  //   dfs(j, u, dep ^ 1);
  // }
}

int main() {
  n = read();
  // for(int i = 0; i <= n; i ++ ) h[i] = -1;

  for(int i = 1; i < n; i ++ ) {
    u = read(), v = read();
    son[u].push_back(v);
    son[v].push_back(u);
    // add(u, v); add(v, u);
  }

  dfs(1, 0, 0);
  // ans -= n - 1;
  print(ans);


  return 0;
}