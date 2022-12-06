#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define PII pair<int, int>
#define debug(x) cout << #x << " > " << x << "\n"
#define all(a) a.begin(), a.end()

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}
ll h,m,a;

ll get(ll t)
{
  
}

void solve() {
  cin>>h>>m>>a;
  ll ans = 0;
  for(ll l = 1,r = 1;l<=m;l=r+1)
  {
    r = min(get(l))
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}