#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b, c; cin >> n >> a >> b >> c;
  int cnt = (!a) + (!b) + (!c);
  vector<string> s(n);
  for (auto &x: s) cin >> x;
  if (cnt == 3) {
    cout << "No\n"; return ;    
  } 
  vector<char> ans(n);
  for (int i = 0; i < n; i ++ ) {
    if (i == n - 1) {
      if (s[i] == "AB") {
        if (a <= b) {
          ans[i] = 'A';
          ++ a, -- b; if (b < 0) return cout << "No\n", void();
        } else {
          ans[i] = 'B';
          ++ b, -- a; if (a < 0) return cout << "No\n", void();
        }
      } else if (s[i] == "BC") {
        if (b <= c) {
          ans[i] = 'B';
          ++ b, -- c; if (c < 0) return cout << "No\n", void();
        } else {
          ans[i] = 'C';
          ++ c, -- b; if (b < 0) return cout << "No\n", void();
        }
      } else {
        if (a <= c) {
          ans[i] = 'A';
          ++ a, -- c; if (c < 0) return cout << "No\n", void();
        } else {
          ans[i] = 'C';
          ++ c, -- a;  if (a < 0) return cout << "No\n", void();
        }
      }
    } else {
      if (s[i] == "AB") {
        if (a < b) {
          ans[i] = 'A';
          ++ a, -- b; if (b < 0) return cout << "No\n", void();
        } else if (b < a) {
          ans[i] = 'B';
          ++ b, -- a; if (a < 0) return cout << "No\n", void();
        } else {
          if (a != 1 || s[i + 1] == "AB" || c > 0) {
            ans[i] = 'A';
            ++ a, -- b; if (b < 0) return cout << "No\n", void();
          } else { 
            if (s[i + 1] == "AC") { 
              ans[i] = 'A';
              ++ a, -- b; if (b < 0) return cout << "No\n", void();
            } else {
              ans[i] = 'B';
              ++ b, -- a; if (a < 0) return cout << "No\n", void();
            }
          }
        }
      } else if (s[i] == "BC") {
        if (b < c) {
          ans[i] = 'B';
          ++ b, -- c; if (c < 0) return cout << "No\n", void();
        } else if (c < b) {
          ans[i] = 'C';
          ++ c, -- b; if (b < 0) return cout << "No\n", void();
        } else {
          if (b != 1 || s[i + 1] == "BC" || a > 0) {
            ans[i] = 'B';
            ++ b, -- c; if (c < 0) return cout << "No\n", void();
          } else { 
            if (s[i + 1] == "AC") { 
              ans[i] = 'C';
              ++ c, -- b; if (b < 0) return cout << "No\n", void();
            } else {
              ans[i] = 'B';
              ++ b, -- c; if (c < 0) return cout << "No\n", void();
            }
          }
        }
      } else {
        if (a < c) {
          ans[i] = 'A';
          ++ a, -- c; if (c < 0) return cout << "No\n", void();
        } else if (c < a) {
          ans[i] = 'C';
          ++ c, -- a;  if (a < 0) return cout << "No\n", void();
        } else {
          if (a != 1 || s[i + 1] == "AC" || b > 0) {
            ans[i] = 'A';
            ++ a, -- c; if (c < 0) return cout << "No\n", void();
          } else { 
            if (s[i + 1] == "AB") { 
              ans[i] = 'A'; 
              ++ a, -- c; if (c < 0) return cout << "No\n", void();
            } else {
              ans[i] = 'C';
              ++ c, -- a;  if (a < 0) return cout << "No\n", void();
            }
          }
        }
      }
    }
  }
  cout << "Yes\n";
  for (char x: ans) cout << x << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; 
  while(T -- ) solve();
  return 0;
}