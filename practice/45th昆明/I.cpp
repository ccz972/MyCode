#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;
#define double long double
constexpr double EPS = 1E-9;
const double PI = acos(-1.000);

int sign(double d) {
  if (fabs(d) < EPS) return 0;
  return (d > 0) ? 1 : -1;
}

struct TPoint {
  double x, y;
  TPoint() {}
  TPoint(const double &_x, const double &_y) : x(_x), y(_y) {}
};

struct TLine {
  double a, b, c; 
};

struct TSegment {
  TPoint s, e;
};

TLine get_line(TPoint &p1, TPoint &p2) {
  TLine tl; 
  tl.a = (double)p2.y - p1.y;
  tl.b = (double)p1.x - p2.x;
  tl.c = (double)p1.y * p2.x - (double)p1.x * p2.y;
  if (tl.a < 0) tl.a *= -1.0, tl.b *= -1.0, tl.c *= -1.0;
  return tl;
}

TPoint line_intersect (TLine l1, TLine l2) {
  TPoint tmp;
  if (sign(l1.b) == 0) {
    tmp.x = -l1.c / (double)l1.a;
    tmp.y = (-l2.c - l2.a * tmp.x) / (double)l2.b;
  } else {
    tmp.x = (double)(l1.c * l2.b - l1.b * l2.c) /
            (double)(l1.b * l2.a - l2.b * l1.a);
    tmp.y = (double)(-l1.c - l1.a * tmp.x) / (double)l1.b;
  }
  return tmp;
}
 
bool in_segment(TSegment seg, TPoint p) {
  double left = seg.s.x, right = seg.e.x;
  if (left > right) swap(left, right);
  if (p.x >= left && p.x <= right) return true;
  return false;
}

void solve() {
  int n, q; cin >> n >> q;
  TPoint s, t; cin >> s.x >> s.y >> t.x >> t.y;

  vector<TPoint> a(n + 1);

  rep(i, 1, n) {
    cin >> a[i].x >> a[i].y;
  }

  TLine Seg = get_line(s, t);
  TSegment seg; seg.s = s, seg.e = t;

  vector<vector<TPoint > > have(n + 1);

  rep(i, 1, n) {
    TPoint p1 = a[i];
    rep(j, 1, n) if (i != j) {
      TPoint p2 = a[j];
      TLine p12 = get_line(p1, p2);
      if (sign(p12.a * Seg.b - p12.b * Seg.a) == 0) {
        continue;
      }
      TPoint Inter = line_intersect(p12, Seg);
      if (in_segment(seg, Inter)) {
        have[i].push_back(Inter);
      }
    }

    if (!have[i].empty()) {
      sort(have[i].begin(), have[i].end(), [&] (TPoint P1, TPoint P2) {
        return abs(P1.x - s.x) < abs(P2.x - s.x);
      });
    }
  }

  while (q -- ) {
    int h, k; cin >> h >> k;
    if (SZ(have[h]) < k) {
      cout << "-1\n"; 
    } else {
      cout << have[h][k - 1].x << " " << have[h][k - 1].y << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  cout << fixed << setprecision(10);
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}