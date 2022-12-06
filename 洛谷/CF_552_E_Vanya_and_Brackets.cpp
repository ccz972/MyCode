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
string s;

ll calc(string s) {
  stack<ll> num;
  stack<char> op;
  int n = s.size();
  for (int i = 0; i < n; i ++ ) {
    if (s[i] == '(') {
      op.push(s[i]);
    } else if (s[i] == ')') {
      while (op.top() != '(') {
        ll t1 = num.top(); num.pop();
        ll t2 = num.top(); num.pop();
        char OP = op.top(); op.pop();
        if (OP == '+') num.push(t1 + t2);
        else num.push(t1 * t2);
      }
      op.pop();
    } else if (isdigit(s[i])) {
      num.push(s[i] - '0');
    } else {
      while (!op.empty() && op.top() == '*') {
        ll t1 = num.top(); num.pop();
        ll t2 = num.top(); num.pop();
        char OP = op.top(); op.pop();
        if (OP == '+') num.push(t1 + t2);
        else num.push(t1 * t2);
      }
      op.push(s[i]);
    }
  }
  while (!op.empty()) {
    ll t1 = num.top(); num.pop();
    ll t2 = num.top(); num.pop();
    char OP = op.top(); op.pop();
    if (OP == '+') num.push(t1 + t2);
    else num.push(t1 * t2);
  }
  return num.top();
}

ll calc(int l, int r) {
  //(0,l)*(r,n-1)
  //..... * (l, r) * ....
  string t;
  for (int i = 0; i < n; i ++ ) {
    if (i == l) t += '(';
    if (i == r) t += ')';
    t += s[i];
  }
  if (r == n) t += ')';

  return calc(t);
}

void solve() {
  cin >> s;
  n = s.size();

  vector<int> left, right;
  left.emplace_back(0);
  right.emplace_back(n);
  for (int i = 1; i < n; i += 2) if (s[i] == '*') {
    left.emplace_back(i + 1);
    right.emplace_back(i);
  }
  //(a+b)*(c+d)
  ll ans = 0;
  for (int l: left) {
    for (int r: right) if (l < r) {
      chkmax(ans, calc(l, r));
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}