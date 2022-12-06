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

const int N = 101, M = 1 << 11;

int g[N];
int f[2][M][M];
vector<int> state, head[M];
int n, m; 

bool check(int x) {
  for (int i = 0; i < m; i ++ ) {
    if ((x >> i & 1) && ((x >> i + 1 & 1) || (x >> i + 2 & 1))) return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    for(int j = 0; j < m; j ++ ) {
      char c; cin >> c;
      g[i] |= (c == 'H') << j;
    }
  }

  for(int i = 0; i < 1 << m; i ++ ) if(check(i)) {
    state.push_back(i);
  }
  
  for(int a: state) {
    for(int b: state) {
      if(!(a & b)) {
        head[a].push_back(b);
      }
    }
  }

  for(int i = 1; i <= n + 2; i ++ ) {
    for(int a: state) {
      if(!(a & g[i])) {
        for(int b: head[a]) {
          for(int c: head[b]) {
            if(!(a & c)) {
              chkmax(f[i & 1][a][b], f[i - 1 & 1][b][c] + __builtin_popcount(a) );
            }
          }
        }
      }
    }
  }

  cout << f[n & 1][0][0] << "\n";

  return 0;
}