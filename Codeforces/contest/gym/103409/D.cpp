#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i ++ ) {
    cin >> b[i];
  }


  vector<array<int, 2> > ans;


  for(int i = n; i >= 1; i -- ) if(a[i] != b[i]) {
    if(a[i] > b[i]) {
      cout << "-1\n";
      return ;
    }

    for(int j = i - 1; j >= 1; j -- ) if(a[j] != b[j]) {
      if(a[j] > a[i] && a[j] <= b[i]) {
        swap(a[i], a[j]);
        ans.push_back({j, i});
      }
      if(a[i] == b[i]) {
        break;
      }
    }

    if(a[i] != b[i]) {
      cout << "-1\n";
      return ;
    }
  }

  cout << (int)ans.size() << "\n";
  for(auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();
  return 0;
} 