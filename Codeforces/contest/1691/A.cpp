#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;scanf("%d", &n);
  vector<int> a(n);
  for(int &x: a) scanf("%d", &x);
  //1 1 0 0 1 0 1
  int ans = 0;
  for(int x: a) ans += (x & 1);
  cout << min(ans, n - ans) << "\n";
  // int x = a[0] & 1; int ans = 0;
  // for(int i = 1; i < n; i ++ ) {
  //   if((a[i] + x) & 1) continue;
  //   ans ++;
  //   while(i + 1 < n && ((a[i + 1] + x) & 1)) {
  //     ++ i;
  //     ans ++;
  //   }

  // }
  // int ans2 = 0;

}
int main() {
  int T; scanf("%d", &T);
  while(T -- ) solve();
}