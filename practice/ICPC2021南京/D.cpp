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
#define int ll 
class fenwick {
public:
  vector<int> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, int v) {
    while (x < n) {
      // chkmax(fenw[x], 1);
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  int get(int x) {
    int v = 0;
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

void solve1() {
  int n; cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  vector<int> cnt(n + 10);
  fenwick fen(n + 100);
  cout << "0";
  int mx = a[0];
  int last = 0;
  fen.modify(a[0], 1);
  cnt[a[0]] ++;
  int last_twice = -1;
  for (int i = 1; i < n; i ++ ) {
    cout << " ";
    if (a[i] == mx) {
      cout << last;
      if (last_twice == -1) {
        last_twice = i;
      }
    } else if (a[i] > mx) {
      last += 2;
      if (last_twice == -1) {
        last_twice = -1;
      }  else {
        last += i - last_twice;        
        last_twice = -1;
      }
      mx = a[i];
      cout << last;
    } else {
      last += fen.get(a[i] + 1, n + 10);
      cout << last;
    }
    int val = fen.get(a[i]) - fen.get(a[i] - 1);
    fen.modify(a[i], 1 - val);
    cnt[a[i]] ++;
    // if (i != n - 1) cout << " ";
    // cout << " \n"[i == n - 1];
  }
  cout << "\n";
  
}


void solve() {
  int n; cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  vector<int> cnt(n + 10);
  fenwick fen(n + 100);
  cout << "0 ";
  int mx = a[0];
  int last = 0;
  fen.modify(a[0], 1);
  cnt[a[0]] ++;
  for (int i = 1; i < n; i ++ ) {
    if (a[i] == mx) {
      cout << last << " ";
    } else if (a[i] > mx) {
      last += 1 + cnt[mx];
      mx = a[i];
      cout << last << " ";
    } else {
      
      last += fen.get(a[i] + 1, n + 10);
      // last ++;
      cout << last << " ";
    }
    int val = fen.get(a[i]) - fen.get(a[i] - 1);
    fen.modify(a[i], 1 - val);
    // cout << "\n > : " << fen.get(n + 10) << "\n";
    cnt[a[i]] ++;
  }
  cout << "\n";
  
}




signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- )
  solve1();
  return 0;
}