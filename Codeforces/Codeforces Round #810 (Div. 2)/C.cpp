/***************************************************

@File    : C.cpp
@Time    : 2022/07/24 23:00:51
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<ll> a(k);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if(n == 1 || m == 1) {
      cout << "No\n";
      return ;
    }

    vector<ll> col, row;
    int N = n, M = m;
    bool flagn = true, flagm = true;
    for(int i = 0; i < k; i ++ ) {
      ll res1 = a[i] / m;
      ll res2 = a[i] / n;

      if(res1 > 1) {
        N -= 2;
        res1 -= 2;
        if(res1) col.push_back(res1);
      }

      if(res2 > 1) {
        M -= 2;
        res2 -= 2;
        if(res2) row.push_back(res2);
      }

      if(N == 1) {
        if(!col.empty()) {
          cout << "Yes\n"; return ;
        } else {
          flagn = false;
          // cout << "No\n"; return ;
        }
      }

      if(M == 1) {
        if(!row.empty()) {
          cout << "Yes\n"; return ;
        } else {
          flagm = false;
        }
      }
    }


    ll sumn = 0, summ = 0;
    for(auto x: col) sumn += x;
    for(auto x: row) summ += x;
    
    if((sumn >= N && flagn) || (summ >= M && flagm)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }

    // vector<ll> col1, col2, row1, row2;
    // vector<vector<ll> > col(vector<ll>(2)), row(vector<ll>(2));
    // ll sumcol = 0, sumrow = 0;
    // for(int i = 0; i < k; i ++ ) {
    //   ll res1 = a[i] / m;
    //   ll res2 = a[i] / n;
    //   if(res1 > 1) {
    //     col[res1 & 1].push_back(res1);
    //     sumcol += res1;
    //   }
    //   if(res2 > 1) {
    //     row[res2 & 1].push_back(res2);
    //     sunrow += res2;
    //   }
    // }

    // if(~n & 1) { //n是偶数
    //   if(sumcol >= n) {
    //     cout << "Yes\n"; return ;
    //   }

    // } 
    // if(~m & 1) {
    //   if(sumrow >= m) {
    //     cout << "Yes\n"; return ;
    //   }
    // }

    //n       col
    


    
  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}