#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 10;

ll a[N];

ll ksm(ll a, ll b, ll p ) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ret % p;
}

void solve() {

  int n; cin >> n;
  for(int i = 0; i < n; i ++ ) {
    cin >> a[i];
  }

  if(n == 1) {
    if(a[0] == 0) {
      cout << "1\n";
    } else {
      cout << "-1\n";
    }
    return ;
  }

  ll i = 0;

  while(i < n && a[i] == (1ll << i)) {
    ++ i;
  }
  
  if(i == n) {
    cout << "-1\n";
    return ;
  }

  ll p = (1ll << i);

  if(p < a[i]) {
    cout << "-1\n";
    return ;
  }
  
  ll mod = p - a[i];

  if(i && mod <= a[i - 1]) {
    cout << "-1\n";
    return;
  }


  for(; i < n; i ++ ) if(a[i] != ksm(2, i, mod)) {
    cout << "-1\n";
    return;
  }

  cout << mod << "\n";



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();

  return 0;
}