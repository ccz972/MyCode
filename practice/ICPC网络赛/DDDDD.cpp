#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve3() {
  int l, r; cin >> l >> r; int n = __lg(r) + 1;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i ++ ) {
    a[n - i - 1] = (l >> i & 1);
    b[n - i - 1] = (r >> i & 1);
  }
  if (l <= 2 && 2 <= r) { cout << "2"; return ;  }
  if (l == r) { if ((__builtin_popcount(l) == __builtin_ctz(r))) cout << l; else cout << "-1"; return ;  }
  auto judge = [] (vector<int> &x, vector<int> &y) {
    int n = x.size();
    for (int i = 0; i < n; i ++ ) {
      if (x[i] > y[i]) return 1;
      else if (x[i] < y[i]) return -1;
    }
    return 0;
  };
  auto print = [] (vector<int> &x) {
    int now = 0;
    for (int P: x) now = now * 2 + P;
    cout << now;
  };

  auto check = [=] (vector<int> &x) {
    int now = 0;
    for (int P: x) now = now * 2 + P;
    if ((__builtin_popcount(now) == __builtin_ctz(now) )&& l <= now && now <= r) {
      cout << now;
      return true;
    } else {
      return false;
    }
  };

  // int Left = 0;
  // int lead = 0;
  // while (a[Left] == b[Left]) {
  //   if (a[Left] == 1) ++ Lead;
  //   ++ Left;
  // }
  for (int suf = 2; suf <= n / 2; suf ++ ) {
    vector<int> p(n);
      
    if (a[0] != b[0]) {
      p[n - 1 - suf] = 1;  
      //00001000
      //0001.....
      auto np = p;
      int st = 0; while (a[st] == 0) ++ st;
      if (st > n - 1 - suf) { //1000
        for (int j = 1; j < suf; j ++ ) {
          np[n - 1 - suf - j] = 1;
        }
        if (judge(b, np) >= 0 && judge(np, a) >= 0) {
          // cout << "tag1 ";
          print(np);
          return ;
        }  
      } else {
        // np[st - 1] = 1;
        // int use = suf - 2;
        if (n - 1 - suf - (st - 1) > suf) { //中间的够用
          np[st - 1] = 1;
          for (int j = 1; j <= suf - 2; j ++ ) {
            np[n - 1 - suf - j] = 1;
          }
          if (judge(b, np) >= 0 && judge(np, a) >= 0) {
            // cout << "tag2 ";
            print(np);
            return ;
          } 
        } else {
          //中间的不够用
          for (int j = 1; j < suf; j ++ ) {
            np[n - 1 - suf - j] = 1;
          }
          if (judge(b, np) >= 0 && judge(np, a) >= 0) {
            // cout << "tag3 ";
            print(np);
            return ;
          } 
        }
      }
    } else {
      int left = 0;
      int use = suf;
      while (a[left] == b[left]) {
        p[left] = a[left];
        if (a[left] == 1) -- use;
        ++ left;
      }
      if (use < 0) continue;

      if (left >= n - suf) {
        if (check(p)) return ;
      } else {
        if (!use) {
          continue;          
        } else {
          -- use;
          p[n - 1 - suf] = 1;  
          // print(p);
          //[left, n - 2 - suf]放剩下的 use
          
          int now = left;
          while (now + 1 <= n - 2 - suf && a[now + 1] == 0) ++ now;
          if (use && now != n - 1 - suf) {
            p[now] = 1;
            -- use;
          }
          // cout << use << " " << suf << "\n";
          for (int i = n - suf - 2, j = use; j > 0; j --, i --) {
            if (i == now) -- i;
            p[i] = 1;
          }

          if (judge(p, a) >= 0  && judge(b, p) >= 0) {
            print(p);
            return ;
          }
        }
      }
    }
  }
  cout << "-1";
  


}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    if (i != 1) cout << "\n" ;
    solve3();
  }
  return 0;
}