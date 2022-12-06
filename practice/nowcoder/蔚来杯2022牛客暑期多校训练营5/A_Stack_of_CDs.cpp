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
#define double long double
constexpr int N = 1010;
constexpr double pi = 3.14159265358979323846;
int n, top; 
double x[N], y[N], r[N];

struct segment {
  double l, r;
  segment() {}
  segment(double x, double y) : l(x), r(y) {}
  segment(int x, double y): l(x), r(y) {}
  bool operator < (const segment T) const {
    return l < T.l;
  }
} q[N];

double echo(int a, int b) {
  double xx = x[a] - x[b], yy = y[a] - y[b];
  return sqrt(xx * xx + yy * yy);
}

bool in(int a, int b) {
  if(r[a] >= r[b] + echo(a, b)) return true;
  return false;
}


void push(int a, int b) {
  double d = echo(a,b);
  double t = (r[a] * r[a] - r[b] * r[b] + d * d) / (2 * d * r[a]);//余弦定理求角(位置见上图)
  double st = atan2((x[a] - x[b]), (y[a]-y[b]));
  double l = acos(t);
  q[++top]=segment(st-l,st+l);//以弧的两个端点当做线段的两个端点
}


double get(int x) {
  for(int i = x + 1; i <= n; i ++ ) {
    if(in(i, x)) return 0;
  } 
  top = 0;
  for(int i = x + 1; i <= n; i ++ ) {
    if(!in(x, i) && r[x] + r[i] >= echo(x, i)) push(x, i);
  }
  double tmp = 0, now = 0;
  for(int i = 1; i <= top; i ++ ) {
    if(q[i].l < 0) q[i].l += 2 * pi;
    if(q[i].r < 0) q[i].r += 2 * pi;
    if(q[i].l > q[i].r) {
      q[++ top] = segment(0, q[i].r);
      q[i].r = 2 * pi;
    }
  }
  sort(q + 1, q + top + 1);
  for(int i = 1; i <= top; i ++ ) {
    if(q[i].l > now) {
      tmp += q[i].l - now;
      now = q[i].r;
    } else {
      chkmax(now, q[i].r);
    }
  }
  tmp += 2 * pi - now;
  return r[x] * tmp;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> x[i] >> y[i] >> r[i];
  } 
  double ans = 0; 
  for(int i = 1; i <= n; i ++ ) {
    ans += get(i);
  }
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}