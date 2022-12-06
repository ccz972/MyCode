#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }
int n, k; 
void solve();
string gao1(string s, int k, int idx1, int idx2) {
  int cost1 = n - idx1;
  if(cost1 > k) return s;
  s[idx1] ^= '1' ^ '0';
  s.back() ^= '1' ^ '0';
  return s;
}
string gao2(string s, int k, int idx1, int idx2) {
  if(idx2 > k) return s;
  s[idx2] ^= '1' ^ '0';
  s[0] ^= '1' ^ '0';
  return s;
}

string gao3(string s, int k, int idx1, int idx2) {
  int cost1 = n - idx1, cost2 = idx2;
  if(cost1 + cost2 > k) return s;
  s[idx1] ^= '1' ^ '0';
  s.back() ^= '1' ^ '0';
  if(idx1 != idx2) {
    s[idx2] ^= '1' ^ '0';
    s[0] ^= '1' ^ '0';
  }
  return s;

}

string nogao(string s, int k, int idx1, int idx2) {
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1; cin >> T; 
  while(T -- ) solve();
  return 0;
}

void solve() {
  cin >> n >> k;
  string s; cin >> s;

  int idx1 = -1; int idx2 = -1;
  for(int i = n - 1; i >= 0; i -- ) if(s[i] == '1') {
    idx1 = i;
    break;
  }
  for(int i = 0; i < n; i ++ ) if(s[i] == '1') {
    idx2 = i;
  }

  if(idx1 == -1) {
    cout << "0\n";
    return ;
  }

  auto get = [&] (string p) {
    int A = 0;
    for(int i = 1; i < n; i ++ ) A += (p[i - 1] - '0') * 10 + (p[i] - '0');
    // debug(s);
    return A;
  };
  // 00001   100000
  cout << min({get(gao1(s, k, idx1, idx2)), get(gao2(s, k, idx1, idx2)), get(gao3(s, k, idx1, idx2)), get(nogao(s, k, idx1, idx2))}) << "\n";
  
  
  //1110     32
  //1101     22

  //1010

  //0110
  //1010
  //0101

  //1001
  //10000000011111000
  //-------

  //  10101
  //  10011
  // 000010011000    1


 /*
  * 0000 -> 0
  * 0001 -> 1
  * 0011 1010  1001 
  0000110000  
  */

}