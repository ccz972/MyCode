#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// string operator + (string a, string b) {
//   // string s = a;
//   // reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
//   while(a.size() > 1 && a.back() == '0') a.pop_back();
//   while(b.size() > 1 && b.back() == '0') b.pop_back();
//   int n = a.size(), m = b.size();
//   string s; int t = 0;
//   for(int i = 0; i < n || i < m; i ++ ) {
//     if(i < n) t += (a[i] - '0');
//     if(i < m) t += (b[i] - '0');
//     s += (char)('0' + t % 10);
//     t /= 10;
//   }
//   while(t) {
//     s += (char)('0' + t % 10);
//     t /= 10;
//   }
//   while(s.size() > 1 && s.back() == '0') s.pop_back();
//   return s;
// }

void solve() {
  int n; cin >> n;
  
  if(n == 1) {
    cout << "0\n";
    return ;
  }
  

  auto chk = [&] (string &x, string &y) {
    int i = 0, lx = x.size(), ly = y.size();
    while(i < ly) {
      if(x[i] != y[i]) { 
        return false;
      }
      i ++;
    }
    return true;
  };

  string now = "1";
  int ans = 1;
  ull mx = 0;
  for(int i = 2; i <= n; i ++ ) {
    ull a = i % n;
    for(int j = 0; ; j ++ ) {
      if(j) a += n;
      string p = to_string(a);
      if(chk(p, now)) {
        ans += p.size() - now.size();
        // s.insert(j);
        // chkmax(mx, a);
        debug(i - 1, i, a, n); 
        break;
      }
    }
    now = to_string(i);  
  }
  
  // cout << mx << "\n";
  cout << mx << "\n";
  // for(int x: s) cout << x << " ";
  // cout << "\n";
  // cout << s.size() << "\n";

  cout << ans << "\n";

}
int main() {

#ifdef LOCAL
  freopen("1.txt", "w", stdout);
#else 
  cin.tie(nullptr)->sync_with_stdio(false);
#endif

  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
