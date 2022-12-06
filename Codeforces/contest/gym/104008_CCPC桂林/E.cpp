#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define ay3 array<int, 3>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

struct point {
  ll x, y;
  bool operator != (const point &T) const {
    return x != T.x || y != T.y;
  }
};

vector<point> get(point x) {
  vector<point> ans(4, x);
  ans[0].x ++; ans[0].y ++;
  ans[1].x ++; ans[1].y --;
  ans[2].x --; ans[2].y ++;
  ans[3].x --; ans[3].y --;
  return ans;
}


vector<point> get(point a, point b) {
  vector<point> ans(4);
  ans[0].x = (a.x + b.x) / 2; ans[0].y = (a.y + b.y) / 2;
  ans[1].x = (a.x + b.x) / 2; ans[1].y = (a.y + b.y + 1) / 2;
  ans[2].x = (a.x + b.x + 1) / 2; ans[2].y = (a.y + b.y) / 2;
  ans[3].x = (a.x + b.x + 1) / 2; ans[3].y = (a.y + b.y + 1) / 2;
  return ans;
}
__int128 get(point a, point b, point c) {
  __int128 l1 = b.x - a.x;
  __int128 r1 = b.y - a.y;
  __int128 l2 = c.x - a.x;
  __int128 r2 = c.y - a.y;
  __int128 p = l1 * r2 - l2 * r1;
  if (p < 0) p = -p;
  if (!p) p = 1E20;
  return p;
}


void solve() {
  point a, b, c; 
  cin >> a.x >> a.y >> b.x >> b.y;
  ll w = abs(a.x - b.x), h = abs(a.y - b.y);
  ll g = gcd(w, h);
  w /= g, h /= g;
  c = a;

  if (b.x > a.x) c.x += w;
  else c.x -= w;
  if (b.y > a.y) c.y += h;
  else c.y -= h;

  auto s1 = get(a);
  auto s2 = get(b);
  auto s3 = get(a, c);
  point ans = s1[0];
  Rep(i, 0, 4) {
    if (s1[i] != a && s1[i] != b && get(a, b, s1[i]) < get(a, b, ans)) {
      ans = s1[i];
    }
    if (s2[i] != a && s2[i] != b && get(a, b, s2[i]) < get(a, b, ans)) {
      ans = s2[i];
    }
    if (s3[i] != a && s3[i] != b && get(a, b, s3[i]) < get(a, b, ans)) {
      ans = s3[i];
    }
  }

  cout << ans.x << " " << ans.y << "\n";

}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; cin >> T;
  while (T --) solve();
  return 0;
}