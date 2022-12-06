#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];
// 1 index
void solve1() {

  cin >> n >> p + 1 >> m >> s + 1;

  for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
  }

  for (int i = 1, j = 0; i <= m; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == n) {
      printf("%d ", i - n);
      j = ne[j];
    }
  }
}
// 0 index
void solve2() {

  cin >> m >> p >> n >> s;

  ne[0] = -1;
  for (int i = 1, j = -1; i < m; i++) {
    while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
    if (p[j + 1] == p[i]) j++;
    ne[i] = j;
  }

  for (int i = 0, j = -1; i < n; i++) {
    while (j != -1 && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m - 1) {
      cout << i - j << ' ';
      j = ne[j];
    }
  }

}



