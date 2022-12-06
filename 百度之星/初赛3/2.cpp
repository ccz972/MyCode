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
const int N = 1e6 + 10;

int cnt;
int primes[N + 1];
bool st[N + 1];

void solve() {
  int n; cin >> n;
  set<ll> s;
  for(int i = 2; i <= N; i ++ ) {
    if(!st[i]) {
      primes[cnt ++ ] = i;
      s.insert(1ll * i * i);
    }
    for(int j = 0; primes[j] <= N / i; j ++ ) {
        st[primes[j] * i] = true;
        if(i % primes[j] == 0) break; 
    }
  }
  
  while (n -- ) {
    ll x; cin >> x;
    if (s.count(x)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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
