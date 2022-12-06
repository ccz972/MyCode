#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
  #include <debugger>
#endif

void solve() {
  string a, b; cin >> a >> b;
  int n = a.size();
  vector<int> now(n + 1);
  for(int i = n - 1; i >= 0; i -- ) {
    if(a[i] != b[i]) {
      now[i] = 1;
    }
  }
  now[n] = 0;
  for(int i = n - 1; i >= 0; i -- ) now[i] += now[i + 1];
  string s(n, '0');
  int cnt = 0;
  for(int i = 0; i < n; i ++ ) {
    if(a[i] == b[i]) {
      s[i] = 'a';
    } else if(a[i] == 'a' && b[i] != 'a') {
      if(abs(cnt + 1) <= now[i + 1]) {
        s[i] = 'a';
        cnt ++; 
      } else if(abs(cnt) <= now[i + 1]) {
        if(b[i] == 'b' && abs(cnt - 1) <= now[i + 1]) {
          s[i] = 'b';
          cnt --;
        } else if(b[i] != 'b') {
          s[i] = 'b';
        } else {
          s[i] = 'c';
        }
      } else {
        s[i] = b[i];
        cnt --;
      }
    } else if(b[i] == 'a' && a[i] != 'a') {
      if(abs(cnt - 1) <= now[i + 1]) {
        s[i] = 'a';
        cnt --; 
      } else if(abs(cnt) <= now[i + 1]) {
        if(a[i] == 'b' && abs(cnt + 1) <= now[i + 1]) {
          s[i] = 'b';
          cnt ++;
        } else if(a[i] != 'b') {
          s[i] = 'b';
        } else {
          s[i] = 'c';
        }
      } else {
        s[i] = a[i];
        cnt ++;
      }
    } else {
      if(abs(cnt) == now[i]) {
        if(cnt > 0) {
          s[i] = b[i];
          cnt --;
        } else if(cnt < 0) {
          s[i] = a[i];
          cnt ++;
        } 
      } else {
        s[i] = 'a';
      }
    } 

    
  }
  
  cout << s ;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  for(int i = 1; i <= T; i ++ ) {
    cout << "Case " << i << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}