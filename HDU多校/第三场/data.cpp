#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int T = 1;
  cout << T << "\n";
  // int n = rng() % 10 + 1, k = rng() % n + 1;
  int n = rng() % 300000 + 1;
  cout << n << "\n";
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  vector<int> b(n);
  iota(b.begin(), b.end(), 1);
  srand(time(0));
  random_shuffle(a.begin(), a.end());
  b = a;
  random_shuffle(b.begin() + n / 2, b.end());
  
  for(int x: a) cout << x << " ";
  cout << "\n";
  for(int x: b) cout << x << " ";
  cout << "\n";

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<int> p;
  int q = 2 * n;
  while(q -- ) {
    if(!a.empty() && !b.empty()) {
      int l = rand() % 100;
      if(l & 1) {
        p.push_back(a.back()); a.pop_back();
      } else {
        p.push_back(b.back()); b.pop_back();
      }
    } else if(a.empty()) {
      while(b.size()) {
        p.push_back(b.back()); b.pop_back();
      }
      break;
    } else if(b.empty()){
      while(a.size()) {
        p.push_back(a.back()); a.pop_back();
      }
      break;
    } else {
      break;
    }
  }
  // vector<int> p(n * 2); 
  // for(int i = 0; i < n; i ++ ) {
  //   p[i] = p[i + n] = i + 1;
  // }
  // random_shuffle(p.begin(), p.end());
  // random_shuffle(p.begin(), p.end());
  // random_shuffle(p.begin(), p.end());
  // random_shuffle(p.begin(), p.end());
  // random_shuffle(p.begin(), p.end());
  for(int x: p) cout << x << " ";



  // cout << n << " " << k << "\n";
  // for(int i = 1; i <= n; i ++ ) {
  //   int l = rng() % 10 + 1, r = rng() % 10 + l;
  //   cout << l << " " << r << "\n";
  // }


}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
