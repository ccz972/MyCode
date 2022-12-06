/***************************************************

@File    : E.cpp
@Time    : 2022/07/17 15:39:40
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
constexpr double EPS = 1E-9;
constexpr double PI = 3.14159265358979232384246;
struct TPoint {
  double x, y;
  TPoint(){}
  TPoint(const double &_x, const double &_y):x(_x), y(_y) {}
};
double dot(TPoint & a, TPoint & b, TPoint & c)
{ return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y); }
TPoint operator + (TPoint a, TPoint b) {
  TPoint ans = a;
  ans.x += b.x;
  ans.y += b.y;
  return ans;
}
TPoint operator - (TPoint a, TPoint b) {
  TPoint ans = a;
  ans.x -= b.x;
  ans.y -= b.y;
  return ans;
}
double len(const TPoint & a)
{ return sqrt((double)(a.x*a.x+a.y*a.y)); }

double dis(const TPoint & a, const TPoint & b)
{ return len(b-a); }


void swap(TPoint &x, TPoint &y) {
  TPoint res = x;
  x = y;
  y = res;
}

double cross(const TPoint & a, const TPoint & b) { 
  return (a.x * b.y - a.y * b.x); 
}
int sign(double d) {
  return d < -EPS ? -1 : (d > EPS ? 1 : 0);
}
double dist_sqr(const TPoint &a, const TPoint &b) {
  return (a.x - b.x)*(a.x - b.x) +(a.y - b.y)*(a.y-b.y);
}
double cross(const TPoint & a, const TPoint & b, const TPoint & c)
{ return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

int find_cross_point(TPoint a, TPoint b, double r, TPoint &p1, TPoint &p2) {
  double len = dis(a, b);
  double d = fabs(cross(a, b)) / len;
  if (sign(d - r) >= 0) {
    return 0;
  }
  TPoint vec;
  if (cross(a, b, TPoint(0, 0)) < 0) {
    vec = b - a;
  } else {
    vec = a - b;
  }
  vec = TPoint(-vec.y, vec.x);
  vec.x *= d / len;
  vec.y *= d / len;
  TPoint add = (b - a);
  double tmp = sqrt(r*r-d*d) / len;
  add.x *= tmp;
  add.y *= tmp;
  TPoint tmp1 = vec + add;
  TPoint tmp2 = vec - add;
  if (dist_sqr(a, tmp1) > dist_sqr(a, tmp2)) {
    swap(tmp1, tmp2);
  }
  bool flag1 = (sign(dot(tmp1, a, b)) < 0);

  bool flag2 = (sign(dot(tmp2, a, b)) < 0);
  if (flag1 && flag2) {
    p1 = tmp1, p2 = tmp2;
    return 2;
  }
  if (flag1) {
    p1 = tmp1;
    return 1;
  }
  if (flag2) {
    p1 = tmp2;
    return 1;
  }
  return 0;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  TPoint a, b;
  double r1, r2;
  cin >> a.x >> a.y >> r1;
  cin >> b.x >> b.y >> r2;

  ll limit = 3141592653589ll;

  ll res = rng() % limit + 1;

  for(int i = 0; i <= 10000; i ++ ) {
    ll res = rng() % limit + 1;
    double alpha = (double)res / 1000000000000ll;
    TPoint now(r1 * cos(alpha) + a.x - b.x, r1 * sin(alpha) + a.y - b.y);
    // if(i <= 10)
    // debug(now.x, now.y);
    TPoint p1, p2;
    int cnt = find_cross_point(TPoint(-b.x, -b.y), now, r2, p1, p2);
    if(cnt > 1) {
      cout << "No\n";
      return 0;
    }
    //向量
  }

  for(int i = 0; i <= 10000; i ++ ) {
    ll res = rng() % limit + 1;
    double alpha = (double)res / 1000000000000ll;
    cout << alpha;
    cout << "FUCK\n";
    return 0;
    TPoint now(r2 * cos(alpha) + b.x - a.x, r2 * sin(alpha) + b.y - a.y);
    TPoint p1, p2;
    int cnt = find_cross_point(TPoint(-a.x, -a.y), now, r1, p1, p2);
    if(cnt > 1) {
      cout << "No\n";
      return 0;
    }
    //向量
  }

  cout << "Yes\n";


  return 0;
}