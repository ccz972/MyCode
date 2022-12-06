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

int a[1000];

void solve() {

  int n; cin >> n;
  bitset<50> b(n);
  for(int i = 0; i < 50; i ++ ) cout << b[i];
  cout << "\n";
  int idx = 0;
  for(int i = 0; i < 50; i ++ ) if(b[i]) {
    idx = i;
  }
  //2
  for(int i = idx; i >= 0; i -- ) {
    int j = i;
    while(j > 0 && b[j - 1] == 0) -- j;
    //
    int len = i - j + 1;
    int l = len / 2 + (len & 1), r = len / 2;
    //2 ^ l, 2 ^ r



    i = j;
  }

  // 1 + 2
  // 3 4 (1 2)
  // for(int i = )

  /*
  13331

  1 + (2 * (1 + 2 * (2 * (2 * (1 + 2 * (2 * (2 * (2 * (2 * (2 * (1 + 2 * (2 * (1 + 2 * 1)))))))))) ) ))


  1 + (2 * (1 + 2 * (2 * (2 * (1 + 2 * (2 * (2 * (2 * (2 * (2 * ))))))) ) ))

  6 * 2  

  ((4  3)  +  1) * 2
    ((4 + 3 +  2)  + 2) // 2 

    ((4 + 3 +  2)  + 2 + 2) // 2 

  
  131

  1 + 2 * (1 + 2 * 2 * 2 * 2 * 2 * 2) 

  2^k * 3 = 2{k+1}

  (8 * 8) + 2 
  (8+8+2) + 2 + 2  //2 

  (([17, 18] 87654321 [16,9]) [20, 19]) //lis = 3
  [] (([17, 18] 87654321 [16,9]) [20, 19]) 
  deque

  30 * 2
    +2

  */  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}