#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 3, 5, 5, 5, 5, 5, 5, 9, 12};

void solve1() {
  int l = 0, r = 9;
  while (l < r) {
    int mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid + 1;
  }
  return l;
}



void solve2() {
  int l = 0, r = 9;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  return l;
}

void double_search1(double l, double r) {
  while(r - l >= eps) {
    double mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid;
    // 具体更新左边界还是右边界，具体情况 具体分析
    // 如果要求的是最大值，一般都是 if(check(mid)) l = mid;
    // 如果要求的是最大值，一般都是 if(check(mid)) r = mid;
  }
  return l;
}

void double_search2(double l, double r) {
  for(int i = 0; i < 100; i ++ ) { //迭代次数
    double mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid;
    // 具体更新左边界还是右边界，具体情况 具体分析
    // 如果要求的是最大值，一般都是 if(check(mid)) l = mid;
    // 如果要求的是最大值，一般都是 if(check(mid)) r = mid;
  }
  return l;
}

int main() {
  solve1();
  solve2();
  return 0;
}