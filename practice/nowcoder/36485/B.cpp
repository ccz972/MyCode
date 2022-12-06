#include <bits/stdc++.h>
#include <debugger>
using namespace std;

vector<int> add(vector<int>& a, vector<int> b) {
  vector<int> ans;
  int n = a.size(), m = b.size();

  int t = 0;
  reverse(b.begin(), b.end());
  for(int i = 0; i < n || i < m; i ++ ) {
    if(i < n) t += a[i];
    if(i < m) t += b[i];
    ans.push_back(t % 10);
    t /= 10;
  }
  if(t) ans.push_back(t);
  while(ans.back() == 0) ans.pop_back();
  if(ans.empty()) ans.push_back(0);
  return ans;
}

bool sgn(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();
  if(n < m) return true;
  if(n > m) return false;
  for(int i = n - 1; i >= 0; i -- ) {
    if(a[i] < b[i]) return true;
    if(a[i] > b[i]) return false;
  } 

  return true;

}

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<int> a(n + 1);
  for(int i = 0; i < n; i ++ ) a[i + 1] = (s[i] - '0');
  vector<vector<vector<int> > > f(m + 10, vector<vector<int> > (n + 10, vector<int>()));

  f[0][0].push_back(0);
  int x = n / (m + 1);
  int y = n % (m + 1);

  vector<int> L;
  for(int i = x - 10; i <= x + 10; i ++ ) if(i >= 1 && i <= n) {
    L.push_back(i);
  }
  int l = L[0], r = L.back();

  for(int i = 0; i <= m; i ++ ) {
    for(int j = 0; j <= n; j ++ ) if(!f[i][j].empty()) {
      vector<int> p; 
      for(int k = 1; k < l && j + k <= n; k ++ ) {
        p.push_back(a[j + k]);
      }
      for(int k = l; k <= r && j + k <= n; k ++ ) {
        p.push_back(a[j + k]);
        if(f[i + 1][j + k].empty()) {
          f[i + 1][j + k] = add(f[i][j], p);
        } else {
          auto Now = add(f[i][j], p);
          if(!sgn(f[i + 1][j + k], Now)) {
            f[i + 1][j + k] = Now;
          }
        }
      }

      // for(int k = j + 1; k <= n && n - k >= m - i; k ++ ) {
      //   p.push_back(a[k]);
      //   if(f[i + 1][k].empty()) {
      //     f[i + 1][k] = add(f[i][j], p);
      //   } else {
      //     auto Now = add(f[i][j], p);
      //     if(!sgn(f[i + 1][k], Now)) {
      //       f[i + 1][k] = Now;
      //     }
      //   }
      //   // debug(i + 1, k, f[i + 1][k]);
      // }
    }
  }

  auto Now = f[m + 1][n];
  int st = Now.size() - 1;
  while(Now[st] == 0) st --;
  for(int i = st; i >= 0; i -- ) {
    cout << Now[i];
  }
  
}

int main() {
  freopen("data.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("out.txt", "w", stdout);
  solve();
  return 0;
}