#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
/*

  -C

  B
  A-B
  3B-A
  4B-2A
  5B-2A
  6B-3A
  7B-3A
  8B-4A
  9B-4A

  B-(A-B)=2B-A+B = 3B-A
  



  C

  A-2B
  2B-A
  2A-3B
  2A-4B
  3A-5B
  3A-6B
  4A-7B
  4A-8B


*/

  /*
     B-C                   A-B-C
A-B  A-2B+C                2B-A+C 
B    3B-A-C                2A-3B+C
A-B  2A-4B+C               4B-2A-C
B    5B-2A-C               A-B-4B+2A+C= 3A-5B + C
A-B  A-B-5B+2A+C=3A-6B+C   6B-3A-C
B    7B-3A-C               A-B-6B+3A+C= 4A-7B+C
A-B  A-B-7B+3A+C=4A-8B+C   8B-4A-C    
B    
A-B

  */
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}