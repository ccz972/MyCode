#include <bits/stdc++.h>
using namespace std;
#define SZ(s) ((int)s.size())
#define all(a) (a).begin(), (a).end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define PII pair<int, int>

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

constexpr int N = 1E5 + 10;

int n, a[N];
bool vis[N];
// pair<int, int> f[N];
int m;
vector<pair<int, int> > f[N];
int solve(int n) {
  int now = 0;
  if (is_sorted(a + 1, a + 1 + n)) {
    return 0;
  }
  while (true) {
    if (is_sorted(a + 1, a + 1 + n)) {
      break;
    }
    m = 0;
    rep(i, 1, n) vis[i] = false;
    rep(i, 1, n) if (a[i] != i) {
      int idx1 = i, idx2 = a[i];
      if (!vis[idx2]) {
        swap(a[idx1], a[idx2]);
        vis[idx1] = vis[idx2] = true;
        f[now].push_back({idx1, idx2});
      }
    }
    assert(!f[now].empty());
    ++ now;
  }
  return now;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n; int mxx = 0;
 

  vector<int> b(n);
  for(int i = 0; i < n; i ++) b[i] = i + 1;
  do{
    for(int i = 1; i <= n; i ++) a[i] = b[i - 1];
    mxx = max(mxx, solve(n));
  }while(next_permutation(all(b)));
  cout << mxx;
  return 0;
}