#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3E5 + 10;

int n, m, Case;
char s[N], str[N];
int p[N], Left[N], Right[N];

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void manacher() {
  int rt = 0, mid = 0;
  for(int i = 1; i <= m; i ++ ) {
    p[i] = i < rt ? min(p[2 * mid - i], rt - i) : 1;
    while(str[i + p[i]] == str[i - p[i]]) ++ p[i];
    if(i + p[i] > rt) {
      rt = i + p[i];
      mid = i;
    }
    chkmax(Left[i + p[i] - 1], p[i] - 1);
    chkmax(Right[i - p[i] + 1], p[i] - 1);
  }
}

int main() {
  str[0] = '!', str[1] = '#';
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0; i < n; i ++ ) {
    str[i * 2 + 2] = s[i];
    str[i * 2 + 3] = '#';
  }
  m = n * 2 + 1;
  str[m + 1] = '@';
  manacher();
  for (int i = 1; i <= m; i += 2) chkmax(Right[i], Right[i - 2] - 2);
  for (int i = m; i >= 1; i -= 2) chkmax(Left[i], Left[i + 2] - 2);
  int ans = 0;
  for (int i = 1; i <= m; i += 2) if (Left[i] && Right[i]) {
    chkmax(ans, Left[i] + Right[i]);
  }
  cout << ans << "\n";
  

  return 0;
}

