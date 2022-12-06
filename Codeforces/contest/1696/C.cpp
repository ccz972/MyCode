#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<array<int, 2> > A;

    for(int &x: a) {
      cin >> x;
      int cnt = 1;
      while(x % m == 0) {
        x /= m;
        cnt *= m;
      }
      if(A.empty()) {
        A.push_back({x, cnt});
      } else {
        if(x == A.back()[0]) {
          A.back()[1] += cnt;
        } else {
          A.push_back({x, cnt});
        }
      }
    }
    int k; cin >> k;
    vector<int> b(k);
    vector<array<int, 2> > B;
    for(int &x: b) {
      cin >> x;
      int cnt = 1;
      
      while(x % m == 0) {
        x /= m;
        cnt *= m;
      }

      if(B.empty()) {
        B.push_back({x, cnt});
      } else {
        if(x == B.back()[0]) {
          B.back()[1] += cnt;
        } else {
          B.push_back({x, cnt});
        }
      }
    }

    if(A == B) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
