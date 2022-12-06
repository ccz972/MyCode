#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e5 + 5;
int h[N], e[M], ne[M], idx;
int match[N];  //标志与女生匹配的男生编号
bool st[N];    //对每一次男生选择而言，女生是否被选择过。
int n1, n2, m;
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
bool find(int x) {
  for (int i = h[x]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) { //女生是否被选择过
      st[j] = 1;  //没选择过则标记一下
      if (!match[j] || find(match[j])) {  
        //如果没匹配男生，或匹配的男生可以有其他选择，则可以匹配成功。 
        match[j] = x;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n1, &n2, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  int res = 0;
  for (int i = 1; i <= n1; i++) {
    memset(st, 0, sizeof st);
    if (find(i)) res++;
  }
  printf("%d\n", res);
  return 0;
}