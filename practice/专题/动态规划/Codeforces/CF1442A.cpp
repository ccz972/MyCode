#include <cstdio>
#include <algorithm>

template < typename T > inline void chkmax(T &x, T y) {x = x >= y ? x : y;}
template < typename T > inline void chkmin(T &x, T y) {x = x <= y ? x : y;}
template < typename T > inline T max(T x, T y) {return x >= y ? x : y;}
template < typename T > inline T min(T x, T y) {return x <= y ? x : y;}
constexpr int N = 3E4 + 10;

int n, a[N];
// int pre[N], suf[N];

void solve1() {
  scanf("%d", &n); //pre[0] = suf[n + 1] = 1E9;
  for (int i = 1; i <= n; i ++ ) {
    scanf("%d", a + i);
  }
  int mi = 1E9;
  for (int i = 1; i < n; i ++ ) {
    if (a[i] > a[i + 1] && mi < a[i] - a[i + 1]) {
      return puts("NO"), void();
    }
    chkmin(mi, a[i]);
    mi -= max(0, a[i] - a[i + 1]);
  }
  std::reverse(a + 1, a + 1 + n);
  mi = 1E9;
  for (int i = 1; i < n; i ++ ) {
    if (a[i] > a[i + 1] && mi < a[i] - a[i + 1]) {
      return puts("NO"), void();
    }
    chkmin(mi, a[i]);
    mi -= max(0, a[i] - a[i + 1]);
  }
  puts("YES");
  
}

int inc[N];
int dec[N];

void solve2() {
  scanf("%d", &n); //pre[0] = suf[n + 1] = 1E9;
  for (int i = 1; i <= n; i ++ ) {
    scanf("%d", a + i);
  }
  inc[1] = 0, dec[1] = a[1];
  for (int i = 2; i <= n; i ++ ) {
    dec[i] = min(dec[i - 1], a[i] - inc[i - 1]);
    inc[i] = a[i] - dec[i];
    if (inc[i] < inc[i - 1] || dec[i] > dec[i - 1] || inc[i] < 0 || dec[i] < 0) {
      return puts("NO"), void();
    }
  }
  // for (int i = 1; i <= n; i ++ ) {
  //   printf("%d%c", inc[i], " \n"[i == n]);
  // }
  // for (int i = 1; i <= n; i ++ ) {
  //   printf("%d%c", dec[i], " \n"[i == n]);
  // }
  
  puts("YES");
  /*
  如果执行将 [1, k] 的数字减去 1 这个操作，那么 a_i 执行的此时一定大于等于 a_{i+1}
  
  因此原题可以转化为 构造一个单调不减的数组inc 和 一个单调不增的数组dec

  使得 a[i] = inc[i] + dec[i]

  贪心的构造，inc[1] = 0, dec[1] = a[1]
  考虑inc[2] 和 dec[2]
  dec[2] <= dec[1]
  dec[2] + inc[2] = a[2] --> dec[2] <= a[2]
  inc[2] >= inc[1]       --> dec[2] <= a[2] - inc[1]

  贪心的让dec[2] 尽可能的大，因此取 dec[2] = min(dec[1], a[2] - inc[1])

  判断此时是否有解即可
  */

 

}

int main() {
  int T; scanf("%d", &T);
  while (T -- ) solve2();
  return 0;
}