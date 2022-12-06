#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 10;

int n;
int a[N], stk[2][N], top[2];
int dis[N];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  top[0] = top[1] = 0;
  for(int i = 1; i <= n; i ++ ) {
    while(top[0] > 0 && a[stk[0][top[0]]] < a[i]) {
      -- top[0];
    }
    stk[0][++ top[0]] = i;
    while(top[1] > 0 && a[stk[1][top[1]]] > a[i]) {
      -- top[1];
    }
    stk[1][++ top[1]] = i;

    if(i == 1)  {
      dis[i] = 0;
    } else {
      int r = (a[i - 1] < a[i]);
      //如果 a_{i-1} < a_i 那么 a_i 肯定是由比 a_i 小的值转移过来，并且下标要大于距离 a_i 最近的大于 a_i 的下标
      dis[i] = dis[*upper_bound(stk[r] + 1, stk[r] + top[r] + 1, stk[r ^ 1][top[r ^ 1] - 1])] + 1;
    }

  }
  cout << dis[n] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();

  return 0;
}