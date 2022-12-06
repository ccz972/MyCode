#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4 + 10;

int n, a[N];
ll b;

void solve1() {

  scanf("%d%lld", &n, &b);

  for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

  sort(a, a + n);
  
  reverse(a, a + n);
  //a[0]

  ll s = 0;

  for(int i = 0; i < n; i ++ ) {
    s += a[i];
    if(s >= b) {
      printf("%d\n", i + 1);
      return ;
    }
  } 

}

void solve2() {
  
  scanf("%d%lld", &n, &b);

  priority_queue<int> q;

  for(int i = 0; i < n; i ++ ) {
    int x; scanf("%d", &x);
    q.push(x);
  }

  

  ll s = 0, cnt = 0;

  while(!q.empty()) {
    int t = q.top(); q.pop();
    cnt ++;
    s += t;
    if(s >= b) {
      printf("%d\n", cnt);
      return ;
    }
  }

}




int main() {
  // solve1();
  solve2();
  return 0;
}