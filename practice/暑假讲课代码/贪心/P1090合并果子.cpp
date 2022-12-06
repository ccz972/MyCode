// @url https://www.luogu.com.cn/problem/P1090

#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

int main() {
  
  int n; cin >> n;

  priority_queue<int, vector<int>, greater<int> > q;

  // priority_queue<int> q;
  // max : q.top();

  for (int i = 0; i < n; i ++ ) {
    int x; cin >> x;
    q.push(x);
  }

  ll ans = 0;

  while((int)q.size() >= 2) {
    int t1 = q.top(); q.pop();
    int t2 = q.top(); q.pop();
    ans += t1 + t2;
    q.push(t1 + t2);
  }

  cout << ans;

  return 0;
}