#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 520, M = 1e4, inf = 0x3f3f3f3f;
int n, m, k;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int cnt[N], dist[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool spfa() {
  
  for(int i = 0; i <= n; i ++ ) {
    dist[i] = inf;
    st[i] = false;
    cnt[i] = 0;
  }

  queue<int> q;
  q.push(1);
  dist[1] = 0;
  st[1] = true;

  while(!q.empty()) {
    int t = q.front(); q.pop();

    st[t] = false;

    for(int i = h[t]; i != -1; i = ne[i]) {

      int j = e[i], p = w[i];

      if(dist[j] > dist[t] + p) {
        dist[j] = dist[t] + p;
        cnt[j] = cnt[t] + 1;
        
        if(cnt[j] >= n) {
          return true;
        }

        if(!st[j]) {
          q.push(j);
          st[j] = true;
        }

      }
    }
  }
  
  return false;
}

void solve() {
  
  scanf("%d%d%d", &n, &m, &k);
  idx = 0;
  for(int i = 0; i <= n; i ++ ) {
    h[i] = -1;
  }
  for(int i = 1; i <= m; i ++ ) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    add(a, b, c); add(b, a, c);
  }
  for(int i = 1; i <= k; i ++ ) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    add(a, b, -c);
  }
  bool f = spfa();
  if(f) {
    puts("YES");
  } else {
    puts("NO");
  }

}

int main() {
  int T; scanf("%d", &T);
  while(T -- )
    solve();
  return 0;
}