#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  auto b = a;
  for (int k = 1; k <= n; k ++ ) {
    int now = 0;
    a = b;
    for (int i = 0; i < k; i ++ ) {
      for (int j = 0; j < k; j ++ ) {
        if (a[i] < a[j]) {
          ++ now;
          swap(a[i], a[j]);
        }  
      }
    }
    cout << now << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- )
  solve();
  return 0;
}