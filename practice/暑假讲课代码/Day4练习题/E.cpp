#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; int k; cin >> s >> k;
  string ans;
  int n = s.size();

  //m - k

  //8 1 5 4 2

  //m - k

  // x xx xxxxx
  //xxxxxxx

  //81542

  for(int i = 0; i < n; i ++ ) {
    int idx = i;
    if(k >= n - i) break; //我就要把剩下的数字全删了
    //i - k 
    for(int j = i + 1; j < n &&  j <= i + k; j ++ ) if(s[j] < s[idx]) {
      idx = j;
    }

    ans.push_back(s[idx]);
    //[i  idx-1] idx
    k -= idx - i;

    i = idx;
  }  
  
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while(T -- ) solve();

  return 0;
}