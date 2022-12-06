#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

//#define int long long 
#define all(v) (v).begin(),(v).end()

const int N = 51;

int n, m, ans; 
int p[N], w[N], v[N];

struct node {
  int cost, val;
  bool operator < (const node &T) const {
    if (val == T.val) return cost > T.cost;
    return val < T.val;
  }
  node(): cost(0), val(0) {}
  node (int x, int y): cost(x), val(y) {}
};

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void init() {
  for (int i = 0; i <= n; i ++ ) p[i] = i;
}

void solve(int test) {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; i ++ ) {
    cin >> v[i] >> w[i]; // cost and value
    int k; cin >> k;
    for (int j = 0; j < k; j ++ ) {
      int id; cin >> id;
      p[find(id)] = p[find(i)];
    }
  }
  ans = 0x3f3f3f3f;
  priority_queue<node> p, q;
  for (int i = 1; i <= n; i ++ ) if (find(i) == i) {
    while (!p.empty()) p.pop();
    while (!q.empty()) q.pop();
    p.push(node{0, 0});
    for (int j = 1; j <= n; j ++ ) if (find(j) == i) {
      while (!p.empty()) {
        node t = p.top(); p.pop();
        q.push(t);
        node now{t.cost + v[j], t.val + w[j]};
        if (now.val >= m) {
          ans = min(ans, now.cost);
        }
        if (now.cost >= ans) {
          continue;
        }
        q.push(now);
      }
      int x = 0x3f3f3f3f;
      while (!q.empty()) {
        node t = q.top(); q.pop();
        if (t.cost < x) {
          x = t.cost;
          p.push(t);
        }
        if (t.val >= m) {
          ans = min(ans, t.cost);
        }
      }
    }
  }
  cout << "Case " << test << ": ";
  if (ans != 0x3f3f3f3f) {
    cout << ans << "\n";
  } else {
    cout << "Poor Magina, you can't save the world all the time!\n";
  }
} 

void solve2(int test) {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; i ++ ) {
    cin >> v[i] >> w[i]; // cost and value
    int k; cin >> k;
    for (int j = 0; j < k; j ++ ) {
      int id; cin >> id;
      p[find(id)] = p[find(i)];
    }
  }
  ans = 0x3f3f3f3f;
  priority_queue<node> p, q;

  for (int i = 1; i <= n; i ++ ) if (find(i) == i) {
    while (!p.empty()) p.pop();
    while (!q.empty()) q.pop();
    p.push(node{0, 0});
    for (int j = 1; j <= n; j ++ ) if (find(j) == i) {
      // p -> q
      while (!p.empty()) {
        node t = p.top(); p.pop();
        node now{t.cost + v[j], t.val + w[j]};
        // 不选
        q.push(t);
        // 选
        if (now.val >= m) {
          ans = min(ans, now.cost);
        }
        if (now.cost >= ans) { // 剪纸  improtant
          continue;
        }
        if (now.val < m) {
          q.push(now);
        }
      }
      int x = 0x3f3f3f3f;
      while (!q.empty()) {
        node t = q.top(); q.pop();
        if (t.cost < x) {
          p.push(t);
          x = min(x, t.cost);
        }
      }
    }
  }

  cout << "Case " << test << ": ";
  if (ans != 0x3f3f3f3f) {
    cout << ans << "\n";
  } else {
    cout << "Poor Magina, you can't save the world all the time!\n";
  }
} 

int main() {
  ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
  int T; cin >> T;
  for (int test = 1; test <= T; test ++ ) solve2(test);

  return 0;
}
 