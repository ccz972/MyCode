#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 5010;
int h[N], e[M], ne[M], wt[M], idx;
int wf[N], cnt[N];
double dist[N];
bool st[N];
int n, m;
void add(int a, int b, int c) {
  e[idx] = b, wt[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool check(double mid) {
  memset(cnt, 0, sizeof cnt);
  memset(st, 0, sizeof st);
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
      auto temp = dist[t] + wf[t] - mid * wt[i];
      if (dist[j] < temp) {  //这里的wf应该是t，因为是更新所有连在t上的边的点。
        dist[j] = temp;
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
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 1; i <= n; i++) cin >> wf[i];
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  double l = 0, r = 1000;
  while (r - l > 1e-4) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.2lf", r);
  return 0;
}