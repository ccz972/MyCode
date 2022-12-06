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

constexpr int N = 1E5 + 10;
constexpr int P = 1E9 + 7;
constexpr int inv = 500000004;
int n, a[N];
ll pow10[N];
char s[N];

template<typename T> 
void add(T &x, T y) {
  x += y;
  if (x >= P) x -= P;
}

void solve() {

  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i ++ ) a[i] = (s[i] - '0');
  pow10[1] = 1;
  for (int i = 2; i <= n; i ++ ) pow10[i] = pow10[i - 1] * 10 % P;


  ll ans = 0, res = 0;  
  for (int i = n; i >= 1; i -- ) {
    ll ret = ((((((pow10[n - i + 1] * i % P) * (i - 1)) % P) * inv) % P) * a[i]) % P;
    add(ans, ret);
    add(ans, (res * a[i]) % P);
    add(res, (pow10[n - i + 1] * (n - i + 1)) % P);
  }
  
  cout << ans << "\n";

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
