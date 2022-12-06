#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
int n;
void solve() {
  vector<int> cnt0(n), cnt1(n);
  for(int i = 0; i < 3 * n; i ++ ) {
    int idx; string s; cin >> idx >> s;
    if(idx >= n) continue;
    if(s[0] == 'Y') {
      cnt1[idx] ++;
    } else {
      cnt0[idx] ++;
    }
  }
  string s(n, '?');
  bool flag = false;
  int cnt = 0;
  vector<bool> st(n);
  for(int i = 0; i < n; i ++ ) {
    if(cnt0[i] + cnt1[i] == 1) { 
      st[i] = true;
      ++ cnt;
    } else if(!cnt0[i] && !cnt1[i]) {
      cout << "-1\n"; return ;
    } else if(!cnt0[i]) {
      s[i] = '1';
    } else if(!cnt1[i]) {
      s[i] = '0';
    } else {
      //1 1 
      if(cnt0[i] == 1 && cnt1[i] == 1) {
        cout << "-1\n"; return ;
      }

      if(cnt0[i] > 1 && cnt1[i] > 1) {
        cout << "-1\n"; return ;
      }

      if(cnt0[i] == 1 || cnt1[i] == 1) {
        if(cnt0[i] == 1) s[i] = '1';
        else s[i] = '0';
        flag = true;
      }
      
    }
  }  
  
  if(flag) { 
    for(int i = 0; i < n; i ++ ) if(st[i]) {
      s[i] = (cnt0[i] ? '0' : '1');
    }
  } else {
    if(cnt) {
      cout << "-1\n";
      return ;
    }
  }
  
  // for(int i = 0; i < n; i ++ )

  cout << s << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(cin >> n) solve();
  return 0;
}