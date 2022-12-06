#include <bits/stdc++.h>


using namespace std;

constexpr int N = 2e6 + 10;
constexpr int M = N * 2;

int ne[N], nextval[N], last;
char s[N], t[N];

void add(char x) {
  int j = last;
  while (j && s[ne[j] + 1] != x) j = nextval[j]; //kmp过程
  //把当前字符加进 s 
  //
  s[++last] = x, j = ne[j] + 1;
  if (last == 1) {
    ne[1] = nextval[1] = 0;
  } else if (s[j] == x) {
    ne[last] = j;
    if (s[ne[j] + 1] == s[j + 1]) {
      nextval[last] = nextval[j];
    } else {
      nextval[last] = j;
    }
  } else {
    ne[last] = nextval[last] = 0;
  }
}

void solve() {
  cin >> t;
  int len = strlen(t);
  // cout<<t<<endl;
  for (int i = 0; i < len; i++) add(t[i]);
  int q;
  cin >> q;
  while (q--) {
    cin >> t;
    len = strlen(t);
    for (int i = 0; i < len; i++) add(t[i]), cout << ne[last] << ' ';
    cout << "\n";
    last -= len;
  }
}

int main() {
  ios;
  int T = 1;
  // cin>>T;

  while (T--) {
    solve();
  }

  return 0;
}