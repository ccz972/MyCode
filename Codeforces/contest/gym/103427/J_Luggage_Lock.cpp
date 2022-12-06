#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for (int i = (b); i <= (s); ++i)
#define dec(i, b, s) for (int i = (b); i >= (s); --i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

const int N = 15, M = N * 2;

int dis[10000][10000];

int get(int s, int x, int len, int ty) {
  int a[4] = {s / 1000 % 10, s / 100 % 10, s / 10 % 10, s % 10};
  for (int i = x; i < x + len; i++) a[i] = (a[i] + ty + 10) % 10;
  s = 0;
  for (int i = 0; i < 4; i++) s = a[i] + s * 10;
  return s;
}

int find(string s) {
  int res = 0;
  for (int i = 0; i < 4; i++) res = 10 * res + s[i] - '0';
  return res;
}

void solve() {
  string st, ed;
  cin >> st >> ed;
  cout << dis[find(st)][find(ed)] - 1 << '\n';
}

int main() {

  int T = 1;
  cin >> T;
  for (int u = 0; u < 10000; u++) {
    queue<int> q;
    q.push(u);
    dis[u][u] = 1;
    while (q.size()) {
      auto t = q.front();
      q.pop();
      for (int len = 1; len <= 4; len++)
        for (int i = 0; i < 4 - len + 1; i++) {
          int res = get(t, i, len, 1);
          if (!dis[u][res]) {
            dis[u][res] = dis[u][t] + 1;
            q.push(res);
          }
          res = get(t, i, len, -1);
          if (!dis[u][res]) {
            dis[u][res] = dis[u][t] + 1;
            q.push(res);
          }
        }
    }
  }
  while (T--) {
    solve();
  }

  return 0;
}