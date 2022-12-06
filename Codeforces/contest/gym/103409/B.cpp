#include <bits/stdc++.h>
using namespace std;
#define ll long long



void solve() {
  int n, q; cin >> n >> q;
  string s, t; cin >> s >> t;
  // reverse(s.begin(), s.end());

  vector<int> p(n + 1);
  iota(p.begin(), p.end());
  function<int(int)> find = [&] (int x) {
    if(p[x] != x) p[x] = find(p[x]);
  };  

  vector<bool> vis(n + 1);
  vector<int> now(n + 1);
  int t = 0;
  for(int i = n - 1; i >= 0; i -- ) {
    now[i] = (s[i] - '0' + t[i] - '0' + t);
    if(now[i] >= 10) {
      vis[i] = true;
      if(vis[i + 1])
        p[find(i + 1)] = find(i);
      t = 1;
    } else {
      t = 0;
    }
  }
  
  while(q -- ) {
    int r, c, d; cin >> r >> c >> d;
    //把第 r 行 第 c 个数字 改为 d
    if (r == 1) {
      if(s[c - 1] - '0' == d) {
        cout << now[c - 1] << " 0\n";
      } else {
        int res = d - '0' + t[c - 1] - '0' + vis[c];
        if (res >= 10) {
          if (vis[c - 1]) { //当前位之前就可以进位
            cout << res % 10 << " " << 2 << "\n";
          } else { //当前位置不能进位
            if(vis[c - 2]) { //当前位置的前一个之前就可以进位
              cout << res % 10 << " " << 3 << "\n"; //只会改变三个
            } else if(s[c - 2] - '0' + t[c - 2] - '0' + 1 >= 10) { //前一位因为当前位置进位才可以进位
              cout << res % 10 << " " <<  c - find(c - 3) << "\n";
            } else {
              cout << res % 10 << " " << 3 << "\n";
            }
          }
        } else { //当前位置改变之后不能进位
          if(vis[c - 1]) {

          } 

        }
        // if(now[c - 1] + d )
      }
    } else {

    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
} 