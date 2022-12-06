/***************************************************

@File    : A.cpp
@Time    : 2022/07/17 12:59:33
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 20, M = 50;

bool vis[M + 1][M + 1];
bool st[M + 1][M + 1];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int d1, d2; cin >> d1 >> d2;
  if(d1 > d2) swap(d1, d2);
  if((__gcd(d1, d2) != 1) || (~(d1 + d2) & 1)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  // int dx[8] = {-d2, -d1, d1, d2, d2, d1, -d1, -d2};
  // int dy[8] = {d1, d2, d2, d1, -d1, -d2, -d2, -d1};

  // st[1][1] = true;
  // for(int i = 1; i <= M; i ++ ) {
  //   for(int j = 1; j <= M; j ++ ) if(st[i][j]) {
  //     for(int k = 0; k < 8; k ++ ) {
  //       int x = i + dx[k], y = j + dy[k];
  //       if(x >= 1 && x <= M && y >= 1 && y <= M) {
  //         vis[x][y] = true;
  //       }
  //     }
  //     for(int k = 1; k <= M; k ++ ) {
  //       for(int l = 1; l <= M; l ++ ) {
  //         if(vis[k][l]) {
  //           st[k][l] = true;
  //         }
  //       }
  //     }
  //   }

  // }
  // for(int i = 1; i <= N; i ++ ) {
  //   for(int j = 1; j <= N; j ++ ) {
  //     if(!st[i][j]) {
  //       cout << "NO\n";
  //       return 0;
  //     }
  //   }
  // }

  // cout <<"YES\n";



  return 0;
}