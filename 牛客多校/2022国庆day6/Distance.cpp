#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
// #define int __int128
namespace io {
  constexpr int BUFFER_SIZE = 1 << 16;
  char buffer[BUFFER_SIZE], *head, *tail;

  char get_char() {
    if (head == tail) {
      int l = (int) fread(buffer, 1, BUFFER_SIZE, stdin);
      tail = (head = buffer) + l;
    }
    return *head++;
  }

  int read() {
    int x = 0, f = 1;
    char c = get_char();
    for (; !isdigit(c); c = get_char())
      if (c == '-') f = -1;
    for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
    return x * f;
  }

  void print(int x) {
    static int sta[1997];
    int top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar('\n');
  }

  void println(int x) { print(x), putchar('\n'); }
}  // namespace io
using namespace io;

void solve() {
  int n = read(), m = read(), h = read(), q = read(); 
  // int n, m, h, q;
  // cin >> n >> m >> h >> q;
  
  vector<array<int, 4> > query(q);
  for (int i = 0; i < q; i ++ ) {
    for (int j = 0; j < 4; j ++ ) {
      // cin >> query[i][j];
      query[i][j] = read();
    }
  }
  int p = min({n, m, h});
  if (p == m) {
    for (int i = 0; i < q; i ++ ) {
      swap(query[i][1], query[i][2]);
    }
    swap(n, m);
  } else if (h == m) {
    for (int i = 0; i < q; i ++ ) {
      swap(query[i][1], query[i][3]);
    }
    swap(n, h);
  }
  if (m > h) {
    for (int i = 0; i < q; i ++ ) {
      swap(query[i][2], query[i][3]);
    }
    swap(m, h);
  }

  //n <= m <= h
  // vector<vector<vector<int> > > a(n + 1, vector<vector<int> > (m + 1, vector<int>(h + 1)));

  vector<vector<vector<int> > > b(n + 1, vector<vector<int> > (m + 1));
  // vector<vector<int> > cnt(n + 1, vector<int>(m + 1));

  for (int i = 0; i < q; i ++ ) {
    auto [op, x, y, z] = query[i];
    if (op & 1) {
      if (b[x][y].empty()) {
        b[x][y].emplace_back(z);
      } else {
        // int idx = lower_bound(b[x][y].begin(), b[x][y].end(), z) - b[x][y].begin();
        // b[x][y].insert(b[x][y].begin() + idx, z);
        b[x][y].insert(lower_bound(b[x][y].begin(), b[x][y].end(), z), z);
      }
    } else {
      int ans = INT_MAX;
      for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) if (!b[i][j].empty()) {
          int ret = abs(i - x) + abs(j - y);
          if (ret >= ans) continue;
          if ((int)b[i][j].size() <= 6) {
            for (int k = 0; k < (int)b[i][j].size(); k ++ ) {
              chkmin(ans, ret + abs(b[i][j][k] - z));
            }
            // chkmin(ans, ret + abs(b[i][j][0] - z));
            continue;
          } 
          auto pos = lower_bound(b[i][j].begin(), b[i][j].end(), z);          
          if (pos == b[i][j].end()) {
            chkmin(ans, ret + abs(*prev(pos) - z));
          } else if (pos == b[i][j].begin()) {
            chkmin(ans, ret + abs(*pos - z));
          } else {
            chkmin(ans, ret + abs(*pos - z));
            chkmin(ans, ret + abs(*prev(pos) - z));
          }
        }
      }
      // cout << ans << "\n";
      print(ans);
    }
  }


}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  // cout << fixed << setprecision(10);
  // cout << pow(100000, 0.667) << "\n";
  solve();
  return 0;
}