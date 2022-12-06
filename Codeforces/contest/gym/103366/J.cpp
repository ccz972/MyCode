#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i(a); i <= b; ++ i)

constexpr int N = 1e5 + 10;

int n, k;
int a[N]; 
bool vis[N];

bool chk(int x) {
  map<int, int> mp;
  int cnt = 0;
  memset(vis, 0, sizeof vis);  
  // set<int> s;
  for(int i = 0, j = -1; i < n; i ++ ) {
    while(j < n - 1 && mp.size() < x + 1) {
      ++ j;
      // mp[a[j]] ++;
      if(i != j && a[i] == a[j]) {
        vis[j] = true;
      }
    }

    // if(!s.count(a[i])) {
    // if(!vis[i])
    //   cnt += mp[a[i]] - 1;
    //   s.insert(a[i]);
    // }
    // cout << i << " " << j << " " << mp.size() << " " << cnt << "\n";
    mp[a[i]] --;
    if(!mp[a[i]]) {
      mp.erase(a[i]);
    }
  }
  for(int i = 0; i < n; i ++ ) {
    cnt += vis[i];
  }
  // exit(0);
  return cnt >= k;
}

void solve() {
  cin >> n >> k;
  rep(i, 0, n - 1) cin >> a[i];
  int l = 1, r = n;
  while(l < r) {
    int mid = (l + r) / 2;
    if(chk(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}