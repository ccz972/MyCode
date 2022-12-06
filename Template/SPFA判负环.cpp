int h[N], ne[M], e[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
void add(int a, int b, int c) {
  // 添加一条边a->b，边权为c
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
  memset(st, 0, sizeof st);
  memset(cnt, 0, sizeof cnt);
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
    st[i] = 1;
  }
  while (q.size()) {
    auto t = q.front();
    q.pop();
    st[t] = 0;
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        cnt[j] = cnt[t] + 1;
        if (cnt[j] >= n) return 1;
        if (!st[j]) {
          q.push(j);
          st[j] = 1;
        }
      }
    }
  }
  return 0;
}