#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= b; ++ i)

int a[4][14];

void solve() {
  for (int i = 0; i < 4; i ++ ) {
    for (int j = 1; j <= 13; j ++ ) {
      int x; cin >> x; //cin >> a[i][j];
      a[i][x] ++;
    }
  }  
  int q; cin >> q;
  int now = 0;
  vector<vector<int>> cards;
  int card; 
  int people = 0;
  while (q -- ) {
    char c; cin >> c;
    if (c == 'S') {
      int x, y; cin >> x >> y; // y 个 x
      card = x;
      vector<int> p(y + 1); 
      for (int i = 0; i < y; i ++ ) {
        cin >> p[i];
        a[people][p[i]] --;
        assert(a[people][p[i]] >= 0);
      }
      p[y] = people; people = (people + 1) % 4;
      cards.emplace_back(p);
    } else if (c == '!') {
      int y; cin >> y;
      vector<int> p(y + 1);
      for (int i = 0; i < y; i ++ ) {
        cin >> p[i];
        a[people][p[i]] --;
        assert(a[people][p[i]] >= 0);
      }
      p[y] = people; people = (people + 1) % 4;
      cards.emplace_back(p);
    } else {
      auto p = cards.back();
      bool flag = true;
      for (int i = 0; i < (int)p.size() - 1; i ++ ) if (p[i] != card) {
        flag = false;
      }
      if (!flag) { 
        int PP = p.back();
        for (auto p: cards) {
          for (int i = 0; i < (int)p.size() - 1; i ++ ) {
            a[PP][p[i]] ++;
          }
        }
      } else {
        for (auto p: cards) {
          for (int i = 0; i < (int)p.size() - 1; i ++ ) {
            a[people][p[i]] ++;
          }
        }
      }
      cards.clear();
      people = (people + 1) % 4;
    }
  }
  for (int i = 0; i < 4; i ++ ) {
    vector<int> ans;
    for (int j = 1; j <= 13; j ++ ) {
      for (int k = 0; k < a[i][j]; k ++ ) {
        ans.emplace_back(j);
      }
    }
    for (int j = 0; j < (int)ans.size(); j ++ ) {
      cout << ans[j]; // << " \n"[j + 1 == (int)ans.size()];
      if (j + 1 != (int)ans.size()) cout << " ";
    }
    if(i != 3) {
      cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}