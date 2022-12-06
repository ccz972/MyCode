#include <string.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 55
#define MAXW 1000
#define inf 1e10
#define ll long long

char s[MAX][MAX];
ll r, c, w;  // w:横着或者竖着需要使用木头数目
ll fit[MAXW][MAXW], row[MAX][MAX], col[MAX][MAX];
ll vis[MAXW], belong[MAXW];

bool match(ll k) {
  for (ll i = 1; i <= w; i++) {  //这里最大是竖板需要的板子个数
    if (!vis[i] && fit[k][i]) {
      vis[i] = 1;
      if (belong[i] == -1 || match(belong[i])) {
        belong[i] = k;
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> r >> c;
  for (ll i = 1; i <= r; i++)
    for (ll j = 1; j <= c; j++) cin >> s[i][j];
  ll cnt1 = 0, cnt2 = 0;
  //横着的板子
  for (ll i = 1; i <= r; i++)
    for (ll j = 1; j <= c; j++) {
      if (s[i][j] == '*') cnt1++;
      while (s[i][j] == '*') row[i][j] = cnt1, j++;
    }
  //竖着的板子
  for (ll i = 1; i <= c; i++)
    for (ll j = 1; j <= r; j++) {
      if (s[j][i] == '*') cnt2++;
      while (s[j][i] == '*') col[j][i] = cnt2, j++;
    }
  w = cnt2;
  memset(fit, 0, sizeof(fit));
  for (ll i = 1; i <= r; i++)
    for (ll j = 1; j <= c; j++)
      if (s[i][j] == '*') {
        ll a = row[i][j], b = col[i][j];
        fit[a][b] = 1;
      }
  ll res = 0;
  memset(belong, -1, sizeof(belong));
  for (ll i = 1; i <= cnt1; i++) {
    //注意这里不是小于等于c，而是横板需要的板子的个数
    memset(vis, 0, sizeof(vis));
    if (match(i)) res++; 
  }
  cout << res << endl;
}
