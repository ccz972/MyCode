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

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
ll read() {
  ll x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
string read_s() {
  string str;
  char c = get_char();
  while (c == ' ' || c == '\n' || c == '\r') c = get_char();
  while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
  return str;
}
void print(int x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 | '0');
}
void println(int x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(ll& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // namespace io

int main() {
#ifdef LOCAL
  freopen("P1273_4.in", "r", stdin);
#endif

  //cin.tie(nullptr)->sync_with_stdio(false);
  int n = io::read(), m = io::read(); // cin >> n >> m;
  vector<vector<array<int, 2> > > son(n + 1);
  
  for(int i = 1; i <= n - m; i ++ ) {
    int k = io::read(); // cin >> k;
    for(int j = 0; j < k; j ++ ) {
      int a = io::read(), c = io::read(); // cin >> a >> c;
      son[i].push_back({a, c});
    }
  }

  vector<int> w(n + 1);
  for(int i = n - m + 1; i <= n; i ++ ) {
    w[i] = io::read();
  }


  vector<vector<ll> > f(n + 1, vector<ll> (n + 1, -1e9));
  //f[u][i]表示在u的子树中选i个叶子的最大价值
  function<int(int)> dfs = [&](int u) {
    int cnt = 0;
    f[u][0] = 0;
    for (auto& [v, w] : son[u]) {
      int now = dfs(v);
      cnt += now;
      vector<ll> tmp(cnt + 1);
        for(int i = 0; i <= cnt; i ++ ) tmp[i] = f[u][i]; 

      for(int i = 1; i <= cnt; i ++ ) {
        for(int j = 0; j <= i && j <= now; j ++ ) {
          chkmax(tmp[i], f[v][j] + f[u][i - j] - w);
        }
      }
      
      for(int i = 0; i <= cnt; i ++ ) f[u][i] = tmp[i]; 
    }
    
    if(!cnt) {
      f[u][1] = w[u];
      cnt ++;
    }
    f[u][0] = 0;
    return cnt;
    
  };

  dfs(1);
  int ans = 0;
  for(int i = 0; i <= n; i ++ ) if(f[1][i] >= 0) {
    ans = i;
  }
  io::print(ans);
  //cout << ans << "\n";

  return 0;
}