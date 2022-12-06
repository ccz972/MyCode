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

// struct node {
//   int x, y;
//   // bool operator < (const node &T) const {
//   //   if(y != T.y) return y > T.y;
//   //   return x > T.x;
//   // }
// };

// bool operator < (const node &a, const node &b) {
//   if(a.y != b.y) return a.y > b.y;
//   return a.x > b.x;
// }

#define PII pair<int, int>

bool operator < (const PII a, const PII b) {
  if(a.second != b.second) return a.second > b.second;
  return a.first < b.first;
}


void solve() {
  priority_queue<PII> q;
  q.push({1, 2});
  q.push({1, 10});
  cout << q.top().first << " " << q.top().second ;


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
