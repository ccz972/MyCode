#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = N * 2;
int h[N], e[M], ne[M], idx;
int n, m;
int color[N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
bool dfs(int u, int c) {
  color[u] = c;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!color[j]) {
      if (!dfs(j, 3 - c)) return false;
    } else if (color[j] == c) {
      return false;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b; scanf("%d%d", &a, &b); 
    add(a, b), add(b, a);
  }
  bool flag = 1;
  for (int i = 1; i <= n; i++)
    if (!color[i]) if (!dfs(i, 1)) {
      flag = 0;
      break;
    }
  if (flag) puts("Yes");
  else puts("No");
  return 0;
}