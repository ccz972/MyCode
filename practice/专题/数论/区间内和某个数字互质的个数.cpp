// https://www.51nod.com/Challenge/Problem.html#problemId=1439
// 每次加入一个数字或者删除集合中的某个数字，问集合中互质的对数

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5E5 + 10;

int n, q, sz, res, num, a[N], cnt[N];
bool vis[N];
vector<int> primes[N];
long long ans;

void init() {
  for (int i = 2; i < N; i ++ ) if (!vis[i]) {
    for (int j = i; j < N; j += i) {
      primes[j].emplace_back(i);
      vis[j] = true;
    }
  }
}

//
void dfs(int pos, int mul, int len, bool flag) {
  if (pos == (int)primes[num].size()) {
    if (len) {
      if (!flag) cnt[mul] --; 
      if (len & 1) res += cnt[mul];
      else res -= cnt[mul];
      if (flag) cnt[mul] ++;
    }

  } else {
    dfs(pos + 1, mul, len, flag);
    dfs(pos + 1, mul * primes[num][pos], len + 1, flag);
  }
}

int add(int x) {
  num = x, res = 0; // 和 x 互质的个数 
  dfs(0, 1, 0, true);
  sz ++;
  return sz - res - 1;
}

int del(int x) {
  num = x, res = 0;
  dfs(0, 1, 0, false);
  sz --;
  return sz - res;
  // return 
}
int main() {
  init();
  scanf("%d%d", &n, &q);  
  for (int i = 1; i <= n; i ++ ) scanf("%d", a + i), vis[i] = false;

  while (q -- ) {
    int x; scanf("%d", &x);
    if (!vis[x]) {
      ans += add(a[x]);
    } else {
      ans -= del(a[x]);
    }
    vis[x] = !vis[x];
    printf("%lld\n", ans);
  }

  return 0;
}

