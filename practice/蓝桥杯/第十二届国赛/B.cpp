#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20210605 + 100;

int p[N], cnt;
bool st[N];

void init(int n) {
  st[0] = st[1] = true;
  for(int i = 2; i <= n; i ++ ) {
    if(!st[i]) p[cnt ++ ] = i;
    for(int j = 0; p[j] <= n / i; j ++ ) {
      st[i * p[j]] = true;
      if(i % p[j] == 0) break;
    } 
  }
}

void solve() {
  int n = 20210605;
  init(n);
  int ret = 0;
  for(int i = 0; i < cnt; i ++ ) {
    int x = p[i];
    // cout << x << "\n";
    bool flag = true;
    while(x) {
      int now = x % 10;
      x /= 10;
      if(st[now]) flag = false;
    }
    ret += flag;
    if(flag) cout << p[i] << "\n";
    // if(ret == 20) exit(0);
  }
  cout << ret << "\n";

}
bool vis[10];
bool chk(int x) {
  
  int now = x;
  while(now) {
    if(!vis[now % 10]) return false;
    now /= 10;
  }
  if(x == 1) return false;
  if(x == 2 || x == 3) return true; 
  if(x % 2 == 0) return false;
  for(int i = 3; i <= x / i; i += 2) if(x % i == 0) {
    return false;
  }
  return true;
}

void get() {
  int ret = 0;
  vis[2] = vis[3] = vis[5] = vis[7] = true;
  for(int i = 1; i <= 20210605; i ++ ) {
    if(chk(i)) {
      ret ++; 
      cout << i << "\n";
    }
  }
  cout << ret;
}

int main() {
  freopen("2.txt", "w", stdout);
  solve();
  
  // get();
  return 0;
}