#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int a[210][210];

void solve() {
  int n; cin >> n;
  if (n % 8 == 0) {
    cout << "YES\n";
    a[1][1] = 1;
    a[2][1] = 1, a[2][2] = 1;
    a[3][1] = 1; a[3][2] = 2, a[3][3] = 2;
    a[4][1] = 3; a[4][2] = 2, a[4][3] = 2; a[4][4] = 4;
    a[5][1] = 3; a[5][2] = 3, a[5][3] = 5; a[5][4] = 4; a[5][5] = 4;
    a[6][1] = 3; a[6][2] = 5, a[6][3] = 5; a[6][4] = 4; a[6][5] = 6; a[6][6] = 6;
    a[7][1] = 7; a[7][2] = 7, a[7][3] = 5; a[7][4] = 8; a[7][5] = 6; a[7][6] = 6; a[7][7] = 9;
    a[8][1] = 7; a[8][2] = 7, a[8][3] = 8; a[8][4] = 8; a[8][5] = 8; a[8][6] = 9; a[8][7] = 9; a[8][8] = 9;

    int now = 10;
    for (int i = 9; i <= n; i += 8 ) {
      int x = i, y = i;
      a[x][y] = now;
      a[x + 1][y] = now, a[x + 1][y + 1] = now;
      a[x + 2][y] = now; a[x + 2][y + 1] = now + 1, a[x + 2][y + 2] = now + 1;
      a[x + 3][y] = now + 2; a[x + 3][y + 1] = now + 1, a[x + 3][y + 2] = now + 1; a[x + 3][y + 3] = now + 3;
      a[x + 4][y] = now + 2; a[x + 4][y + 1] = now + 2, a[x + 4][y + 2] = now + 4; a[x + 4][y + 3] = now + 3; a[x + 4][y + 4] = now + 3;
      a[x + 5][y] = now + 2; a[x + 5][y + 1] = now + 4, a[x + 5][y + 2] = now + 4; a[x + 5][y + 3] = now + 3; a[x + 5][y + 4] = now + 5; a[x + 5][y + 5] = now + 5;
      a[x + 6][y] = now + 6; a[x + 6][y + 1] = now + 6, a[x + 6][y + 2] = now + 4; a[x + 6][y + 3] = now + 7; a[x + 6][y + 4] = now + 5; a[x + 6][y + 5] = now + 5; a[x + 6][y + 6] = now + 8;
      a[x + 7][y] = now + 6; a[x + 7][y + 1] = now + 6, a[x + 7][y + 2] = now + 7; a[x + 7][y + 3] = now + 7; a[x + 7][y + 4] = now + 7; a[x + 7][y + 5] = now + 8; a[x + 7][y + 6] = now + 8; a[x + 7][y + 7] = now + 8;
      now += 9;
    }

    for (int i = 9; i <= n; i += 8) {
      for (int j = 1; j <= i - 8; j += 8) {
        //8 X 8
        for (int x = i; x <= i + 7; x += 2 ) {
          for (int y = j; y <= j + 7; y += 2 ) {
            a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = now;
            ++ now;
          }
        }         
      }
    }
    

    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= i; j ++ ) {
        cout << a[i][j] << " \n"[j == i];
        // printf("%2d%c", a[i][j], " \n"[j == i]);
      }
    }
    
  } else if ((n + 1) % 8 == 0) {
    cout << "YES\n";
    a[1][1] = 1;
    a[2][1] = 1, a[2][2] = 1;
    a[3][1] = 1; a[3][2] = 2, a[3][3] = 2;
    a[4][1] = 3; a[4][2] = 2, a[4][3] = 2; a[4][4] = 4;
    a[5][1] = 3; a[5][2] = 3, a[5][3] = 4; a[5][4] = 4; a[5][5] = 4;
    a[6][1] = 3; a[6][2] = 5, a[6][3] = 6; a[6][4] = 6; a[6][5] = 6; a[6][6] = 7;
    a[7][1] = 5; a[7][2] = 5, a[7][3] = 5; a[7][4] = 6; a[7][5] = 7; a[7][6] = 7; a[7][7] = 7;
    int now = 8;
    for (int i = 9; i <= n; i += 8 ) {
      int x = i, y = i;
      a[x][y] = now;
      a[x + 1][y] = now, a[x + 1][y + 1] = now;
      a[x + 2][y] = now; a[x + 2][y + 1] = now + 1, a[x + 2][y + 2] = now + 1;
      a[x + 3][y] = now + 2; a[x + 3][y + 1] = now + 1, a[x + 3][y + 2] = now + 1; a[x + 3][y + 3] = now + 3;
      a[x + 4][y] = now + 2; a[x + 4][y + 1] = now + 2, a[x + 4][y + 2] = now + 3; a[x + 4][y + 3] = now + 3; a[x + 4][y + 4] = now + 3;
      a[x + 5][y] = now + 2; a[x + 5][y + 1] = now + 4, a[x + 5][y + 2] = now + 5; a[x + 5][y + 3] = now + 5; a[x + 5][y + 4] = now + 5; a[x + 5][y + 5] = now + 6;
      a[x + 6][y] = now + 4; a[x + 6][y + 1] = now + 4, a[x + 6][y + 2] = now + 4; a[x + 6][y + 3] = now + 5; a[x + 6][y + 4] = now + 6; a[x + 6][y + 5] = now + 6; a[x + 6][y + 6] = now + 6;
      now += 7;
    }

    for (int i = 8; i <= n; i += 8) {
      for (int j = 1; j <= i; j += 8) {
        //8 X 8
        for (int x = i; x <= i + 7; x += 2 ) {
          for (int y = j; y <= j + 7; y += 2 ) {
            a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = now;
            ++ now;
          }
        }         
      }
    }
    

    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= i; j ++ ) {
        cout << a[i][j] << " \n"[j == i];
        // printf("%2d%c", a[i][j], " \n"[j == i]);
      }
    }

  } else {
    cout << "NO\n";
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
