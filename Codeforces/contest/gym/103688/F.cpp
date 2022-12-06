#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 10;

int dist[N][N];
bool st[N];
void init() {
  memset(dist, 0x3f, sizeof dist);
  memset(st, false, sizeof st);
  dist[1][2] = 1;
  dist[1][3] = 1;
  dist[2][4] = 1;
  dist[3][4] = 1;
  dist[4][5] = dist[4][6] = 1;
  dist[5][7] = dist[6][7] = 1;
  int n = 7;
  for(int i = 1; i <= n; i ++ ) {
    dist[i][i] = 0;
    for(int j = i + 1; j <= n; j ++ ) {
      dist[j][i] = dist[i][j];
    }
  }
  for(int k = 1; k <= n; k ++ ) {
    for(int i = 1; i <= n; i ++ ) {
      for(int j = 1; j <= n; j ++ ) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

void solve() {
  int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
  printf("%d\n", min(dist[a1][b1] + dist[a2][b2], dist[a1][b2] + dist[a2][b1]));
}

int main()
{
  init();
  int T; scanf("%d", &T);
  while(T -- ) 
    solve();
  return 0;
}
