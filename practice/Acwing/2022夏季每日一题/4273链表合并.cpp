#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 10;

int ne[N], val[N];

int main() {
  int h1, h2; scanf("%d%d", &h1, &h2);
  int n; scanf("%d", &n);
  vector<int> a, b;
  for (int i = 0; i < n; i ++ ) {
    int id; scanf("%5d", &id);
    scanf("%d%5d", &val[id], &ne[id]);
  }
  int now1 = h1, now2 = h2;
  while (now1 != -1) {
    a.push_back(now1);
    now1 = ne[now1];
  }
  while (now2 != -1) {
    b.push_back(now2);
    now2 = ne[now2];
  }
  if (a.size() < b.size()) {
    swap(h1, h2);
    a.swap(b);
  }
  vector<int> ans;
  for (int i = 0; i < a.size(); i ++ ) {
    ans.push_back(a[i]);
    if ((i & 1) && !b.empty()) {
      ans.push_back(b.back());
      b.pop_back();
    } 
  }
  for (int i = 0; i < ans.size() - 1; i ++ ) {
    printf("%05d %d %05d\n", ans[i], val[ans[i]], ans[i + 1]);
  }
  printf("%05d %d %d\n", ans.back(), val[ans.back()], -1);
  return 0;
}