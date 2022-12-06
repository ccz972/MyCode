#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()

int get(char c) {
  if (c <= '9') return c - '0'; //10 - 35
  if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
  return c - 'a' + 36;
}

vector<int> mul(vector<int> a, int ml, int k) {
  // vector<int> ans;
  reverse(all(a)); int n = SZ(a);
  int t = 0;
  for (int i = 0; i < n; i ++ ) {
    auto bit = a[i] + t;
    bit *= ml;
    a[i] = bit / k;
    t = bit % k;
  }
  while (t) {
    a.push_back(t % k);
    t /= k;
  }
  while (SZ(a) > 1 && a.back() == 0) a.pop_back();
  reverse(all(a));
  return a;
}

vector<int> div(vector<int> a, int dv, int k, int &mod) {
  int n = SZ(a);
  int now = 0;
  vector<int> b;
  for (int i = 0; i < n; i ++ ) {
    now = now * 10 + a[i];
    int j = i;
    while (j + 1 < n && now < dv) {
      b.push_back(0);
      ++ j;
      now = now * 10 + a[j];
    }    
    b.push_back(now / dv);
    now %= dv;
    i = j;
  }
  mod = now;
  reverse(all(b));
  while (SZ(b) > 1 && b.back() == 0) b.pop_back();
  reverse(all(b));
  return b;
}

void print(vector<int> &a) {
  for (int &x: a) cout << x;
  cout << "\n";
}

vector<int> get(vector<int> &a, int k) {
  vector<int> ans;
  reverse(all(a)); int n = SZ(a);
  int t = 0;
  for (int i = 0; i < n; i ++ ) {
    t += a[i];
    ans.push_back(t % 10);
    t /= 10;
  }
  while (t) {
    ans.push_back(t % 10);
    t /= 10;
  }
  while (SZ(ans) > 1 && ans.back() == 0) ans.pop_back();
  return ans;
}

void solve() {
  int x, y; cin >> x >> y;
  string s; cin >> s;
  int n = SZ(s);
  vector<int> a(n);
  for (int i = 0; i < n; i ++ ) a[i] = get(s[i]);
  auto b = get(a, x);
  print(b);
  // int mod = 0;
  // auto b = div(a, x, x, mod);
  // print(b);
  // cout << mod << "\n";
}
//

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}