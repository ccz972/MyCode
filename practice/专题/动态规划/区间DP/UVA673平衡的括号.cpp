//url: https://www.luogu.com.cn/problem/UVA673

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
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  getchar();
  while (T--) {
    string s; //cin >> s;
    getline(cin, s);
    stack<char> stk;
    int n = s.size();
    // cout << n << "\n";
    bool flag = true;
    for (int i = 0; i < n && flag; i ++ ) {
      if (s[i] == '(' || s[i] == '[') {
        stk.push(s[i]);
      } else if(s[i] == ')') {
        if(stk.empty() || stk.top() != '(') {
          flag = false;
        } else {
          stk.pop();
        }
        
      } else {
        if(stk.empty() || stk.top() != '[') {
          flag = false;
        } else {
          stk.pop();
        }
      }
    }

    if(!stk.empty()) flag = false;

    if(flag) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}