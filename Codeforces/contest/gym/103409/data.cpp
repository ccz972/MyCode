#include <bits/stdc++.h>
using namespace std;
// #define ll long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n = rng() % 10 + 1;
  cout << n << "\n";
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i ++ ) {
    a[i] = b[i] = i + 1;
  } 
  // iota(a.begin(), a.end(), 1);
  // iota(b.begin(), a.end(), 1);
  while(a[0] != n)
    random_shuffle(a.begin(), a.end());
  while(b.back() < a.back())
    random_shuffle(b.begin(), b.end());
  for(int x: a) cout << x << " ";
  cout << "\n";
  for(int x: b) cout << x << " ";
  cout << "\n";
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  freopen("data.txt", "w", stdout);
  int T = rng() % 1000 + 1;
  cout << T << "\n";  
  // int T; cin >> T;
  while(T -- ) solve();
  return 0;
}