#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int N = 1010;

int cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s; cin >> s;
  int n = s.size();
  string tmp;
  ll l = 0, r = 0;
  char c = '0';
  for(int i = 0; i < n; i ++ ) {
    if(s[i] == '+' || s[i] == '-' || i == n - 1) {
      if(i == n - 1 && !(s[i] == '+' || s[i] == '-')) {
        tmp += s[i];
      }
      //opertion tmp
      if(tmp[0] == 'd') {
        int ct = 1, now = 0;
        for(int j = 1; j < tmp.size(); j ++ ) now = (now << 3) + (now << 1) + (tmp[j] - 48);
        if(now == 0) cout << tmp << "  FICHK!\n";
        cnt[now] += ct;
        if(c == '0') {
          l = 1, r = now;
        } else if(c == '-') {
          l -= now, r -= 1;
        } else {
          l += 1, r += now;
        }

      } else {
        bool f = false;
        for(char c: tmp) if(c == 'd') f = true;
        if(f) {
          int ct = 0, now = 0, j = 0;
          for( ; j < tmp.size() && tmp[j] != 'd'; j ++ ) ct = (ct << 3) + (ct << 1) + (tmp[j] - 48);
          for(j += 1; j < tmp.size(); j ++ ) now = (now << 3) + (now << 1) + (tmp[j] - 48);
          if(now == 0) cout << tmp << " FUCKOKKKK !\n";
          cnt[now] += ct;
          // ct  (ge)  now
          if(c == '0') {
            l = 1 * ct, r = now * ct;
          } else if(c == '-') {
            l -= now * ct, r -= 1 * ct;
          } else {
            l += 1 * ct, r += now * ct;
          }
        } else {
          int now = 0;
          for(int j = 0; j < tmp.size(); j ++ ) now = (now << 3) + (now << 1) + (tmp[j] - 48);
          if(c == '0') {
            l = now, r = now;
          } else if(c == '-') {
            l -= now, r -= now;
          } else {
            l += now, r += now;
          }
        }
        
      }
      tmp.clear();
      c = s[i];
    } else {
      tmp += s[i];
    }
  }

  for(int i = 0; i < N; i ++ ) if(cnt[i]) {
    cout << i << " " << cnt[i] << "\n";
  }

  cout << l << " " << r << "\n";

  

 
  return 0;
}