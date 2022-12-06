#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for(int i(a); i <= b; ++ i) 
#define dec(i, a, b) for(int i(a); i >= b; -- i) 

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

//constexpr double pi = acos(-1);

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

void solve() {

  ll n; cin >> n;

  if(!n) {
    cout << "r";
    return ;
  }  
  int m = 0;
  dec(i, 50000, 0) {
    ll t = 1ll * i * (i + 1) / 2;
    int x = n / t;
    n %= t;
    m += x;
    if(x) 
      cout << string(x, 'r');
    if(m)
      cout << "ed";
  }
  
  cout << "\n";

}