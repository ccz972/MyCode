#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Date {
  int y, m, d;
  bool operator < (const Date &T) const {
    if(y != T.y) return y < T.y;
    if(m != T.m) return m < T.m;
    return d < T.d;
  }
};
vector<int> date{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date operator + (Date x, int Y) {
  auto [y, m, d] = x;
  d += 1;
  if(d == date[m - 1] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) + 1) {
    m += 1;
    d = 1;
  }
  if(m == 13) {
    m = 1;
    y ++;
  }
  return Date{y, m, d};
};

int calc(int x, int ret = 0) {
  while(x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

void solve() {
  Date st = {2001, 1, 1}, ed = {2021, 12, 31};
  set<int> V;
  for(int i = 0; i <= 10000; i ++ ) {
    V.insert(i * i);
  }
  int ans = 0;
  while(st < ed) {
    int s = calc(st.y) + calc(st.m) + calc(st.d);
    if(V.count(s)) ans ++;
    st = st + 1;
  }
  
  cout << ans ;



}

int main() {
  solve();
  return 0;
}