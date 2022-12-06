#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
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
void print(ll x) {
  if(x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 | '0');
}
void println(ll x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(ll& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // 
using namespace io;

constexpr int N = 2E5 + 10;
constexpr int INF = 2E9 + 10;

ll a[N], b[N];
struct splitmix64 {
    size_t operator()(size_t x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};
unordered_map<ll, int, splitmix64> mp;
void solve() {
  int n = read();
  for(int i = 1; i <= n; i ++ ) a[i] = read(), mp[a[i]] ++;
  sort(a + 1, a + 1 + n);
  array<ll, 2> ans1 = {-1, -1};
  array<ll, 3> ans2;
  ll ans = a[1];
  for(int i = 2; i <= n; i ++ ) {
    for(int j = 0; j <= 31; j ++ ) {
      bool flag = false;
      if(mp.count(a[i] - (1ll << j))) {
        // println(a[i]); puts("FUCK");
        // print(a[i]); putchar(' '); println(a[i] - (1ll << j));
        ans1 = {a[i], a[i] - (1ll << j)};
        flag = true;
      } 

      if(mp.count(a[i] + (1ll << j))) {
        // println(a[i]);
        ans1 = {a[i], a[i] + (1ll << j)};
        if(flag) {
          println(3);
          print(a[i] - (1ll << j)); putchar(' ');
          print(a[i]); putchar(' ');
          print(a[i] + (1ll << j)); putchar(' ');
          return ;
        }
      } 

    }
  }

  if(ans1[0] == -1 && ans1[1] == -1) {
    println(1);
    print(a[1]); putchar(' ');
    return ;
  } else {
    println(2);
    print(ans1[0]); putchar(' ');
    print(ans1[1]); putchar(' ');
    return ;
  }
  


}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
