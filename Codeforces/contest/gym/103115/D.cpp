#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;
ll a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r; cin >> n >> l >> r;
  string t; cin >> t;
  vector<int> p1(n);
  iota(p1.begin(), p1.end(), 0);
  function<int(int)> find1 = [&] (int x) {
    if(p1[x] != x) p1[x] = find1(p1[x]);
    return p1[x];
  };

  vector<int> p2(n);
  iota(p2.begin(), p2.end(), 0);
  function<int(int)> find2 = [&] (int x) {
    if(p2[x] != x) p2[x] = find2(p2[x]);
    return p2[x];
  };

  vector<bool> vis(n);
  
  for(int i = 0; i < n; i ++ ) {
    for(int j = i + l; j <= i + r && j < n; j = find1(j) + 1 ) {
      p2[find2(j)] = p2[find2(i)];
      vis[j] = true;
      if(vis[j - 1]) {
        p1[find1(j - 1)] = p1[find1(j)];
      }
    }
  }

  vector<vector<int> > son(n);
  for(int i = 0; i < n; i ++ ) {
    int f = find2(i);
    son[f].push_back(i);
  }

  for(int i = 0; i < n; i ++ ) if(!son[i].empty()) {
    string s;
    for(auto j: son[i]) {
      s.push_back(t[j]);
    }
    sort(s.begin(), s.end());
    int idx = 0;
    for(auto j: son[i]) {
      t[j] = s[idx ++];
    }
  }

  cout << t << "\n";

  return 0;
}