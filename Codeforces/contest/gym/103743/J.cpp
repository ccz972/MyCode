#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map<ull, ull> mp;

ull dfs(ull x) {
  if(x == 0ull) return 1ull;
  if(x == 1ull) return 1ull;
  if(x == 2ull) return 2ull;
  if(x == 3ull) return 1ull;
  if(mp.count(x)) return mp[x];
  mp[x] = dfs((x - 1) / 2) * dfs((x - 1) / 2 + ((x - 1) % 2));
  if((x - 1) & 1) mp[x] = mp[x] + mp[x];
  return mp[x];
}

void solve() {
  // ull n; cin >> n;
  // cout << dfs(n) << "\n";
  // mp.clear();
  for(int i = 100; i <= 1000; i ++ ) {
    if(dfs(i) == 0ull) {
      cout << i << "\n";
    }
  }
  
}
         
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  freopen("out.txt", "w", stdout);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}